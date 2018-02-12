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

# What day of the week it is
echo "$1 is a `date -d "$1" +%A`"

SECONDS_PER_DAY=86400
REMAINING_SECONDS=$(( `date -d "$1" +%s` - `date +%s` ))
DAYS_REMAINING=`expr $REMAINING_SECONDS / $SECONDS_PER_DAY`
if [[ $REMAINING_SECONDS -gt 0 ]]; then
    (( DAYS_REMAINING++ ))
fi

# How many days remaining (ceiling)
echo "$DAYS_REMAINING day(s) remaining"
