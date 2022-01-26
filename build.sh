#!/bin/bash
work_path=/home/rock/k210/standalone
build_path=/home/rock/k210/standalone/sdk/build
k210tty=/dev/ttyUSB0

rm $work_path/end.bin
if $1 ; then
    echo _____BUILD_ALL____
    cd $work_path/sdk/build
    rm -rf *
    cmake .. -DPROJ=project -DTOOLCHAIN=/opt/kendryte-toolchain/bin 
    make -j4 && mv $build_path/project.bin $work_path/end.bin
    rm $build_path/project*
else
    cd $work_path/sdk/build && rm project*
    make -j4 && mv $work_path/sdk/build/project.bin $work_path/end.bin
fi