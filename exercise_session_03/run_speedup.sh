#!/bin/bash

# Array of thread counts
THREADS=(1 2 4 8)

# Output file
OUTFILE="speedup_results.txt"
echo "Threads,Time(s)" > $OUTFILE

for t in "${THREADS[@]}"; do
    export OMP_NUM_THREADS=$t
    # Run the program and extract the elapsed time
    TIME=$(./sum_parallel | grep "Elapsed time" | awk '{print $3}')
    echo "$t,$TIME" >> $OUTFILE
done

echo "Results saved in $OUTFILE"
