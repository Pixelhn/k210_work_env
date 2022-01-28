#!/bin/bash
work_path=/home/rock/k210/standalone
k210tty=/dev/ttyUSB0
bin_file=$work_path/out.bin
main_path=$work_path/sdk/src/project
project_path=$work_path/project

if [ ! -f $main_path/board_config.h ]; then
    cp $project_path/board_config.h $main_path
fi

cd $work_path/sdk/build
make -j4 || exit
rm $bin_file
mv $work_path/sdk/build/project.bin $bin_file
rm project*
/home/rock/.local/bin/kflash -p $k210tty $bin_file -b 1500000 -B maixduino -t

