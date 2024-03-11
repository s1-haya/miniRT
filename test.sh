#!/bin/bash

for file in rt_file/error/*; do
	echo $file && ./miniRT $file;
done
