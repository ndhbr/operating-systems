#!/bin/bash

if [ ! $# == 2 ]; then
    echo "Bitte gebe exakt zwei Parameter ein!"
fi

if [ -d "$2" ]; then
    echo "Zielpfad wird in $1 gepackt."
    tar -zcvf "$1" "$2"
else
    echo "Der angegebene Zielpfad existiert nicht."
fi
