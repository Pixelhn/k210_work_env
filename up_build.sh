#!/bin/bash
work_path=$(pwd)
main_path=$work_path/sdk/src/project
build_path=$work_path/sdk/build
bin_file=$work_path/out.bin
k210tty=/dev/ttyUSB0

if [ ! -f $main_path/board_config.h ]; then
    cp $project_path/board_config.h $main_path
fi

cd $work_path/sdk/build
make -j4 || exit
rm $bin_file
mv $work_path/sdk/build/project.bin $bin_file
rm project*
/home/rock/.local/bin/kflash -p $k210tty $bin_file -b 1500000 -B maixduino -t

