#!/bin/bash

if [ ! $# == 2 ]; then
    echo "Bitte gebe exakt zwei Parameter ein!"
    exit 1
fi

if [ -e "$1" ]; then
    echo "Der angegebene Dateiname existiert bereits."
    exit 1
fi

if [ -d "$2" ]; then
    if [ -r "$2" ]; then
        echo "Keine Leseberechtigung..."
        exit 1
    fi

    echo "Zielpfad wird in $1 gepackt."
    tar -zcvf "$1" "$2"
else
    echo "Der angegebene Zielpfad existiert nicht."
fi
