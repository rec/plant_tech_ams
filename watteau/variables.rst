The watering project
------------------------

The watering system is a single infinite loop that repeats forever:

* compute
* delay

Here's our simplest example again!

https://github.com/rec/plant_tech_ams/blob/master/MoistureSensor.ino#L17-L27

The machine we're using has about 40k left over after installing TCP/IP and
such, so we can't waste memory.

Let's start by identifying the important variables. And remember: data, data,
data!  We want to be collecting as much as we can.


Configuration variables
=============================

Here's where we set up the system.

Remember, there's no reason we couldn't have multiple sensors and plants hooked
to this thing!

* analog: analog input pins on the board

* digital: digital input pins on the board

* pump pins: output pins each of which turns on a pump

* delay time: how long to delay in each cycle

* memory settings: for each observed buffer, how many samples to hold?

  * analog samples: 10 bits

  * digital samples: 1 bit

  * pump samples: 32 bits

(There's no reason that we can't change the values above while the program is
running, either. It shouldn't have to recompile each time...)

Observed variables
======================

At each loop point we collect:

* For each analog channel (AC)

  * A 10-bit analog A value between 0 and 1023

  * Packing 10-bit values will be a bit challenging so we'll use
    16 bit values for now

* For each digital channel (DC)

  * A single D bit

* For each pump channel (PC)

  * If the pump state changed from the previous loop, record the loop count

  * We are recording what the program did, not a sensor

  * I thought of using a single bit here, but this changes so rarely that
    only recoding the changes uses less memory

Since we have limited space, all of these need to be packed carefully, and use
a circular buffer.  The size of each buffer is set in Configuration.

Each analog sample is 10 bits - 16 bits, for now.

Each digital sample is 1 bit.

Each pump sample takes 32 bits, but we only usually record one when the state of
the pump changes, if the pump has turned on of off.

The top bit of the pump sample records whether the pump was on or off, and the
remaining 31 bits contain the loop index.  This allows for 2**31, over two
billion loops, or over 6 years at ten loops a second.


Accumulators
=================

An accumulator is a value that is updated at each loop.  The accumulators are
fixed size.

* The loop count

  How many times have we gone around the loop.

  The loop count is our base time clock, starting at zero
  when we turn the whole thing on.

  You can convert the loop count into a pretty good "wall clock" time
  if you know the delay time and can guess at how long the code
  takes to run.

* Total number of millseconds spent waiting in ``delay()``

* For each pump:

  * Total number of millseconds spent in ``delay()`` with the pump on

  * Total number of compute cycles with the pump on

  * These last two give you a measure of how much water you have used
