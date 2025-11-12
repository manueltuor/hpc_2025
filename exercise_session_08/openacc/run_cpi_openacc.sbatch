#!/bin/bash
#SBATCH --job-name=cpi_openacc
#SBATCH --output=cpi_openacc.out
#SBATCH --error=cpi_openacc.err
#SBATCH --nodes=1                     
#SBATCH --ntasks-per-node=1           
#SBATCH --gres=gpu:1                  
#SBATCH --time=00:10:00               
#SBATCH --partition=normal            

# Load required modules
module load cray
module load nvhpc

# Run the program
srun ./cpi_openacc
