#!/bin/bash

if [ -z $@ ]; then
    echo "Bitte gebe Dateinamen ein!"
else
    echo "Folgende Dateien angegeben: $@"
fi

i=1
anz=$(( $# + 1 ))

while [ "$i" -lt "$anz" ]
do
    if [ "$1" != "toLwr.sh" ] && [ -f "$1" ] && ! [ "$1" == "*.pwd" ]; then
        echo "Renaming $1..."
        mv "$1" "${1,,}"
    fi

    i=$(( $i + 1 ))
    shift 1
done
