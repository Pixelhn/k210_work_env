#!/bin/bash

K210_port=/dev/ttyUSB0
WD=$(pwd)

MAIN_PATH=$WD/src/
SDK_PATH=$WD/sdk/src/

BUILD_PATH=$WD/sdk/build
END_BIN=$WD/end.bin


bash ./clean.sh

cp -r $MAIN_PATH/* $SDK_PATH

cd $BUILD_PATH

cmake .. -DPROJ=project -DTOOLCHAIN=/mnt/sdcard/K210/kendryte-toolchain/bin || exit
make -j4 || exit

mv $BUILD_PATH/project.bin $END_BIN
rm project*

ls -al $END_BIN