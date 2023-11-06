An attempt at using allowing several devices to connect to a Raspberry Pi Pico simultaneously:

* A keyboard
* A mouse
* Three CDC Serial devices
* Possibly Mass Storage devices

This is for the transputer-emulator project, when it's embedded on a Pi Pico. The three serial devices are for:

1) the link to the host computer
2) the debug connection for core 0 and
3) the debug connection for core 1.

Ideally I'd like to set custom strings for the details shown for the three serial ports.

To build: ./build.sh

