#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y) {
    int base = nx / size;
    int rest = nx % size;

    *min_x = my_rank * base + (my_rank < rest ? my_rank : rest);
    *max_x = *min_x + base + (my_rank < rest ? 1 : 0);

    *min_y = 0;
    *max_y = ny;

    printf("Rank %d domain: xmin=%d xmax=%d ymin=%d ymax=%d\n", my_rank, *min_x, *max_x, *min_y, *max_y);
    return 0;
}

int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight){
    int left  = (my_rank == 0) ? MPI_PROC_NULL : my_rank - 1;
    int right = (my_rank == size - 1) ? MPI_PROC_NULL : my_rank + 1;

    int nx_local = p.xmax - p.xmin;
    int ny_local = p.ymax - p.ymin;

    double* sendLeft  = new double[ny_local];
    double* sendRight = new double[ny_local];

    for (int j = 0; j < ny_local; j++) {
        sendLeft[j]  = u[1][j];
        sendRight[j] = u[nx_local][j]; 
    }

    MPI_Request reqs[4];

    MPI_Irecv(fromLeft,  ny_local, MPI_DOUBLE, left,  0, MPI_COMM_WORLD, &reqs[0]);
    MPI_Irecv(fromRight, ny_local, MPI_DOUBLE, right, 1, MPI_COMM_WORLD, &reqs[1]);

    MPI_Isend(sendRight, ny_local, MPI_DOUBLE, right, 0, MPI_COMM_WORLD, &reqs[2]);
    MPI_Isend(sendLeft,  ny_local, MPI_DOUBLE, left,  1, MPI_COMM_WORLD, &reqs[3]);

    MPI_Waitall(4, reqs, MPI_STATUSES_IGNORE);

    if (left != MPI_PROC_NULL)
        for (int j = 0; j < ny_local; j++) u[0][j] = fromLeft[j];
    if (right != MPI_PROC_NULL)
        for (int j = 0; j < ny_local; j++) u[nx_local+1][j] = fromRight[j];

    delete[] sendLeft;
    delete[] sendRight;

    return 0;
}

int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}

