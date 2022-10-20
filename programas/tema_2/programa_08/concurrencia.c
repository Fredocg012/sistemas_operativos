/* 
    Correa González Alfredo

    Muy parecido al programa de tarea
    un vector, un hilo encuentra el mínimo y el otro el promedio
*/
//No es recomendable poner en el for una variable global
// Para compilar: gcc concurrencia.c -lpthread

#include <pthread.h>
#include <stdio.h>

int vector[] = {23,15,42,3,72,38,12,91,57,64};

int elemMenor;
float promedio;
int I; // Para iterar los for. Mayúscula para ver que es global

void *calcula_elem_menor();
void *calcula_promedio();

int main()
{
    pthread_t hilo1, hilo2;
    // Se crean los dos hilos seguidos para que compitan por los recursos
    pthread_create(&hilo1, NULL, calcula_elem_menor, NULL);
    pthread_create(&hilo2, NULL, calcula_promedio, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("Elemento menor: %d \n", elemMenor);
    printf("El promedio es: %f \n", promedio);
}

void *calcula_elem_menor()
{
    elemMenor = vector[0];

    for(I = 0; I < 10; I++)
    {
        if(elemMenor > vector[I])
        {
            elemMenor = vector[I];
        }

        
    }

    pthread_exit(NULL);
}

void *calcula_promedio()
{
    int suma = 0;

    for(I = 0; I < 10; I++)
    {
        suma = suma + vector[I];
    }

    promedio = suma / 10;
    pthread_exit(NULL);

}











