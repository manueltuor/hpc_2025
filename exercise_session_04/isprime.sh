#!/bin/bash

if [ $# -ne 1 ]; then
    echo "ERROR: Please provide exactly one argument."
    exit 1
fi

num="$1"

if ! [[ "$num" =~ ^[0-9]+$ ]]; then
    if [[ "$num" =~ ^-?[0-9]+$ ]]; then
        echo "ERROR: The given input is not a positive integer: $num"
    else
        echo "ERROR: The given input is not a number: $num"
    fi
    exit 1
fi

start_time=$(date +%s.%N)
factor_output=$(factor "$num")
end_time=$(date +%s.%N)

factor_count=$(echo "$factor_output" | cut -d':' -f2 | wc -w | cut -d':' -f2)

if [ "$factor_count" -eq 1 ]; then
    echo "$num is prime"
else
    echo "$num is composite"
fi

elapsed=$(echo "$end_time - $start_time" | bc -l)
printf "Execution time: %.6f seconds\n" "$elapsed"
