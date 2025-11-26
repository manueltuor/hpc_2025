## Sheet 10

### Exercise 4

| Block Size | GPU Convolution Time (ms) |
|------------|---------------------------|
| 8          | 0.258592                  |
| 16         | 0.047296                  |
| 32         | 0.027168                  |
| 64         | 0.018432                  |
| 128        | 0.013312                  |
| 256        | 0.011488                  |
| 512        | 0.011232                  |
| 1024       | 0.011936                  |

**Optimal Block Size:** 512 (Time: 0.011232 ms)  

**Final Run:**  
- GPU Convolution Time: 0.011200 ms  
- CPU Convolution Time: 0.000000 s  
- Result: PASSED
