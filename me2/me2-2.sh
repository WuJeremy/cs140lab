#!/bin/bash

if [[ -z $1 ]]; then
    echo "Usage: $0 <grades-file>"
    exit 1
fi

GRADESFILE=$1

awk -F, -f me2-2.awk $GRADESFILE > tmp
mv tmp $GRADESFILE
