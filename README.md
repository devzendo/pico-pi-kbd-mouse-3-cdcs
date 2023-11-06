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

Acknowledgements:
This started from the example code in https://github.com/a-h/pico_usb_kbd_mouse from Adrian Hesketh.

To build: initialise the copy of the tinyusb repo in your pico SDK directory with
'git submodule update --init'.

./build.sh clean

Subsequent builds can just do ./build.sh




