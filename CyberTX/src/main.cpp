#include <Arduino.h>
#include <Tinyframe.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("Teensy 3.2: CyberTX PPM Proxy");
    delay(1000);
}