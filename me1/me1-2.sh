#!/bin/bash

if [[ -z $1 || -z $2 ]]; then
    echo "Usage: $0 <operand-1> <operand-2>"
    exit 1
fi

# Using double parentheses
SUM=$(( $1 + $2 ))
echo "SUM: $SUM"

# Using let
let "DIFF = $1 - $2"
echo "DIFF: $DIFF"

# Using expr
PRODUCT=$( expr $1 \* $2 )
echo "PRODUCT: $PRODUCT"

# Using expr without storing to a variable
echo "QUOTIENT: `expr $1 / $2`"
