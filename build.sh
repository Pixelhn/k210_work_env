#!/bin/bash
work_path=/home/rock/k210/standalone
build_path=$work_path/sdk/build
bin_file=$work_path/out.bin
k210tty=/dev/ttyUSB0

rm $work_path/end.bin
if $1 ; then
    echo ___________BUILD_ALL!____________
    cd $work_path/sdk/build
    rm -rf *
    cmake .. -DPROJ=project -DTOOLCHAIN=/opt/kendryte-toolchain/bin || exit
    make -j4 || exit
    mv $build_path/project.bin $bin_file
    rm $build_path/project*
    echo ___________ALL_RIGHT!____________
else
    cd $work_path/sdk/build && rm project*
    make -j4 && mv $work_path/sdk/build/project.bin $work_path/end.bin
fi