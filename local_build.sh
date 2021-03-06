#!/bin/bash
work_path=$(pwd)
main_path=$work_path/sdk/src/project
project_path=$work_path/project
build_path=$work_path/sdk/build
bin_file=$work_path/out.bin
k210tty=/dev/ttyUSB0

if [ ! -f $main_path/dev.h ]; then
    cp $project_path/dev.h $main_path
fi

if [ ! -f $main_path/dev.c ]; then
    cp $project_path/dev.c $main_path
fi

cd $work_path/sdk/build
make -j4 || exit
rm $bin_file
mv $work_path/sdk/build/project.bin $bin_file
rm project*