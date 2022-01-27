#!/bin/bash
work_path=/home/rock/k210/standalone
k210tty=/dev/ttyUSB1

cd $work_path/sdk/build && rm project*
make -j4 ||exit
rm $work_path/end.bin
mv $work_path/sdk/build/project.bin $work_path/end.bin
rm project*

