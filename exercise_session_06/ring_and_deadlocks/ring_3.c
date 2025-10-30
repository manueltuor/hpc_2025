#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int dims[1] = {size};
    int periods[1] = {1};
    MPI_Comm comm_cart;
    MPI_Cart_create(MPI_COMM_WORLD, 1, dims, periods, 1, &comm_cart);

    int my_cart_rank;
    MPI_Comm_rank(comm_cart, &my_cart_rank);

    int left, right;
    MPI_Cart_shift(comm_cart, 0, 1, &left, &right);

    int my_sum = 0;
    int send_rank = my_cart_rank;
    int recv_rank = 0;

    for (int i = 0; i < size; i++) {
        MPI_Request requests[2];
        MPI_Irecv(&recv_rank, 1, MPI_INT, left, 0, comm_cart, &requests[0]);
        MPI_Isend(&send_rank, 1, MPI_INT, right, 0, comm_cart, &requests[1]);
        MPI_Waitall(2, requests, MPI_STATUSES_IGNORE);

        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    printf("I am process %d out of %d, and the sum is %d\n", my_cart_rank, size, my_sum);

    MPI_Finalize();
    return 0;
}
