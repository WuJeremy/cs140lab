#!/bin/bash

if [[ $# -eq 0 ]]; then # or [[ -z $1 ]] to check if argument 1 is empty
    echo "Usage: $0 <date>"
    exit 1
fi

# Test if valid date
date -d "$1" &> /dev/null
if [[ $? -ne 0 ]]; then
    echo "Not a valid date!"
    exit 1
fi

echo "$1 is a `date -d "$1" +%A`"
