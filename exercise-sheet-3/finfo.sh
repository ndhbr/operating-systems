#!/bin/bash

file=$1

if [ ! -z $file ]; then
    IFS=' ' read -r -a array <<< $(ls -l $file)

    echo "-------------------------------------------------------"
    echo "Datei: ${array[7]} $file"
    echo "Rechte: ${array[0]}"
    echo "Größe: ${array[4]}"
    echo "Besitzer: ${array[2]}"
    echo "Gruppe: ${array[3]}"
    echo "Letzte Änderung: ${array[5]} ${array[6]}"
    echo "-------------------------------------------------------"
fi
