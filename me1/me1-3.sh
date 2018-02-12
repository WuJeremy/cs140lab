#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Usage: $0 <directory> <minimum-word-count>"
    exit 1
fi

WORKINGDIR=$1
MINCOUNT=$2

if [[ ! -d $WORKINGDIR ]]; then
    echo "ERROR: Not a valid directory!"
    exit 1
fi

for FILE in $WORKINGDIR/*; do
    WORDCOUNT=`wc -w $FILE | cut -f1 -d' '`
    if [[ $WORDCOUNT -lt $MINCOUNT ]]; then
        echo "$FILE (word count: $WORDCOUNT)"
    fi
done

# Using find (for more selective cases)
#find $WORKINGDIR -maxdepth 1 -type f -exec echo "{}" \; | while read file; do 
#   ... code here
#done
