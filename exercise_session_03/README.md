# Exercise Session 03 #
## Exercise 1
	•	tWElapsed (1.477 s) measures only the time spent inside the computation loop using MPI_Wtime().
	•	tEnd - tStart (1.607 s) measures the total wall-clock time, including:
	•	Startup costs of the MPI environment (MPI_Init)
	•	Finalization overhead (MPI_Finalize)
	•	Any other minor setup/teardown costs
	•	The serial execution time (1.51 s) is roughly between those two values because it has no MPI overhead but does include the whole computation.
