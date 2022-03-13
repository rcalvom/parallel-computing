#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int threads_num = 0;
double pi = 0;
double *pi_array;
long iterations = 0;

void *calc(void* ap){                                                       // Función que calcula una suma parcial del calculo de Pi.
    double pi_local  = 0;
    long countS = iterations / threads_num * (*(int*)ap) + 1;               // Teniendo en cuenta el número de hilo, calcula los limites de la sumatoria.
    long countE = iterations / threads_num * (*(int*)ap + 1) + 1;           
    for(long i = countS; i < countE;i++){                                   // Se calcula Pi usando los limites correspondientes al hilo.
        pi_local += (4.0) / (2 * i - 1);
        i++;
        pi_local -= (4.0) / (2 * i - 1);
    }
    *(pi_array + (*(int*)ap)) = pi_local;                                   // Se guarda el valor obtenido de la suma parcial en una posición de pi_array.
}


int main(int argc, char* argv[]){ 
    threads_num = atoi(argv[1]);                                            // Obtenemos el número de hilos a utilizar.
    iterations = atol(argv[2]);                                             // Obtenemos el número de iteraciones a realizar.
    pi_array = malloc(sizeof(double) * threads_num);                        // Se declara un espacio de memoria donde cada hilo almacenará una suma parcial.
    int data[threads_num];                                                  // Se declara un arreglo para indicarle a los hilos que parte de la suma van a realizar.
    pthread_t tfd[threads_num];                                             // Creamos el arreglo de hilos.
    for(int i = 0; i < threads_num; i++){
        data[i] = i;                                                
        pthread_create(&tfd[i], NULL, calc, &data[i]);                      // Se crean los hilos.
    }
    for(int i = 0; i < threads_num; i++){                                   // Se espera a que todos los hijos hayan terminado.
        pthread_join(tfd[i], NULL);
    }
    for(int i = 0; i < threads_num; i++){                                   // Se suman todas la sumas parciales en a variable Pi
        pi += *(pi_array + i);
    }
    printf("The calculated value of pi is: %1.12f\n\n", pi);                // Se imprime el valor obtenido en consola.      
    free(pi_array);                                                         // Se librera espacio de memoria ya no utilizado.
    return 0;
}