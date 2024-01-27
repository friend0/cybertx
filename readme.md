Cyber TX
==========

CyberTX turns a Teensy into a Serial to PPM proxy, enabling RC control over a serial link.
CyberTX is inspired by the PCTx device which was used as a serial to PPM device in early experiments.

The role of this device remains largely the same: read serial data from a controller running on a local machine,
then output the commanded PPM signal for an RC to interpret through its trainer port.

The primary benefit of a control architecture where the RC acts as the leader to a follower signal coming from a control PC is safety.
In novel control applications, it is critical for a human operator to be able to terminate automatic control, and to be able to take over piloting
of a vehicle. Human intervention can mitigate the impacts of loss of control, both on humans and the equipment. In architectures where the control PC is 
in the middle of this loop, there is a single point of failure at the control node. If human intervention is processed in this control loop, then a safe takeover is dependent on the system under test being absolutely reliable. Moving this failure point to the RC does not eliminate the single point of failure, but it does transfer much of the burden to hardware and software stacks that are under continuous development in popular open source, or industry backed systems.

The secondary benefits are reliability, and scalability, since this solution uses RC technology that has been widely vetted in the hobby community, and in industry.

