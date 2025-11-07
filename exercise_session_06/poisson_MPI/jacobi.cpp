#include "jacobi.h"
#include <math.h>
#include "mpi_module.h"
#include <mpi.h>

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
    double local_sum = 0.0;
    int nx_local = p.xmax - p.xmin;
    int ny_local = p.ymax - p.ymin;

    for (int i = 1; i <= nx_local; i++){       
        for (int j = 0; j < ny_local; j++){
            double diff = mat1[i][j] - mat2[i][j];
            local_sum += diff * diff;
        }
    }

    double global_sum = 0.0;
    MPI_Allreduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    double norm = sqrt(global_sum / (p.nx * p.ny));
    return norm;
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */

void jacobi_step(params p, double** u_new, double** u_old, double** f, int my_rank, int size){
    double dx = 1.0/((double)p.nx - 1);
    double dy = 1.0/((double)p.ny - 1);

    int nx_local = p.xmax - p.xmin;
    int ny_local = p.ymax - p.ymin;

    double* fromLeft = new double[ny_local];
    double* fromRight = new double[ny_local];

    for (int i = 1; i <= nx_local; i++){                  
        for (int j = 0; j < ny_local; j++){
            u_old[i][j] = u_new[i][j];
        }
    }

    halo_comm(p, my_rank, size, u_new, fromLeft, fromRight);

    for (int i = 1; i <= nx_local; i++){                   
        if (i==1 && my_rank==0) continue;                 
        if (i==nx_local && my_rank==size-1) continue;     
        for (int j = 1; j < ny_local-1; j++){          
            u_new[i][j] = 0.25*(u_old[i-1][j] + u_old[i+1][j] + u_old[i][j-1] + u_old[i][j+1] - dx*dy*f[i][j]);
        }
    }

    delete[] fromLeft;
    delete[] fromRight;
}
