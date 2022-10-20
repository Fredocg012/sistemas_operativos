// Variable I como global para ser compartida por los dos hilos secundarios.

#include <pthread.h>
#include <stdio.h>

int vector[]= {23,15,42,3,72,38,12,91,57,64}; /* vector como variable global */
int elemMenor;/* variable global para obtener el resultado del hilo 1 */
float promedio; /* variable global para obtener el resultado del hilo 2 */
int I; ;/*variable global para usarla en los hilos secundarios dentro del for correspondiente*/

void *calcula_elem_menor( ); /* prototipo de la función del hilo 1 */
void *calcula_promedio( );/* prototipo de la función del hilo 2 */

int main()

{

    pthread_t hilo1, hilo2; /* se declaran los identificadores de los hilos*/
    int error;

    error = pthread_create(&hilo1,NULL,calcula_elem_menor,NULL); /* se crea el hilo 1, no se envia argumento*/
    error = pthread_create(&hilo2,NULL,calcula_promedio, NULL); /* se crea el hilo 2, no se envia argumento */

    error = pthread_join(hilo1, NULL); /* se espera a que termine el hilo 1 */
    error = pthread_join(hilo2,NULL); /* se espera a que termine el hilo 2 */

    printf("Hilo 1 terminado, menor = %d\n",elemMenor); /* Se escribe el resultado del hilo 1 */
    printf("Hilo 2 terminado, promedio = %f\n", promedio); /* Se escribe el resultado del hilo 2 */

}   

// Calcula el elemento menor usando directamente la varible global I

void *calcula_elem_menor() // No recibe argumento
{
    elemMenor = vector[0];
    for(I = 1; I < 10; I ++)
    {
        if(elemMenor > vector[I])
        {
            elemMenor = vector[I];
        }
    }
    pthread_exit(NULL);

    return 0;
}

// Se calcula el promedio usando directamente la variable global I

void *calcula_promedio() // No recibe argumento
{
    int suma = 0;

    for(I = 0; I < 10; I++)
    {
        suma += vector[I]; 
    }

    promedio = suma / 10.0;
    pthread_exit(NULL);
}





