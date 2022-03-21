#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdlib.h>

int threads_num = 0;
double pi = 0;
double* pi_array;
long iterations = 0;

void* calc(void* ap) {
    double pi_local = 0;
    long countS = iterations / threads_num * (*(int*)ap) + 1;
    long countE = iterations / threads_num * (*(int*)ap + 1) + 1;
    for (long i = countS; i < countE;i++) {
        pi_local += (4.0) / (2 * i - 1);
        i++;
        pi_local -= (4.0) / (2 * i - 1);
    }
    *(pi_array + (*(int*)ap)) = pi_local;
}


int main(int argc, char* argv[]) {
    struct timeval start;
    struct timeval end;
    double stopwatch;
    gettimeofday(&start, NULL);
    threads_num = atoi(argv[1]);
    iterations = atol(argv[2]);
    pi_array = malloc(sizeof(double) * threads_num);
    int data[threads_num];
    pthread_t tfd[threads_num];
    for (int i = 0; i < threads_num; i++) {
        data[i] = i;
        pthread_create(&tfd[i], NULL, calc, &data[i]);
    }
    for (int i = 0; i < threads_num; i++) {
        pthread_join(tfd[i], NULL);
    }
    for (int i = 0; i < threads_num; i++) {
        pi += *(pi_array + i);
    }
    gettimeofday(&end, NULL);
    stopwatch = (double)(end.tv_sec + (double)end.tv_usec / 1000000) - (double)(start.tv_sec + (double)start.tv_usec / 1000000);
    printf("The calculated value of pi is: %1.12f\n\n", pi);
    printf("The excecution of the program has taken: %.16g miliseconds.\n", stopwatch * 1000.0);
    free(pi_array);
    return 0;
}