#include <Arduino.h>
#include <PulsePosition.h>
#include "ppm.pb.h"
#include "state.h"
#include <nanopbSerial.h>
#include <pb.h>

#define MAX_PPM 1
#define MATLAB_MODE

// Configuration
#define num_channels 16 // set the number of channels per PPM
void printBin(byte aByte);
void ppmUpdate(uint16_t *ppm);

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
  endFrame2,
  error,
};

uint16_t ppm[num_channels], routingInfo;
char charBuffer[12];
uint8_t currentState, nextState, MSB, LSB, route, count, curChan;
bool contact, newLineFlag;

unsigned long now;
unsigned long last_now = 0;
const int interval_ms = 2000;
volatile int ledState = LOW;

PulsePositionOutput output1;
PulsePositionOutput outputs[MAX_PPM];

const int ppm_output_pins[8] = {5, 6, 9, 10, 20, 21, 22, 23};
size_t message_length;

bool proto_decode_status;

cybertx_UpdateAll ppm_message = cybertx_UpdateAll_init_zero;
pb_istream_s pb_in = pb_istream_from_serial(Serial, 36);


void setup()
{

  // Status LED
  pinMode(LED_BUILTIN, OUTPUT);

  // PPM Setup
  Serial1.begin(38400);
  for (int i = 0; i < MAX_PPM; i++)
  {
    Serial1.printf("Initializing PPM %d on pin %d\r\n", i, ppm_output_pins[i]);
    outputs[i].begin(ppm_output_pins[i]);
    for (int j = 0; j < 16; j++)
    {
      outputs[i].write(j, 1500);
      ppm[i] = 0;
    }
  }

  currentState = start_frame;
  nextState = start_frame;

  // Serial.flush();
}

void runFSM();

void loop()
{

  while (!Serial.dtr() && !Serial.available())
  {
    // TODO: put this into an ISR on Timer0, then jsut have this be an if/continue
    now = millis();
    if (now - last_now >= interval_ms)
    {
      last_now = now;
      ledState ^= 1;
      digitalWrite(LED_BUILTIN, ledState);
      currentState = start_frame;
      curChan = 0;
      MSB = 0;
      LSB = 0; 
      Serial.flush();  
    }
    continue;
  }

#ifndef MATLAB_MODE
  /* Now we are ready to decode the message. */
  if (Serial.available() > 0)
  {
    status = pb_decode(&pb_in, cybertx_UpdateAll_fields, &ppm_message);
    Serial1.println(status);
    if (status)
    {
      // TODO: figure out why readBytes on the stream doesn't clear buffer
      // Decoding on the stream doesn't clear the buffer, so clear the same number of bytes we read from the buffer now.
      pb_in = pb_istream_from_serial(Serial, 36);
      for (int i = 0; i < (int)sizeof(ppm_message); i++)
      {
        Serial.read();
      }
      pb_in.state = &Serial;

      // Process PPM update
      for (int i = 0; i < 16; i++)
      {
        outputs[0].write(i + 1, (float)ppm_message.channel_values[i]);
      }

      if (Serial1.availableForWrite())
      {
        // Serial1.printf("PPM Update successful: %d", ppm_update_success);
        Serial1.printf("Received command for line %d %d\r\n", ppm_message.line, sizeof(ppm_message));
        for (int i = 0; i < 16; i++)
        {
          Serial1.printf("- channel_%d value: %d\r\n", i, ppm_message.channel_values[i]);
        }
        Serial1.printf("Serial available: %d\r\n", Serial.available());
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
      if (currentState == error) {
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
        if (Serial.read() == 0x03)
        {
          nextState = receiveMSB;
        }
        else
        {
          nextState = error;
        }
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
        if (curChan >= num_channels)
        {
          nextState = endFrame1;
          curChan = 0;
        }
        else
        {
          if (Serial.peek() != 0x15) {
            nextState = error;
          } else {
            nextState = receiveMSB;
          }
        }
        Serial.read();
      }
      else if (currentState == endFrame1)
      {
        if (Serial.read() == 0x15)
        {
          nextState = endFrame2;
        }
        else
        {
          nextState = error;
        } // error condition
      }

      else if (currentState == endFrame2)
      {
        if (Serial.read() == 0x12)
        {
          nextState = start_frame;
          ppmUpdate(ppm);
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

  void printBin(byte aByte)
  {
    for (int8_t aBit = 7; aBit >= 0; aBit--)
      Serial1.write(bitRead(aByte, aBit) ? '1' : '0');
    Serial1.write('\t');
  }

  void ppmUpdate(uint16_t *ppm) {
      for (int i = 0; i < 16; i++)
      {
        float ms = ppm[i];
        outputs[0].write(i + 1, ms);
      }
  }