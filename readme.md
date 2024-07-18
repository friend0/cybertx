Cyber TX
==========

CyberTX turns a Teensy into a Serial to PPM proxy, enabling RC control over a serial link.
This enables control algorithms to send commands to the trainer input of an RC.
By extension, this enables mid level controllers to pilot any vehicle bound to an RC.

It is an updated implemetation of the PCTx. We aim to offer the same functionality, but with:
- Support for multiple PPM output lines, meaning multiple vehicles can be controlled with one CyberTX.
- Work with Protobufs, making CyberTX easy to use from your language of choice.
- Support control over serial *temporary workaround for easy Matlab support*.

The objective for this device is to translate messages
The role of this device remains largely the same: read serial data from a controller running on a local machine,
then output the commanded PPM signal for an RC to interpret through its trainer port.

The primary benefits of a control architecture where the RC acts as the leader to a follower signal coming from a control PC is safety and interoperability.

A human pilot can always take control, and any RC with a trainer input can be used with CyberTX*.
In novel control applications, it is critical for a human operator to be able to terminate automatic control, and to be able to take over piloting
of a vehicle. Human intervention can mitigate the impacts of loss of control, both on humans and the equipment. In architectures where the control PC is 
in the middle of this loop, there is a single point of failure at the control node. If human intervention is processed in this control loop, then a safe takeover is dependent on the system under test being absolutely reliable. Moving this failure point to the RC does not eliminate the single point of failure, but it does transfer much of the burden to hardware and software stacks that are under continuous development in popular open source, or industry backed systems.


* Potentially with modifications to the PPM waveform output by default.

