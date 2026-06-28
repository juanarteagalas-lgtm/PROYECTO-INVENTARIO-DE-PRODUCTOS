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