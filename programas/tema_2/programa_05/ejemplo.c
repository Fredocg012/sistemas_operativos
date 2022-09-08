/*
    Correa González Alfredo
    Programa en c cuya jerrarquía de procesos sea de un proceso padre
    y un hijo. El proceso padre definirá un arreglo de cinco enteros y
    el hijo escribirá el menor del arreglo. 
    Ahora el padre imprimirá el valor menor.

*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {25, 17, 8, 40, 13};
    int pidH, valor;

    pidH = fork();
    if(pidH)
    {
        printf("Soy el padre \n");
        wait(&valor);   // Aquí espera a que termine el hijo su ejecución.
        printf("El valor minimo desde el padre es: %d \n", valor>>8);
    }
    else
    {
        int i, min = arr[0];
        
        for(i = 1; i<5; i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
        }   // Fin del for

        exit(min);  // Se lo pasa al padre
    }   // Fin del else 

    return 0;
}