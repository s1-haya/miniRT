#!/bin/bash

for file in rt_file/success/*; do
	echo $file && ./miniRT $file
done
