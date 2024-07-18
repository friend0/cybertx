"""
Send a single PPM update packet.

Expects that a CyberTX teensy is available on COM3.

"""

import logging
import sys
from typing import List
import serial
import time

from CyberTX.proto.python.ppm_pb2 import UpdateLine, UpdateAll

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



class Client:
    def __init__(self, port=None, baudrate=115200, timeout=10):
        if port is None:
            logging.ERROR("No port specified. Exiting.")
            sys.exit(1)
        self.connection = serial.Serial(port, baudrate=baudrate, timeout=timeout)

    def send(self, message):
        ser_str = message.SerializeToString()
        self.connection.write(ser_str)
    
    def UpdateLine(self, channel, value):
        newMessage = UpdateLine()
        newMessage.channel = channel
        newMessage.channel_value = value
        self.send(newMessage)
    
    def UpdateAll(self, line: int, channel_values: List[int]):
        newMessage = UpdateAll()
        newMessage.line = line
        newMessage.channel_values = channel_values
        self.send(newMessage)