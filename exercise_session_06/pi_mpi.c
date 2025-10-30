#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int my_rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const long long N = 1000000000;
    long long chunk = N / size;
    long long start = my_rank * chunk;
    long long end   = (my_rank == size - 1) ? N : start + chunk;

    double partial_sum = 0.0;

    for (long long i = start; i < end; i++) {
        double term = (i % 2 == 0 ? 1.0 : -1.0) / (2*i + 1);
        partial_sum += term;
    }

    double pi = 0.0;

    MPI_Reduce(&partial_sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        pi *= 4.0;
        printf("Approximated value of pi using %lld terms: %.15f\n", N, pi);
    }

    MPI_Finalize();
    return 0;
}
