#!/bin/bash
export PICO_SDK_PATH=~/Documents/pico-sdk-experiments/pico-sdk
if [ "$1" = "clean" ]
then
	rm -rf cmake-build-debug
fi

if [ ! -d cmake-build-debug ]
then
	mkdir cmake-build-debug
	(cd cmake-build-debug ; cmake ..)
fi
(cd cmake-build-debug ; make -j 4)
pwd
ls -l cmake-build-debug/usbexperiment.uf2

