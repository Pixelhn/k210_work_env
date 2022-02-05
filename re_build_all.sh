#!/bin/bash
work_path=$(pwd)
main_path=$work_path/sdk/src/project
build_path=$work_path/sdk/build
bin_file=$work_path/out.bin
k210tty=/dev/ttyUSB0

if [ ! -f $main_path/board_config.h ]; then
    cp $project_path/board_config.h $main_path
fi

if [ ! -f $main_path/bcf.c ]; then
    cp $project_path/bcf.c $main_path
fi
rm $work_path/end.bin

    echo _________________BUILD_ALL!__________________
    cd $work_path/sdk/build
    rm -rf *
    cmake .. -DPROJ=project -DTOOLCHAIN=/opt/kendryte-toolchain/bin || exit
    make -j4 || exit
    echo _________________ALL_RIGHT!__________________