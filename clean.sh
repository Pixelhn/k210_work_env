#!/bin/bash

K210_port=/dev/ttyUSB0
WD=$(pwd)

MAIN_PATH=$WD/src/
SDK_PATH=$WD/sdk/src/

BUILD_PATH=$WD/sdk/build
END_BIN=$WD/end.bin

rm -rf $SDK_PATH*

rm -rf $BUILD_PATH/*

if [ -f $END_BIN ]; then
    rm $END_BIN
fi