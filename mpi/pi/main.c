#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv){
    long iterations = 1000000000;
    long start, end;
    int rank, size;
    double local_pi, pi;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    local_pi = 0.0;
    start = iterations / size * rank + 1;
    end = iterations / size * (rank + 1) + 1;
    for (int i = start; i < end; i++){
        local_pi += (4.0) / (2 * i - 1);
        i++;
        local_pi -= (4.0) / (2 * i - 1);
    }
    MPI_Reduce(&local_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("pi is approximately %.12f", pi);
    }
    MPI_Finalize();
    return 0;
}