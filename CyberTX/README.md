# CyberTX

CyberTX is a Serial to PPM converter. 
PPM signals are a classic method for sending many channels of servo data to RC trainer ports, which are then transmitted as control signals over any number of radio implementations.
Trainer ports make it possible for new pilots to learn to fly while an experienced pilot can take command at any time.

The safety case for this architecture is obvious. In automatic control scenarios, we want to allow the same functionality so that a controller implementation can command a vehicle only while the pilot is not sending override commands. This paradigm enables much safer testing, and has been widely adpoted by numerous companies working to operationalize their autonomous vehicle fleets. 

## Hardware 
I've chose to implement CyberTX on an ARM-M4 Teensy board, but this should port to most embedded platforms with a Serial and PPM implementation. 
The Teensy has the capability to support ~8 PPM channels without the use of multiplexing.
The main control PC is expected to connect vis USB Serial, while a USB to UART probe can be connected to Serial 1 for debugging.

## Software 
I'm using some stock Teensy stuff to interface with USB and hardware serial ports.
I'm using Paul's PPM implementation to drive the outputs.
I'm using Protobufs for serialization/deserialization, and to maximize interoperability with the largest number of controller implementations possible. 

The main control flow is as follows:

- While there is no serial connection, blink an LED on 2 second intervals
- When a serial connection is present, check for available data. 
- If data is available, see if it can be parsed into a PPMUpdateMessage. If it can, use that message to issue an update to the PPM outputs for the given channel. 