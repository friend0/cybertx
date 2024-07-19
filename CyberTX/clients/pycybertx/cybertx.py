"""
Send a single PPM update packet.

Expects that a CyberTX teensy is available on COM3.

"""

import logging
import sys
from typing import List
import serial

from ppm_pb2 import UpdateLine, UpdateAll


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