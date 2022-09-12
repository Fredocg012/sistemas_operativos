/*
    Correa González Alfredo   Tarea_03   SO  Grupo: 5

    - Elaborar un programa en C que defina una jerrarquía de procesos padre
    y dos procesos hijo.
    
    - El proceso padre creará un arreglo de 10 elementos enteros cuyos valores
    estén en el rango de 0-255.

    - El primer proceso hijo calculará el elemento menor del arreglo y se lo enviará al padre.

    - El segundo proceso hijo calculará el elemento mayor del arreglo y se lo enviará al padre.

    - Finalmente el proceso padre escribirá los resutados.
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int arr[10] = {80,12,4,70,189,222,250,3,20,10};
    int pidH1, pidH2, valorMenor, valorMayor;


    if ( (pidH1=fork()) == 0 )
    { /* hijo 1*/
           
        int i, min = arr[0];
        
        for(i = 1; i<10; i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
        }

        exit(min);

    }
    else
    { /*  padre */
        if ( (pidH2=fork()) == 0 )
        { /* hijo 2  */
            
           int i, max = arr[0];
        
            for(i = 1; i<10; i++)
            {
                if(max < arr[i])
                {
                    max = arr[i];
                }
            }
            exit(max);

            
        }


        else
        { /* padre */
/* Esperamos al primer hijo */
            wait(&valorMenor);
/* Esperamos al segundo hijo */
            wait(&valorMayor);
            printf(" Soy el padre e imprimo el:\n Valor mayor: %d \n Valor menor: %d \n", valorMayor>>8, valorMenor>>8);
        }
    }

    return 0;
}