An attempt at using allowing several devices to connect to a Raspberry Pi Pico simultaneously:

* A keyboard
* A mouse
* Three CDC Serial devices
* Possibly Mass Storage devices

NOTE: this project has been ABANDONED as it is not possible to EASILY use a Pi
Pico for both host and device mode using the Pico's inbuilt USB port. The state
of the project is from when I was trying to get both working, which was futile.

I asked for advice in the Pico forum at
https://forums.raspberrypi.com/viewtopic.php?t=359363 and thanks to helpful
replies from DrDnar and hippy, I've decided that to keep the hardware as simple
as possible, I'll use two Picos, one for the CDC links, and another for the
Keyboard / Mouse. They'll be connected by emulated Transputer links.

Initial ideas...

This is for the transputer-emulator project, when it's embedded on a Pi Pico. The three serial devices are for:

1) the link to the host computer
2) the debug connection for core 0 and
3) the debug connection for core 1.

Ideally I'd like to set custom strings for the details shown for the three serial ports.

Acknowledgements:
This started from the example Keyboard/Mouse code in
https://github.com/a-h/pico_usb_kbd_mouse from Adrian Hesketh. I'm not sure
this works in the form I have it here. Experimentation continues.

I added the tinyusb dual_cdc code - this works.

As mentioned above (ABANDONED) - you can't have both host mode and device mode active simultaneously.

Build:

To build: initialise the copy of the tinyusb repo in your pico SDK directory with
'git submodule update --init'.

./build.sh clean

Subsequent builds can just do ./build.sh




