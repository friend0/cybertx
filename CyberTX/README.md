# CyberTX

CyberTX is a Serial to PPM converter. 
PPM signals are a classic method for sending servo position data for many channels to the trainer port of an RC.
These commands are then transmitted to the vehicle over the radio link used by the RC.
Trainer ports make it possible for new pilots to learn to fly while an experienced pilot can take command at any time.

The safety case for this architecture is obvious. In automatic control scenarios, we want to allow the same functionality so that a controller implementation can command a vehicle only while the pilot is not sending override commands. This paradigm enables much safer testing, and has been widely adpoted by numerous companies working to operationalize their autonomous vehicle fleets. 

## Hardware 
I've chose to implement CyberTX on an ARM-M4 Teensy board, but this should port to most embedded platforms with a Serial and PPM implementation. 
The Teensy has the capability to support ~8 PPM channels without the use of multiplexing.
The main control PC is expected to connect vis USB Serial, while a USB to UART probe can be connected to Serial 1 for debugging.

## Software 

### Server
The CyberTX server implementation in `src` runs onboard the Teensy 3.2.
This initial runs a Serial program that processes control commands on a stream. 

The main control flow is as follows:

- While there is no serial connection, blink an LED on 2 second intervals
- When a serial connection is present, check for available data. 
- If data is available, see if it can be parsed into a PPMUpdateMessage. If it can, use that message to issue an update to the PPM outputs for the given channel. 

The data on this stream is assumed to be composed of messages defined in the `proto` directory.
Protobufs are used here for ease of serialization/deserialization, and to maximize interoperability with the largest number of controller implementations possible. 
If you need to add a client implementation, simply recompile the protobufs for your language of choice, and implement the functionality shown in the other client implementations.
If you need to run it without protobufs, i.e. with plain serial, uncomment the matlab mode defintion in `src/main.cpp`.
After the messages are interpreted, they are used to update the PPM outputs.

## Compiling CyberTX Protobufs
This repository is configured to use Platformio. If you have VSCode, and have installed PlatformIO, it should handle the compile step for 
the necessary protobufs.

Manual compilation can be done by using nanopb and it's provided generators.
In the command below, we use the nanopb builtin `nanopb_generator` to build nanopb protobuffs to be used on the Teensy board.

```
python nanopb/generator/nanopb_generator.py
```

To rebuild protobufs for the Go and Python clients, run the following (paths here assume the $PWD is cybertx/cybertx)

```
protoc --plugin=protoc-gen-nanopb=proto\nanopb\generator\protoc-gen-nanopb --proto_path=proto\nanopb\generator\proto\ --proto_path=proto --python_out=examples\python --pyi_out=examples\python  --go_out=. --go_opt=module="github.com/friend0/cybertx" ppm.proto
```

### Clients

A number of clients are provided for reference in the `clients` directory. All have been tested to work manually, but
None should be used in production as of the current release.
