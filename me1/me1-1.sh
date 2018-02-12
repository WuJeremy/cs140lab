#!/bin/bash

# Check if required parameters are supplied
if [[ $# -eq 0 ]]; then # or [[ -z $1 ]] to check if argument 1 is empty
    echo "Usage: $0 <name>"
    exit 1
fi

echo "Hello $1!"
