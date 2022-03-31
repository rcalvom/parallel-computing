#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    struct timeval start;
    struct timeval end;
    double stopwatch;
    gettimeofday(&start, NULL);

    int threads_num = atoi(argv[1]);
    long iterations = atol(argv[2]);
    double pi = 0.0;
    #pragma omp parallel for num_threads(threads_num) reduction(+:pi)
    for (long i = 1; i <= iterations; i++) {
        pi += (4.0 * (i % 2 == 0 ? -1 : 1))/ (2 * i - 1);
    }
    gettimeofday(&end, NULL);
    stopwatch = (double)(end.tv_sec + (double)end.tv_usec / 1000000) - (double)(start.tv_sec + (double)start.tv_usec / 1000000);
    printf("The calculated value of pi is: %1.12f\n\n", pi);
    printf("The excecution of the program has taken: %.16g miliseconds.\n", stopwatch * 1000.0);
    return 0;
}