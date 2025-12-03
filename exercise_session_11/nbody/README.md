## Sheet 11

### Exercise 1

You can find the full report of the run in [this file](https://github.com/manueltuor/hpc_2025/blob/main/exercise_session_11/nbody/nbody%2B42806-1773752035s/rpt-files/RUNTIME.rpt).
Below I summarized a couple of the key metrics.

#### Program Runtime Summary

| Metric              | Value            |
|---------------------|------------------|
| Average runtime     | 12.86 seconds     |
| Number of MPI ranks | 1                |
| Threads per rank    | 1                |
| Frequency           | 2.251 GHz         |
| Peak memory usage   | 46.2 MiB          |
| Node                | eiger-ln002       |
| CPU                 | AMD Rome          |

#### Source-Level Hotspots (Perftools-Lite)

| File / Location | Line | Sample % | Samples | Description |
|-----------------|------|----------|---------|-------------|
| nbody.cpp       | 40   | 56.5%    | 723     | Main compute loop |
| nbody.cpp       | 39   | 22.9%    | 293     | Loop iteration / accumulation |
| nbody.cpp       | 38   | 3.8%     | 49      | Setup / function call |
| stl_vector.h    | 386  | 16.7%    | 214     | Vector access / bounds checks |

**Total samples:** 1280

#### Interpretation

The performance analysis shows that almost all execution time (100%) is spent inside `main()`, and more than 80% is concentrated within three adjacent lines in `nbody.cpp` (lines 38–40).
Line 40 is the main performance hotspot (56.5%), which indicates the primary computational kernel of the N-body simulation (likely the nested force calculation loop). Line 39 (22.9%) contributes significantly, likely controlling accumulation of results.
The standard library `vector` implementation also accounts for 16.7% of runtime, which suggests non-trivial memory access overhead and possible inefficiencies related to dynamic memory usage or poor data locality.
The application shows minimal memory bandwidth usage, so performance is **compute-bound rather than memory-bound**.

Conclusion: Performance is dominated by the force computation loop and could benefit from:
- Multi-threading (OpenMP)
- Vectorization
- GPU offloading
- Reducing STL overhead

### Exercise 2

| function | Runtime (s) |
|-----------------|------|
| sqrt       | 12.818 | 
| sqrtf       | 7.231 | 
