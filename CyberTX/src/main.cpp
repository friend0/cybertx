#include <Arduino.h>
#include <PulsePosition.h>
#include "message.pb.h"
#include "state.h"
#include <nanopbSerial.h>
#include <pb.h>

#define MAX_PPM 1
// StateMachine state;

unsigned long now;
unsigned long last_now = 0;
const int interval_ms = 2000;
volatile int ledState = LOW;
PulsePositionOutput output1;
PulsePositionOutput outputs[MAX_PPM];

const int ppm_output_pins[8] = {5, 6, 9, 10, 20, 21, 22, 23};
size_t message_length;

bool status;

cybertx_messages_PPMUpdateAll ppm_message = cybertx_messages_PPMUpdateAll_init_zero;
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
    for (int j = 0; j < 16; j++) {
      outputs[i].write(j, 1500);
    }
  }
}

void loop()
{

  while (!Serial.dtr())
  {
    // TODO: put this into an ISR on Timer0, then jsut have this be an if/continue
    now = millis();
    if (now - last_now >= interval_ms)
    {
      last_now = now;
      ledState ^= 1;
      digitalWrite(LED_BUILTIN, ledState);
    }
    continue;
  }

  /* Now we are ready to decode the message. */
  if (Serial.available() > 0)
  {
    status = pb_decode(&pb_in, cybertx_messages_PPMUpdateAll_fields, &ppm_message);
    if (status)
    {
      // TODO: figure out why readBytes on the stream doesn't clear buffer
      // Decoding on the stream doesn't clear the buffer, so clear the same number of bytes we read from the buffer now.
      pb_in = pb_istream_from_serial(Serial, 36);
      for (int i=0; i < (int) sizeof(ppm_message); i++){
        Serial.read();
      }
      pb_in.state = &Serial;
      
      // Process PPM update
      for (int i=0; i < 16; i++) {
        outputs[0].write(i + 1, (float) ppm_message.channel_values[i]);
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
  }
}