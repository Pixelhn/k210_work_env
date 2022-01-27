#!/bin/bash
work_path=/home/rock/k210/standalone
k210tty=/dev/ttyUSB1
bin_file=$work_path/out.bin

cd $work_path/sdk/build
make -j4 || exit
rm $work_path/end.bin
mv $work_path/sdk/build/project.bin $bin_file
rm project*
/home/rock/.local/bin/kflash -p $k210tty $bin_file -b 1500000 -B maixduino -t

