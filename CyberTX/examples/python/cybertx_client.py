"""
Send a single PPM update packet.

Expects that a CyberTX teensy is available on COM3.

"""

import serial
import time

from ppm_pb2 import UpdateLine, UpdateAll

# TODO: cross-platform implementation
arduino = serial.Serial('COM3', baudrate=115200, timeout=0)

newMessage = UpdateLine()()

newMessage.channel = 1
newMessage.channel_value = 1500

ppm = UpdateAll()(line=1,
                  channel_values=[
                      1700, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                      2000, 2000, 2000, 2000, 2000, 2000, 2000
                  ])
ser_str = ppm.SerializeToString()
print(ser_str, ppm.ByteSize(), ser_str,
      UpdateAll()().FromString(ser_str).channel_values)
arduino.write(ser_str)
