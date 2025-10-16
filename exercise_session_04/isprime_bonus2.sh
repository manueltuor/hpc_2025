#!/bin/bash

if [ $# -ne 2 ]; then
    echo "ERROR: Please provide exactly two numbers: start and end of range."
    exit 1
fi

start="$1"
end="$2"

if ! [[ "$start" =~ ^[0-9]+$ && "$end" =~ ^[0-9]+$ ]]; then
    echo "ERROR: Both inputs must be positive integers."
    exit 1
fi

for num in $(seq "$start" "$end"); do
    factor_output=$(factor "$num")
    factor_count=$(echo "$factor_output" | cut -d':' -f2 | wc -w)
    if [ "$factor_count" -eq 1 ]; then
        echo "$num is prime"
    fi
done
