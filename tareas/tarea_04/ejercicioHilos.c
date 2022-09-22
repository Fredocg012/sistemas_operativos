/* Correa González Alfredo

 El hilo principal debe crear dos hilos secundarios
    - El hilo secundario 1 obtendrá el mínimo de un arreglo.
    - El hilo secundario 2 obtendrá el máximo de un arreglo.
    - Los valores del arreglo los definirá el hilo principal
      y están en un rango de 0 a 1000 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int vector[100], min, max;

void *codigo_hilo1(void *num_hilo)  // Esta función solo puede tener un argumento.
{
    int i;
    min = vector[0];
    for(i = 0; i < 100; i++)
    {
        if(min > vector[i])
        {
            min = vector[i];
        }

    }

    printf("El valor recibido en el argumento es: %d \n", *(int *)num_hilo); // Apuntador a entero
    pthread_exit(NULL);
}

void *codigo_hilo2(void *num_hilo)  // Esta función solo puede tener un argumento.
{
    int i; 
    max = vector[0];
    for(i = 0; i < 100; i++)
    {
        if(max < vector[i])
        {
            max = vector[i];
        }

    }

    printf("El valor recibido en el argumento es: %d \n", *(int *)num_hilo); // Apuntador a entero
    pthread_exit(NULL);
}


int main()
{
    pthread_t hilo1, hilo2;     //Variables de tipo hilo
    int i, error, valorHilo;

    for(i = 0; i < 100; i++)
    {
        vector[i] = rand()%1001;
    }

   

    valorHilo = 1;
    error = pthread_create(&hilo1, NULL, codigo_hilo1, &valorHilo );  //(hilo, variables, función a ejecutar, argumento de la función a ejecutar)
    error = pthread_create(&hilo2, NULL, codigo_hilo2, &valorHilo );
    error = pthread_join(hilo1,NULL);   // Equivalente al wait  
    
    if(error ==1)
    {
        return(1);
    }

    error = pthread_join(hilo2,NULL);   // Equivalente al wait  

    if(error ==1)
    {
        return(1);
    }

    
    printf("Valor minimo: %d \nValor maximo: %d \n", min, max);
    
    return 0;  
}

