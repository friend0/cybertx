#include <Arduino.h>
#include "PulsePosition.h"
#include "ppm.pb.h"
#include <nanopbSerial.h>
#include <pb.h>

// If we need to provide direct from MATLAB communication over serial without protobufs, uncomment the following line
// rebuild and upload the code to the Teensy.
#define MATLAB_MODE

// Configuration
// provide the number of PPMs to be used
// as of 7/18/24 we are only using 1 PPM
#define NUM_LINES 1
// todo: PPM library does not make this configurable out of the box
// you will need to update the #define in PulsePosition.h until this is implemented as a new feature
#define NUM_CHANNELS 16 // set the number of channels per line
const int ppm_output_pins[8] = {5, 6, 9, 10, 20, 21, 22, 23};
u_int8_t dynamic_channels;

// FSM States
enum states
{
  start_frame,
  startFrame2,
  startFrame3,
  receiveMSB,
  receiveLSB,
  receiveNext,
  endFrame1,
  error,
};

uint8_t currentState, nextState, MSB, LSB, route, count, curChan;
bool contact, newLineFlag;

unsigned long now, previous;
const int interval_ms = 2000;
volatile int ledState = LOW;

// output channels are line outs to an RC
// ppm channels are the values for a given line
PulsePositionOutput output_channels[NUM_LINES];
uint16_t ppm[NUM_CHANNELS];

cybertx_UpdateAll ppm_message = cybertx_UpdateAll_init_zero;
u_int32_t channel_values[NUM_CHANNELS];

void setup()
{

  // Status LED
  pinMode(LED_BUILTIN, OUTPUT);

  // PPM Setup
  Serial1.begin(38400);
  for (int i = 0; i < NUM_LINES; i++)
  {
    #ifdef MATLAB_MODE
      Serial1.printf("Operating in MATLAB Serial mode\r\n");
    #else
      Serial1.printf("Operating in Protobuf mode\r\n");
    #endif
    Serial1.printf("Initializing PPM %d on pin %d\r\n", i, ppm_output_pins[i]);
    output_channels[i] = PulsePositionOutput(FALLING);
    output_channels[i].begin(ppm_output_pins[i]);
    for (int j = 0; j < NUM_CHANNELS; j++)
    {
      output_channels[i].write(j, 1500);
      ppm[i] = 0;
    }
  }

  currentState = start_frame;
  nextState = start_frame;

  ppm_message.channel_values.funcs.decode = decode_channel_values;
  ppm_message.channel_values.arg = &channel_values;
  Serial.flush();
}

void runFSM();

void loop()
{

  while (!Serial.dtr() && !Serial.available())
  {
    // TODO: put this into an ISR on Timer0, then this will be an if/continue
    now = millis();
    if (now - previous >= interval_ms)
    {
      previous = now;
      ledState ^= 1;
      digitalWrite(LED_BUILTIN, ledState);
      currentState = start_frame;
      curChan = 0;
      MSB = 0;
      LSB = 0;
    }
    continue;
  }

#ifndef MATLAB_MODE
  bool proto_decode_status;
  if (Serial.available() > 0)
  {
    pb_istream_s pb_in;
    pb_in = pb_istream_from_serial(Serial, 36);
    proto_decode_status = pb_decode(&pb_in, cybertx_UpdateAll_fields, &ppm_message);
    if (proto_decode_status)
    {
      // Process PPM update
      for (std::size_t i = 0; i < NUM_CHANNELS; i++)
      {
        output_channels[0].write(i + 1, channel_values[i]);
      }

      if (Serial1.availableForWrite())
      {
        Serial1.printf("Received command for line %d %d\r\n", ppm_message.line, sizeof(ppm_message));
        for (std::size_t i = 0; i < 16; i++)
        {
          Serial1.printf("- channel_%d value: %d\r\n", i, channel_values[i]);
        }
      }
    }
    else
    {
      Serial1.printf("Decode failed: %d\n", proto_decode_status);
    }
  }
#endif

#ifdef MATLAB_MODE

  runFSM();

#endif
}

void runFSM()
{
  nextState = currentState;
  if (Serial.available())
  {
    if (currentState == error)
    {
      nextState = start_frame;
      MSB = 0;
      LSB = 0;
      curChan = 0;
      Serial.read();
    }
    else if (currentState == start_frame)
    {
      if (Serial.read() == 0x01)
      {
        nextState = startFrame2;
      }
      else
      {
        nextState = error;
      }
    }
    else if (currentState == startFrame2)
    {
      if (Serial.read() == 0x02)
      {
        nextState = startFrame3;
      }
      else
      {
        nextState = error;
      }
    }
    else if (currentState == startFrame3)
    {
      dynamic_channels = Serial.read();
      Serial1.printf("Dynamic Channels: %d\r\n", dynamic_channels);
      nextState = receiveMSB;
    }
    else if (currentState == receiveMSB)
    {
      MSB = Serial.read();
      nextState = receiveLSB;
    }
    else if (currentState == receiveLSB)
    {
      LSB = Serial.read();
      nextState = receiveNext;
    }
    else if (currentState == receiveNext)
    {
      ppm[curChan] = ((uint16_t)(MSB & 0x0F)) << 8 | (uint16_t)LSB;
      Serial1.printf("Chan %d - %d\r\n", curChan, ppm[curChan]);
      curChan++;
      MSB = 0x00;
      LSB = 0x00;
      if (curChan >= dynamic_channels)
      {
        nextState = endFrame1;
        curChan = 0;
      }
      else
      {
        Serial1.printf("peek: %02X\r\n", Serial.peek());
        if (Serial.peek() != 0xDD)
        {
          nextState = error;
        } // error condition
        else
        {
          nextState = receiveMSB;
        }
      }
      Serial.read();
    }
    else if (currentState == endFrame1)
    {
      if (Serial.read() == 0xD4)
      {
        nextState = start_frame;
        for (int i = 0; i < dynamic_channels; i++)
        {
          float ms = ppm[i];
          output_channels[0].write(i + 1, ms);
        }
      }
    else
      {
        // todo: error condition
        nextState = error;
      }
    }
    if (currentState != nextState)
    {
      Serial1.printf("StateTransition: %d -> %d\r\n", currentState, nextState);
    }
    currentState = nextState;
  }
}
