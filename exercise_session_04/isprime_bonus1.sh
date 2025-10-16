#!/bin/bash

if [ $# -lt 1 ]; then
    echo "ERROR: Please provide at least one number."
    exit 1
fi

while [ $# -gt 0 ]; do
    num="$1"

    if ! [[ "$num" =~ ^[0-9]+$ ]]; then
        if [[ "$num" =~ ^-?[0-9]+$ ]]; then
            echo "ERROR: The given input is not a positive integer: $num"
        else
            echo "ERROR: The given input is not a number: $num"
        fi
        shift
        continue
    fi

    factor_output=$(factor "$num")
    factor_count=$(echo "$factor_output" | cut -d':' -f2 | wc -w)

    if [ "$factor_count" -eq 1 ]; then
        echo "$num is prime"
    else
        echo "$num is composite"
    fi

    shift
done
