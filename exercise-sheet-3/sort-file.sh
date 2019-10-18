#!/bin/bash

input="personal"
output="personal.sort"

head -2 $input > $output
tail -n +3 $input >> $output
