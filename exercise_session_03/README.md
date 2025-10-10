# Exercise Session 03 #
## Exercise 1
	•	tWElapsed (1.477 s) measures only the time spent inside the computation loop using MPI_Wtime().
	•	tEnd - tStart (1.607 s) measures the total wall-clock time, including:
	•	Startup costs of the MPI environment (MPI_Init)
	•	Finalization overhead (MPI_Finalize)
	•	Any other minor setup/teardown costs
	•	The serial execution time (1.51 s) is roughly between those two values because it has no MPI overhead but does include the whole computation.

## Exercise 2

### Exercise 2.1

[eiger][mtuor@eiger-ln004 exercise_session_03]$ ./sum_O0
sum=10022429073.341873
Elapsed time: 4.916411 seconds
No optimization, code runs exactly as written.

[eiger][mtuor@eiger-ln004 exercise_session_03]$ ./sum_O1
sum=10022429073.341873
Elapsed time: 1.956954 seconds
Removes some redundant instructions, simple inlining.

[eiger][mtuor@eiger-ln004 exercise_session_03]$ ./sum_O2
sum=10022429073.341873
Elapsed time: 1.077999 seconds
Loop optimizations, instruction scheduling, better inlining.

[eiger][mtuor@eiger-ln004 exercise_session_03]$ ./sum_O3
sum=10022429073.341873
Elapsed time: 1.082061 seconds
Aggressive optimizations, vectorization, auto-parallelization in some cases.

Other Ways to Get Timings

Besides getTime(), other ways to get timings:
clock() (from time.h) – measures CPU time.
omp_get_wtime() – high-resolution timer for OpenMP parallel regions.

How to make it even faster?
Parallelize the main loop

### Exercise 2.2

The line was inserted right before the for loop. The code was compiled as follows: cc -O3 -fopenmp sum.c getTime.c -o sum_parallel -lm.

### Exercise 2.3

As you can see on the plot the speedup is between linear and exponential.

