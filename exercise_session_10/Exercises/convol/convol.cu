#include <time.h>
#include <cuda.h>
#include <stdio.h>
#define STOP 0
#define START 1

extern "C" void chrono(int kind, float *time);

__global__ void kconvol(float *gpu_a, float *gpu_b, int n) {
    int i, j, l;

    l = blockDim.x * blockIdx.x + threadIdx.x;

    j = l / n;
    i = l - j * n;

    if ((i >= n) || (j >= n)) return;

    if ((i == 0) || (j == 0) || (i == n - 1) || (j == n - 1)) {
        gpu_b[l] = gpu_a[l];
    }
    else {
        gpu_b[l] = (1.0f / 5.0f) *
                   (gpu_a[l - n] + gpu_a[l - 1] + gpu_a[l] +
                    gpu_a[l + 1] + gpu_a[l + n]);
    }
}

extern "C" void gpu_convol(float *a, float *b, int n) {
    float *gpu_a;
    float *gpu_b;
    cudaError_t err;
    size_t size = n * n * sizeof(float);

    err = cudaMalloc(&gpu_a, size);
    if (err != 0) { printf("Error allocating gpu_a: %s\n", cudaGetErrorString(err)); exit(1); }
    err = cudaMalloc(&gpu_b, size);
    if (err != 0) { printf("Error allocating gpu_b: %s\n", cudaGetErrorString(err)); exit(1); }

    cudaMemcpy(gpu_a, a, size, cudaMemcpyHostToDevice);

    printf("\n--- GPU Block Size Tuning ---\n");
    int total_elements = n * n;

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    int best_block_size = 0;
    float best_time = 1e9f;

    int blockSizes[] = {8, 16, 32, 64, 128, 256, 512, 1024};
    int nBlockSizes = sizeof(blockSizes)/sizeof(blockSizes[0]);

    for (int t = 0; t < nBlockSizes; t++) {
        int block_size = blockSizes[t];
        int numBlocks = (total_elements + block_size - 1)/block_size;
        float elapsed_ms;

        cudaEventRecord(start, 0);
        kconvol<<<numBlocks, block_size>>>(gpu_a, gpu_b, n);
        err = cudaDeviceSynchronize();
        cudaEventRecord(stop, 0);
        cudaEventSynchronize(stop);
        cudaEventElapsedTime(&elapsed_ms, start, stop);

        if (err != 0) {
            printf("Error during kernel for block size %d: %s\n", block_size, cudaGetErrorString(err));
            exit(1);
        }

        printf("Block size %4d: Convolution took %f ms\n", block_size, elapsed_ms);

        if (elapsed_ms < best_time) {
            best_time = elapsed_ms;
            best_block_size = block_size;
        }
    }

    printf("Optimal Block Size: %d (Time: %f ms)\n", best_block_size, best_time);
    printf("-----------------------------\n");

    int final_num_blocks = (total_elements + best_block_size - 1)/best_block_size;
    float final_time;
    cudaEventRecord(start, 0);
    kconvol<<<final_num_blocks, best_block_size>>>(gpu_a, gpu_b, n);
    err = cudaDeviceSynchronize();
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&final_time, start, stop);

    printf("Convolution took %f ms on GPU\n", final_time);

    cudaMemcpy(b, gpu_b, size, cudaMemcpyDeviceToHost);

    cudaFree(gpu_a);
    cudaFree(gpu_b);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
}
