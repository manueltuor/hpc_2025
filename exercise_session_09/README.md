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

The GPU runtime is much slower since the overhead of copying over the data to the GPU outweighs the acceleration as the problem is not big enough. However for higher magnitude problems the GPU would be faster.

