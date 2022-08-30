// Crea un proceso
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    fork();         // Se crea un proceso hijo
    printf("Hola amigos");      // El printf lo escribe el padre y el hijo.
}