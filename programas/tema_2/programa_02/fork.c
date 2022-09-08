/*
    Correa González Alfredo
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();       //fork() crea al proceso hijo

    if(pid != 0)
    {
        printf("Soy el padre\n");
        
    }
    else
    {
        printf("Soy el hijo\n");
    }

return 0;
}