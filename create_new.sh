#!/bin/bash

if ! ll | grep -qx $1; then
	mkdir $1
	cp $PWD/template/* $1
fi

cd $1

