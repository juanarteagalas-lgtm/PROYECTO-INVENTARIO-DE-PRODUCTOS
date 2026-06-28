#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    printf("\n===== INVENTARIO =====\n");
    printf("1. Registrar producto\n");
    printf("2. Listar productos\n");
    printf("3. Buscar producto\n");
    printf("4. Actualizar producto\n");
    printf("5. Eliminar producto\n");
    printf("6. Utilidad total\n");
    printf("7. Guardar archivo\n");
    printf("8. Salir\n");
}

int codigoExiste(Producto inventario[], int total, char codigo[])
{
    for(int i = 0; i < total; i++)
    {
        if(strcmp(inventario[i].codigo, codigo) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void registrarProducto(Producto inventario[], int *total)
{
    if(*total >= MAX_PRODUCTOS)
    {
        printf("Inventario lleno.\n");
        return;
    }

    Producto nuevo;

    printf("\n=== REGISTRO DE PRODUCTO ===\n");

    do
    {
        printf("Codigo: ");
        scanf("%15s", nuevo.codigo);

        if(codigoExiste(inventario, *total, nuevo.codigo))
        {
            printf("ERROR: Codigo ya existente.\n");
        }

    } while(codigoExiste(inventario, *total, nuevo.codigo));

    printf("Nombre: ");
    scanf(" %49[^\n]", nuevo.nombre);

    printf("Categoria: ");
    scanf(" %29[^\n]", nuevo.categoria);

    do
    {
        printf("Precio de compra: ");
        scanf("%f", &nuevo.precio_compra);

        if(nuevo.precio_compra <= 0)
        {
            printf("ERROR: Debe ser mayor que 0.\n");
        }

    } while(nuevo.precio_compra <= 0);

    do
    {
        printf("Precio de venta: ");
        scanf("%f", &nuevo.precio_venta);

        if(nuevo.precio_venta <= nuevo.precio_compra)
        {
            printf("ERROR: Debe ser mayor al precio de compra.\n");
        }

    } while(nuevo.precio_venta <= nuevo.precio_compra);

    do
    {
        printf("Cantidad: ");
        scanf("%d", &nuevo.cantidad);

        if(nuevo.cantidad < 0)
        {
            printf("ERROR: No puede ser negativa.\n");
        }

    } while(nuevo.cantidad < 0);

    inventario[*total] = nuevo;
    (*total)++;

    printf("Producto registrado correctamente.\n");
}

float calcularUtilidad(Producto p)
{
    return (p.precio_venta - p.precio_compra) * p.cantidad;
}

void listarProductos(Producto inventario[], int total)
{
    if(total == 0)
    {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    printf("\n================ INVENTARIO ================\n");

    printf("%-10s %-20s %-15s %-10s %-10s %-10s %-10s\n",
           "CODIGO",
           "NOMBRE",
           "CATEGORIA",
           "COMPRA",
           "VENTA",
           "CANTIDAD",
           "UTILIDAD");

    for(int i = 0; i < total; i++)
    {
        printf("%-10s %-20s %-15s %-10.2f %-10.2f %-10d %-10.2f\n",
               inventario[i].codigo,
               inventario[i].nombre,
               inventario[i].categoria,
               inventario[i].precio_compra,
               inventario[i].precio_venta,
               inventario[i].cantidad,
               calcularUtilidad(inventario[i]));
    }
}

void buscarProducto(Producto inventario[], int total)
{
    int opcion;
    int encontrado = 0;

    printf("\n=== BUSCAR PRODUCTO ===\n");
    printf("1. Buscar por codigo\n");
    printf("2. Buscar por nombre\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if(opcion == 1)
    {
        char codigo[16];

        printf("Ingrese el codigo: ");
        scanf("%15s", codigo);

        for(int i = 0; i < total; i++)
        {
            if(strcmp(inventario[i].codigo, codigo) == 0)
            {
                printf("\nProducto encontrado\n");

                printf("Codigo: %s\n", inventario[i].codigo);
                printf("Nombre: %s\n", inventario[i].nombre);
                printf("Categoria: %s\n", inventario[i].categoria);
                printf("Precio compra: %.2f\n", inventario[i].precio_compra);
                printf("Precio venta: %.2f\n", inventario[i].precio_venta);
                printf("Cantidad: %d\n", inventario[i].cantidad);
                printf("Utilidad: %.2f\n",
                       calcularUtilidad(inventario[i]));

                encontrado = 1;
                break;
            }
        }
    }
    else if(opcion == 2)
    {
        char nombre[50];

        printf("Ingrese parte del nombre: ");
        scanf(" %49[^\n]", nombre);

        for(int i = 0; i < total; i++)
        {
            if(strstr(inventario[i].nombre, nombre) != NULL)
            {
                printf("\nCodigo: %s\n", inventario[i].codigo);
                printf("Nombre: %s\n", inventario[i].nombre);
                printf("Categoria: %s\n", inventario[i].categoria);
                printf("Precio compra: %.2f\n", inventario[i].precio_compra);
                printf("Precio venta: %.2f\n", inventario[i].precio_venta);
                printf("Cantidad: %d\n", inventario[i].cantidad);
                printf("Utilidad: %.2f\n",
                       calcularUtilidad(inventario[i]));

                encontrado = 1;
            }
        }
    }

    if(!encontrado)
    {
        printf("\nProducto no encontrado.\n");
    }
}