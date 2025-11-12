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
