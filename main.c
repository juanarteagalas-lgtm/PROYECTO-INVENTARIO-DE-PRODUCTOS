#include <stdio.h>
#include "funciones.h"

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

    } while(opcion != 8);

    return 0;
}