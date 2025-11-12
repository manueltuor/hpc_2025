#!/bin/bash
#SBATCH --job-name=cuda_scaling
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --time=00:30:00
#SBATCH --output=output_scaling.txt

module load nvhpc
./run_cuda_scaling.sh
