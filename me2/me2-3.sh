#!/bin/bash

if [[ -z $1 ]]; then
    echo "Usage: $0 <grades-file>"
    exit 1
fi

GRADESFILE=$1

awk '{$1 = ++i FS $1; print $0}' FS=, OFS=, $GRADESFILE
