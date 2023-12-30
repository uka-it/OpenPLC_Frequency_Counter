This is an attempt to implement a frequency counter using OpenPLC.
For this to work the task time cycle interval must be set to 0.5 milliseconds.
If you change this you may need to calibrate the counter. The frequency range that can be measured is related to the cycle time, it won´t be able
to count pulses if they come faster than the cycle time, some will be missed(aliasing).
The counter calibration can be done altering the constant value that multiplies the measured frequency in the assigned interval (200ms).

In this example, it is measuring pulses in a 200ms interval, which is 1/5 of a second. The measured frequency will be the counted pulses in 200ms
interval times 5 (since frequency is cycles/s). The decimal digits is used for calibration, on my tests it had an small linear error that can be
corrected this way.
When I was testing with an internal pulse generator(inside the same OpenPLC program) it did not need calibration, but when used with an external source
it did not work. It seems the cycle time is not 100% accurate, so if another functions and/or tasks added to the program, it may need aditional corrections
as it should alter the cycle time.

It has been tested from 0hz to 500hz on an ESP32 microcontroller with a square wave and seems to be working with enough accuracy.
May not be reliable enough for anything that requires high precision and/or response time, although it seems to be very responsive.

ESP32 Inputs / Outputs:
Frequency Input 17 (Digital)
Frequency Value Output 25 (Analog)

The Frequency Value will be a uint value corresponding to the measured frequency.

This was implemented just to save hardware in some educational experiments and precision should not be expected.
There is a better and right way to count pulses.

Thanks.
