#!/bin/bash

cd /home/pi/Desktop/satrot/Software/RotorDriver-GUI/build

qmake ..

make

cd RotorDriver

./RotorDriver