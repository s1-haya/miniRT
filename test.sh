#!/bin/bash

for file in rt_file/bonus/*; do
	echo $file && ./miniRT $file;
done
