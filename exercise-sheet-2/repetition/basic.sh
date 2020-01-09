#! /bin/bash

echo "ANZAHL ARGUMENTE = "$#

i=1
anz=$(( $# + 1))
while [ "$i" -lt "$anz" ]
do
	echo "$1" | tr '[:upper:]' '[:lower:]'
	i=$(( $i + 1 ))
	shift 1
done
