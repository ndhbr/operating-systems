#!/bin/bash

echo "ANZAHL ARGUMENTE = "$#
echo $@

anz=$(( $# + 1 ))
i=0
while [ "$i" -lt "$anz" ]
do
    echo "Parameter "$i
    echo $1
    i=$(( $i + 1 ))
    shift 1
done
