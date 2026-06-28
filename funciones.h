#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 100

typedef struct
{
    char codigo[16];
    char nombre[50];
    char categoria[30];
    float precio_compra;
    float precio_venta;
    int cantidad;
} Producto;

void mostrarMenu();

void registrarProducto(Producto inventario[], int *total);
int codigoExiste(Producto inventario[], int total, char codigo[]);

float calcularUtilidad(Producto p);
void listarProductos(Producto inventario[], int total);
void buscarProducto(Producto inventario[], int total);

#endif