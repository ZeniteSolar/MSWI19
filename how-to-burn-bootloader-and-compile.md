```
#clone MiniCore
git clone https://github.com/MCUdude/MiniCore.git
cd MiniCore
avrdude -C avr/avrdude.conf -v -patmega328pb -cusbasp -Pusb -e -Ulock:w:0x3f:m -Uefuse:w:0b11110101:m -Uhfuse:w:0xd6:m -Ulfuse:w:0b11111111:m 
```
Use Usbasp programer

for compile the code install 
aur/avr-libc-atmega328pb (arch linux)
https://gist.github.com/goncalor/51e1c8038cc058b4379552477255b4e1



