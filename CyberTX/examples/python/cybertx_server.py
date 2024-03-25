import serial
import time
from message_pb2 import PPMUpdate, PPMUpdateAll

arduino = serial.Serial('COM3', baudrate=115200, timeout=0)

newMessage = PPMUpdate()

newMessage.channel = 1
newMessage.channel_value = 1500
print()

# arduino.write(newMessage.SerializeToString())
ppm = PPMUpdateAll(
    line=2,
    channel_values=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16])
ser_str = ppm.SerializeToString()
print(ser_str, ppm.ByteSize(), ser_str,
      PPMUpdateAll().FromString(ser_str).channel_values)
arduino.write(ser_str)

time.sleep(.5)

res = arduino.read(20)
print(res)
# ppm = PPMUpdateAll()
# print(ppm.ParseFromString(res))
# print(ppm.channel_values)
