#!/bin/bash

srcDir=$1
dstDir=$2

cd srcDir

for s in $(ls | grep [A-Z]);
do
	mv -i $s dstDir/`echo $s | tr 'A-Z' 'a-z'`
done
