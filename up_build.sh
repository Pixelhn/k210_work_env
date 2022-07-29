#!/bin/bash

K210_PORT=/dev/ttyUSB0
WD=$(pwd)

MAIN_PATH=$WD/src/
SDK_PATH=$WD/sdk/src/

BUILD_PATH=$WD/sdk/build
END_BIN=$WD/end.bin


#bash ./clean.sh

cp -r $MAIN_PATH/* $SDK_PATH

cd $BUILD_PATH
if [ ! -f $BUILD_PATH/Makefile ]; then
    echo run re_build.sh
    exit
fi
#cmake .. -DPROJ=project -DTOOLCHAIN=/mnt/sdcard/K210/kendryte-toolchain/bin || exit
make -j4 || exit

mv $BUILD_PATH/project.bin $END_BIN
rm project*

ls -al $END_BIN
kflash -p $K210_PORT $END_BIN -b 1500000 -B maixduino -t

