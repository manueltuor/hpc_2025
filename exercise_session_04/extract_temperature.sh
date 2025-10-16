#!/bin/bash

OUTFILE="out.txt"
> "$OUTFILE" 

total_temp=0
count=0

for file in measured/measurements*.txt; do
    grep -E "Temperature:|time:" "$file" >> "$OUTFILE"

    temps=$(grep -E "Temperature:" "$file" | awk '{print $2}')
    for t in $temps; do
        total_temp=$(echo "$total_temp + $t" | bc -l)
        count=$((count + 1))
    done
done

if [ $count -gt 0 ]; then
    avg=$(echo "$total_temp / $count" | bc -l)
    echo "Average temperature: $avg"
else
    echo "No temperature data found."
fi
