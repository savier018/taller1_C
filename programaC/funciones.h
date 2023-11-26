#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 50
#define MAX_USUARIOS 10
#define MAX_VENTAS 50

struct Producto {
    float precioCompra;
    int codigo; 
    char nombre[50];
    char categoria[50];
    char marca[50]; 
    char bodega[50];
};

struct RegistroVenta{
    float precioVenta;
    int cantidad;
    char local[50];
    char vendedor[50];
    char fechaVenta[20];
};

struct Usuario{
    char username[20];
    char password[20];
    char rol[20];
};

void crearUsuario(struct Usuario usuarios[], int *numUsuarios);
void cargarUsuarios(struct Usuario usuarios[], int *numUsuarios);
void actualizarUsuarios(struct Usuario usuarios[], int numUsuarios);
void actualizarArchivoUsuarios(struct Usuario usuarios[], int numUsuarios);

void crearProducto(struct Producto productos[], int *numProductos);
void cargarProductos(struct Producto productos[], int *numProductos);
void actualizarProductos(struct Producto productos[], int numProductos);
void actualizarArchivoProductos(struct Producto productos[], int numProductos);

void cargarVentas(struct RegistroVenta ventas[], int *numVentas);
void actualizarArchivoVentas(struct RegistroVenta ventas[], int numVentas);
void venderProducto(struct RegistroVenta ventas[], int *numVentas);


#endif
