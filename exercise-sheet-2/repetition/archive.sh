#!/bin/bash

archive=$1
srcDir=$2
dstDir="."

if [ -f $dstDir/$archive ]
then
	echo "Datei existiert bereits."
	exit
fi

if [ ! -d $dstDir ]
then
	echo "Zielverzeichnis existiert nicht."
	exit
fi

if [ ! [ -r $srcDir ] ]
then
	echo "Keine Leserechte..."
	exit
fi

tar cvfz $archive.tar.gz $srcDir
