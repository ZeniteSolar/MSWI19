cd lib/avr-can-lib
git submodule init
git submodule update
cd src/
make clean
make lib
cd ../../../
cd lib/DISPLAYS/SSD1306_AVR
make clean
make
cd src/
wget https://raw.githubusercontent.com/ZeniteSolar/CAN_IDS/master/can_ids.h
cd ..
