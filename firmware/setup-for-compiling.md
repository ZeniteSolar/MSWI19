# How to setup for compiling:

This is an easy way to use atmega328pb-au:

## Bootloader
- Download and install [Arduino IDE](https://www.arduino.cc)
- Setup [MiniCore](https://github.com/MCUdude/MiniCore)
    - Follow [How to install](https://github.com/MCUdude/MiniCore#how-to-install)
    - Follow [Getting started with MiniCore](https://github.com/MCUdude/MiniCore#getting-started-with-minicore)
    - BOD: 2.7V
    - Crystal: External 16 MHz
    - Burn the bootloader using a simple usb programmer like usbASP

## This firmware
- Configuring Makefile
    - Find binaries for avr-gcc from installed arduino (eg `~/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin`)
        - hint: you can use `sudo updatedb && locate arduino/tools/avr-gcc | grep bin`
    - Open Makefile and edit `CROSS` (around line 68) to match your bin folder.

# To upload:
- Plug your usb-serial device and edit the -P (port parameter).
    - hint 1: `dmesg | tail -n10 | grep attached` to find it.
    - hint 2: you need to have write permission and the correct way of doing
      that is to add yourself in the correct group. To find the group you can
      use `ls -la` to the device. An easy and non-permanent workarround could be a `chown`.
- Wire some tactil switch from RST to GND.
- run `./up.sh` and press reset while uploading (it is not hard to get the
  timming).

