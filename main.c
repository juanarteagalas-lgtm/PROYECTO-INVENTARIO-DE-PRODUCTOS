#include <stdio.h>
#include "funciones.h"

int main()
{
    Producto inventario[MAX_PRODUCTOS];
    int total = 0;
    int opcion;

    do
    {
        mostrarMenu();

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
          case 1:
        registrarProducto(inventario, &total);
        break;

    case 2:
        listarProductos(inventario, total);
        break;

    case 3:
        buscarProducto(inventario, total);
        break;

    case 8:
        printf("Saliendo...\n");
        break;

    default:
        printf("Opcion no disponible aun.\n");
        }

    } while(opcion != 8);

    return 0;
}