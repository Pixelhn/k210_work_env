#!/bin/bash
work_path=/home/rock/k210/standalone
k210tty=/dev/ttyUSB1

cd $work_path/sdk/build
make -j4 ||exit
rm $work_path/end.bin
mv $work_path/sdk/build/project.bin $work_path/end.bin
rm project*
/home/rock/.local/bin/kflash -p $k210tty $work_path/end.bin -b 1500000 -B maixduino -t

