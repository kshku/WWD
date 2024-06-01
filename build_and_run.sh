#!/bin/sh

files="main.c wallhavenAPI/wallhavenapi.c"
defines="-D DEBUG"
includes="-I wallhavenAPI"
libs="-lcurl"
name="wwd"

gcc $defines $includes $files -o $name $libs

if [ $? -eq 0 ]
then
    echo "Built successfully!"
    echo "Running the $name"
    ./$name
    echo "$name exited with the exit code $?"
else
    echo "Error during compilation"
fi
