#!/bin/sh
#cppcheck  --force --std=c99 --language=c src/
make clean
rm -rf bin obj
make all
#fuser -k /dev/ttyACM0
avrdude -C etc/avrdude.conf -v -c arduino -P /dev/ttyUSB0 -p atmega328pb -b 115200 -D -U flash:w:bin/firmware.elf
figlet "MSWI19"
