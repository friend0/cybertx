import serial
import time
from message_pb2 import PPMUpdate, PPMUpdateAll

arduino = serial.Serial('COM3', baudrate=9600, timeout=1)

newMessage = PPMUpdate()

newMessage.channel = 1
newMessage.channel_value = 1500
print()

# arduino.write(newMessage.SerializeToString())
ser_str = PPMUpdateAll(
    channel_values=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
                    ]).SerializeToString()
arduino.write(ser_str)
time.sleep(.05)
res = arduino.read_all()
ppm = PPMUpdateAll()
print(ppm.ParseFromString(res))
print(ppm.channel_values)
