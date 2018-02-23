#!/bin/bash

if [[ -z $1 ]]; then
    echo "Usage: $0 <masterfile>"
    exit 1
fi

MASTERFILE=$1

awk -F, 'NF { fname=$3; gsub(" ", "", fname); print $0 > "me21output/"fname }' OFS=, $MASTERFILE
