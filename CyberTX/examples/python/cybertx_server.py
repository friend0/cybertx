import serial
import time
from message_pb2 import PPMUpdate, PPMUpdateAll

arduino = serial.Serial('COM3', baudrate=115200, timeout=0)

newMessage = PPMUpdate()

newMessage.channel = 1
newMessage.channel_value = 1500

# arduino.write(newMessage.SerializeToString())
ppm = PPMUpdateAll(line=1,
                   channel_values=[
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                       1500,
                   ])
ser_str = ppm.SerializeToString()
# print(ser_str, ppm.ByteSize(), ser_str,
#       PPMUpdateAll().FromString(ser_str).channel_values)
arduino.write(ser_str)

time.sleep(.5)

# num = arduino.read()
# cv = arduino.read()
# while(arduino.)
# res = arduino.read(18)
# print(f"num {int.from_bytes(num)}")
# print(f"cv {int.from_bytes(cv)}")
# print(res)
# ppm = PPMUpdateAll()
# print(ppm.ParseFromString(res))
# print(ppm.channel_values)
