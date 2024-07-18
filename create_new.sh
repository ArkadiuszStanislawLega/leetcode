#!/bin/bash

if [ -z "$1" ]; then
	echo "Insert name of directory."
	return 1
fi

if ! ll | grep -qx $1; then
	mkdir $1
	cp $PWD/template/* $1
fi

cd $1

