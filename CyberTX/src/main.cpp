#include <Arduino.h>
#include <PulsePosition.h>

#include "state.h"
#include <pb.h>

#define MAX_PPM 2

StateMachine state;

unsigned long last_now = 0;
const int interval_ms = 2000;
int ledState = LOW;
PulsePositionOutput *outputs[MAX_PPM];

void setup()
{
  // Status LED
  pinMode(LED_BUILTIN, OUTPUT);

  // PPM Setup
  for (int i = 0; i < MAX_PPM; i++)
  {
    PulsePositionOutput newOut;
    outputs[i] = &newOut;
  }

  // Serial
  Serial.begin(9600);
  Serial.println("Teensy 3.2: CyberTX PPM Proxy");
}

void loop()
{
  unsigned long now = millis();

  while (!Serial.dtr())
  {
    if (now - last_now >= interval_ms)
    {
      last_now = now;
      ledState ^= 1;
      digitalWrite(LED_BUILTIN, ledState);
    }
  }

  // Serial Connected
  if (Serial.available()){

  }
}