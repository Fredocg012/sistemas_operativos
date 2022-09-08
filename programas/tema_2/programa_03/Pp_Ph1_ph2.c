/*
    Correa González Alfredo
    Crear un proceso padre con dos procesos hijos

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pidH1, pidH2;

    pidH1 = fork();
    if(pidH1)
    {
        pidH2 = fork();
        if(pidH2)
        {
            printf("Soy el padre y tengo dos hijos \n");
            printf("Sus pid son: %d y %d \n", pidH1, pidH2);
        }
        else
        {
            printf("Soy el hijo 2 y el pid es: %d \n", getpid());
        }
    }
    else
    {
        printf("Soy el hijo uno y mi pid es: %d \n", getpid());
    }

    return 0;
}