## Sheet 9

### Exercise 1

```
[daint][mtuor@daint-ln004 axpy]$ srun --account=uzh8 --constraint=gpu -n 1 ./axpy.openacc 24
memcopy and daxpy test of size 16777216
-------
timings
-------
axpy (openmp): 0.0501775 s
axpy (openacc): 3.36291 s

============ PASSED
```

The GPU runtime is much slower since the overhead of copying over the data to the GPU outweighs the acceleration as the problem is not big   enough. However for higher magnitude problems the GPU would be faster.

### Exercise 2

• What is the problem with this approach?

blur() must be compiled for the GPU (#pragma acc routine seq).
If this is not done, the compiler will either run blur() on the host → illegal inside a GPU kernel or fail to inline, which leads to a wrong result or crash. Also data is repeatedly transferred between CPU and GPU, and each loop executes in a separate kernel launch, which causes a huge overhead.

• What is the difference to the naive implementation?

The differences are that a persistent data region is used and only the loops are offloaded, not the data for each step which leads to better runtime.

• What is the difference in execution time?

naive:
```
[daint][mtuor@daint-ln004 basics]$ srun --account=uzh8 --constraint=gpu -n 1 ./blur.openacc 24 100
srun: job 2106480 queued and waiting for resources
srun: job 2106480 has been allocated resources
dispersion 1D test of length n = 16777220 : 128MB
==== success ====
Host version took 0.243021 s (0.00243021 s/step)
GPU version took 4.32421 s (0.0432421 s/step)
```

no copies:
```
[daint][mtuor@daint-ln004 basics]$ srun --account=uzh8 --constraint=gpu -n 1 ./blur.openacc 24 100
srun: job 2106498 queued and waiting for resources
srun: job 2106498 has been allocated resources
dispersion 1D test of length n = 16777220 : 128MB
==== success ====
Host version took 0.286841 s (0.00286841 s/step)
GPU version took 2.86165 s (0.0286165 s/step)
```

The no copies version is almost double as fast as the naive version.


