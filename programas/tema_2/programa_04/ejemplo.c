/*
    Correa González Alfredo
    Programa en c cuya jerrarquía de procesos sea de un proceso padre
    y un hijo. El proceso padre definirá un arreglo de cinco enteros y
    el hijo escribirá el menor del arreglo.
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int arr[5] = {25, 17, 8, 40, 13};
    int pidH;

    pidH = fork();
    if(pidH)
    {
        printf("Soy el padre \n");
        arr[3] = 1; // Solo se modifica en el arreglod el padre.
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

        printf("El menor es: %d \n", min);
    }   // Fin del else 

    return 0;
}