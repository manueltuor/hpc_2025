## Sheet 5

### Exercise 1

1. init_f
   Initializes the source term matrix f for the Poisson equation.
2. jacobi_step
   Performs one Jacobi iteration to update the solution.
3. norm_diff
   Computes the L2 norm of the difference between two successive solutions.

### Exercise 3

1. Now parallelize in the same way also the second loop, counting the occurrences of 0 in
   the array. Run it again multiple times. What happens?
   The number of 0's is not counted correctly because of race conditions, since multiple threads write to the same variable.
2. Where is it best to insert these directives in order to avoid a
   serialization of your code? The best place to put the #pragma omp atomic in the second loop is where the number is incremented.
   In the first loop you would put a #pragma omp critical before the if check that checks if the number is bigger than the max value.
