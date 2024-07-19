"""
Send a single PPM update packet.

Expects that a CyberTX teensy is available on COM3.

"""

import serial
import time

from ppm_pb2 import UpdateLine, UpdateAll


def test_cybertx(com_port='COM3', baudrate=115200, timeout=0):
    arduino = serial.Serial(com_port, baudrate=baudrate, timeout=timeout)
    ppm = UpdateAll(line=6,
                    channel_values=[
                        1701, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
                        2008, 2009, 2010, 2011, 2012, 2013, 2014
                    ])
    ser_str = ppm.SerializeToString()
    print(ppm.ByteSize())
    print(ser_str, ppm.ByteSize(), ser_str,
          UpdateAll().FromString(ser_str).channel_values)
    arduino.write(ser_str)

if __name__ == "__main__":
    test_cybertx()