#include <Arduino.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include <PulsePosition.h>
#include "message.pb.h"
#include "state.h"

#define MAX_PPM 2
#define BUFFER_LEN 1025
// StateMachine state;

int buffer_idx = 0;
unsigned long last_now = 0;
const int interval_ms = 2000;
int ledState = LOW;
PulsePositionOutput *outputs[MAX_PPM];

uint8_t buffer[BUFFER_LEN];
size_t message_length;

cybertx_messages_PPMUpdateAll ppm_message = cybertx_messages_PPMUpdate_init_zero;
bool status;

// class Print;
// class Stream;

// static bool pb_stream_read(pb_istream_t *stream, pb_byte_t *buf, size_t count)
// {
//   Stream *s = reinterpret_cast<Stream *>(stream->state);
//   size_t written = s->readBytes(buf, count);
//   return written == count;
// };

// static bool pb_print_write(pb_ostream_t *stream, const pb_byte_t *buf, size_t count) {
//     Print* p = reinterpret_cast<Print*>(stream->state);
//     size_t written = p->write(buf, count);
//     return written == count;
// };

// pb_istream_s as_pb_istream(Stream &s)
// {
// #ifndef PB_NO_ERRMSG
//   return {pb_stream_read, &s, BUFFER_LEN, 0};
// #else
//   return {pb_stream_read, &s, SIZE_MAX};
// #endif
// };

// pb_ostream_s as_pb_ostream(Print& p) {
//     return {pb_print_write, &p, SIZE_MAX, 0};
// };

// pb_ostream_s pb_out = as_pb_ostream(Serial);
// pb_istream_s pb_in = as_pb_istream(Serial);

pb_istream_t stream = pb_istream_from_buffer(buffer, 20);
pb_ostream_t ostream = pb_ostream_from_buffer(buffer, sizeof(buffer));
void setup()
{
  // Status LED
  pinMode(LED_BUILTIN, OUTPUT);

  // clear buffer
  for (int i = 0; i < BUFFER_LEN; i++)
  {
    buffer[i] = 0;
  }

  // PPM Setup
  for (int i = 0; i < MAX_PPM; i++)
  {
    PulsePositionOutput newOut;
    outputs[i] = &newOut;
  }

  // Serial
  // Serial.begin(38400);
  // Serial.println("Teensy 3.2: CyberTX PPM Proxy");
}

void loop()
{

  unsigned long now = millis();

  // while (!Serial.dtr())
  // {
  //   if (now - last_now >= interval_ms)
  //   {
  //     last_now = now;
  //     ledState ^= 1;
  //     digitalWrite(LED_BUILTIN, ledState);
  //   }
  //   continue;
  // }

  // Serial Connected
  if (Serial.available())
  {
    char c = Serial.read();
    buffer[buffer_idx] = c;
    // Serial.write(buffer_idx);
    buffer_idx++;
  }

  /* Now we are ready to decode the message. */

  if (buffer_idx >= 18)
  {
    status = pb_decode(&stream, cybertx_messages_PPMUpdateAll_fields, &ppm_message);
    if (status)
    {
      Serial.write(ppm_message.line);
      for (int i = 0; i < 16; i++)
      {
        Serial.write(ppm_message.channel_values[i]);
      }
    }
    buffer_idx = 0;
  }

  /* Check for errors... */
  // if (Serial.available())
  // {
  //   while (Serial.available()) {

  //   }
  //   // PB_GET_ERROR()
  //   status = pb_decode(&pb_in, cybertx_messages_PPMUpdateAll_fields, &ppm_message);
  //   if (status)
  //   {
  //     pb_encode(&pb_out, cybertx_messages_PPMUpdateAll_fields, &ppm_message);
  //   }
  // }

  // if (Serial.availableForWrite() && status) {
  //   Serial.write(ppm_message.line);
  //   status = false;
  // }
}