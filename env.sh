#!/bin/bash
work_path=/home/rock/k210/standalone
build_path=$work_path/sdk/build
main_path=$work_path/sdk/src/project
bin_file=$work_path/out.bin
k210tty=/dev/ttyUSB0

cp $work_path/project/board_config.h $main_path
rm $work_path/end.bin

    echo _________________BUILD_ALL!__________________
    cd $work_path/sdk/build
    rm -rf *
    cmake .. -DPROJ=project -DTOOLCHAIN=/opt/kendryte-toolchain/bin || exit
    make -j4 || exit
    echo _________________ALL_RIGHT!__________________