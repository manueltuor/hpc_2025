## Sheet 8

### Exercise 8.1

Output:

```
[daint][mtuor@daint-ln002 openacc]$ cat cpi_openacc.out
PI = 3.141592653589793 computed in 0.8642 seconds
PI = 3.141592653589793 computed in 0.001157 seconds
PI = 3.141592653589793 computed in 0.00115 seconds
PI = 3.141592653589793 computed in 0.001142 seconds
PI = 3.141592653589793 computed in 0.001141 seconds
```

• Does each iteration have the same run time?

No, the first iteration takes significantly longer since there is implementation overhead from GPU code compilation and setup as well as memory allocation.

### Exercise 8.2

Output (I added a for loop to the cuda code to compare it with 8.1):

```
[daint][mtuor@daint-ln002 cuda]$ srun --gres=gpu:1 ./cpi_cuda
srun: job 1998042 queued and waiting for resources
srun: job 1998042 has been allocated resources
PI = 3.14159265358979 computed in 0.04854 seconds
PI = 3.141592656731382 computed in 0.04841 seconds
PI = 3.141592656731382 computed in 0.04841 seconds
PI = 3.141592656731382 computed in 0.04841 seconds
PI = 3.141592656731382 computed in 0.04841 seconds
```

• Run the code and compare the execution time with your results from exercise 1. Are the times of each iteration the same? Why (not)?

The runtimes of cuda are more consistent than the ones from openacc, however after the first iteration openacc is faster. In cuda the runtimes of each iteration are roughly the same, because memory and threads are preallocated in cuda and so kernel launches dominate the runtime.

