#!/bin/bash

blocks=(60 120 180 240 300 360 420 600)
threads=(16 32 48 64 80 96 112 128 144 160)

> output_scaling.txt

for b in "${blocks[@]}"; do
  for t in "${threads[@]}"; do
    ./cpi_cuda $b $t
    
    echo "NUM_BLOCK=$b THREAD=$t" >> output_scaling.txt
  done
done
