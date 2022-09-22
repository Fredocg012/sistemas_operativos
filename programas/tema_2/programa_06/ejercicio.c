/*
    Correa González Alfredo

    -   Elaborar un programa en c con llamadas al sistema que resuelva
        el siguiente problema:

        - Calcular el promedio de los elementos de un arreglo utilizando procesamiento
          concurrente.
        
        Descripción:

        - El arreglo será de 100 elementos enteros cuyo valor debe estar en el rango del
          1 al 12.

        - Número de procesos hijo: 5.

        - El proceso padre, antes de crear a los cinco hijos generará un arreglo aleatorio
          de los cien elementos (Usar la función rand()).

        - Cada proceso hijo sumará veinte elementos del arreglo y el resultado se los enviarán 
          al proceso padre.
        
        - El proceso padre hará la suma total y calculara el promedio.

        - Finalmente lo mostrará.
    
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 100
#define NH 5

int V[100];

void suma(int identh)
{
    int i, sum = 0;
    int N_elem = N/NH;
    int limInf = identh * N_elem;
    

    for (i = limInf; i < limInf + N_elem; i++)
    {
        sum += V[i]; 
    }

    exit(sum);
}

int main()
{

    int pidh[NH];
    int idh[NH], i;
    int sumaP;
    float sumaT;
    


    
    for(i = 0; i < N; i++)
    {
        V[i] = rand()%12+1;

    }
   
    for(i = 0; i <NH; i++)
    {
        pidh[i] = fork();
        
        if(pidh[i] == 0)
        {
            idh[i] = i;
            suma(idh[i]);
        }
    }

    for(i = 0; i < NH; i++)
    {
        wait(&sumaP);
        sumaT += sumaP >> 8;
    }

    printf("El promedio desde el padre es: %f \n", sumaT);

    return 0;
}


/*
int numero_Aleatorio = r() %12and+1;
    printf("%d \n", numero_Aleatorio);

    */