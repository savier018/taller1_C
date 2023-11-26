#include <stdio.h>
#include <string.h>
#include "funciones.h"

#include <stdio.h>
#include <string.h>
#include "funciones.h"

void crearUsuario(struct Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios >= MAX_USUARIOS) {
        printf("Se alcanzó el límite máximo de usuarios. No se pueden agregar más usuarios.\n");
        return;
    }

    printf("Ingrese el nuevo usuario:\n");

    printf("Rol (Administrador/Bodeguero/Vendedor): ");
    scanf("%19s", usuarios[*numUsuarios].rol);

    printf("Usuario: ");
    scanf("%19s", usuarios[*numUsuarios].username);

    printf("Contraseña: ");
    scanf("%19s", usuarios[*numUsuarios].password);

    (*numUsuarios)++;
    actualizarArchivoUsuarios(usuarios, *numUsuarios);
}

void actualizarArchivoUsuarios(struct Usuario usuarios[], int numUsuarios) {
    FILE *archivo;
    archivo = fopen("usuarios.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios para actualizar.\n");
        return;
    }

    for (int i = 0; i < numUsuarios; ++i) {
        fprintf(archivo, "%s %s %s\n", usuarios[i].rol, usuarios[i].username, usuarios[i].password);
    }

    fclose(archivo);
}

void actualizarUsuarios(struct Usuario usuarios[], int numUsuarios) {
    FILE *archivo;
    archivo = fopen("usuarios.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios para actualizar.\n");
        return;
    }

    char nombreUsuario[20];
    printf("Ingrese el nombre de usuario que desea actualizar: ");
    scanf("%19s", nombreUsuario);

    int encontrado = 0;

    for (int i = 0; i < numUsuarios; ++i) {
        if (strcmp(usuarios[i].username, nombreUsuario) == 0) {
            encontrado = 1;
            printf("Usuario encontrado:\n");
            printf("Rol: %s\n", usuarios[i].rol);
            printf("Username: %s\n", usuarios[i].username);
            printf("Password: %s\n", usuarios[i].password);

            printf("¿Desea cambiar el nombre de usuario? (S/N): ");
            char opcion;
            scanf(" %c", &opcion);  

            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese el nuevo nombre de usuario: ");
                scanf("%19s", usuarios[i].username);
            }

            printf("¿Desea cambiar la contraseña? (S/N): ");
            scanf(" %c", &opcion);

            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese la nueva contraseña: ");
                scanf("%19s", usuarios[i].password);
            }
        }

        fprintf(archivo, "%s %s %s\n", usuarios[i].rol, usuarios[i].username, usuarios[i].password);
    }

    fclose(archivo);

    if (!encontrado) {
        printf("Usuario no encontrado.\n");
    }
}

void cargarUsuarios(struct Usuario usuarios[], int *numUsuarios) {
    FILE *archivo;
    archivo = fopen("usuarios.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%19s %19s %19s", usuarios[*numUsuarios].rol, usuarios[*numUsuarios].username, usuarios[*numUsuarios].password) == 3) {
            (*numUsuarios)++;
            if (*numUsuarios >= MAX_USUARIOS) {
                printf("Se alcanzó el límite máximo de usuarios.\n");
                break;
            }
        }
    }

    fclose(archivo);
}

void crearProducto(struct Producto productos[], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("Se alcanzó el límite máximo de productos. No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nuevo producto:\n");

    printf("Nombre: ");
    scanf("%49s", productos[*numProductos].nombre);

    printf("Categoría: ");
    scanf("%49s", productos[*numProductos].categoria);

    printf("Marca: ");
    scanf("%49s", productos[*numProductos].marca);

    printf("Código: ");
    scanf("%d", &productos[*numProductos].codigo);

    printf("Precio de Compra: ");
    scanf("%f", &productos[*numProductos].precioCompra);

    printf("Bodega: ");
    scanf("%49s", productos[*numProductos].bodega);

    (*numProductos)++;

    actualizarArchivoProductos(productos, *numProductos);
}

void actualizarArchivoProductos(struct Producto productos[], int numProductos) {
    FILE *archivo;
    archivo = fopen("productos.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de productos para actualizar.\n");
        return;
    }

    for (int i = 0; i < numProductos; ++i) {
        fprintf(archivo, "%s %s %s %d %.2f %s\n", productos[i].nombre,
                                                  productos[i].categoria,
                                                  productos[i].marca,
                                                  productos[i].codigo,
                                                  productos[i].precioCompra,
                                                  productos[i].bodega);
    }

    fclose(archivo);
}

void actualizarProductos(struct Producto productos[], int numProductos) {
    FILE *archivo;
    archivo = fopen("productos.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de productos para actualizar.\n");
        return;
    }

    int codigoProducto;
    printf("Ingrese el código del producto que desea actualizar: ");
    scanf("%d", &codigoProducto);

    int encontrado = 0;

    for (int i = 0; i < numProductos; ++i) {
        if (productos[i].codigo == codigoProducto) {
            encontrado = 1;
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Categoría: %s\n", productos[i].categoria);
            printf("Marca: %s\n", productos[i].marca);
            printf("Código: %d\n", productos[i].codigo);
            printf("Precio de Compra: %.2f\n", productos[i].precioCompra);
            printf("Bodega: %s\n", productos[i].bodega);

            printf("¿Desea cambiar el nombre? (S/N): ");
            char opcion;
            scanf(" %c", &opcion); 

            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese el nuevo nombre: ");
                scanf("%49s", productos[i].nombre);
            }

            printf("¿Desea cambiar la categoría? (S/N): ");
            scanf(" %c", &opcion);

            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese la nueva categoría: ");
                scanf("%49s", productos[i].categoria);
            }

            printf("¿Desea cambiar la marca? (S/N): ");
            scanf(" %c", &opcion);
          
            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese la nueva marca: ");
                scanf("%49s", productos[i].marca);
            }

            printf("¿Desea cambiar el código? (S/N): ");
            scanf(" %c", &opcion);

            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese el nuevo código: ");
                scanf("%d", &productos[i].codigo);
            }

            printf("¿Desea cambiar el precio de compra? (S/N): ");
            scanf(" %c", &opcion);
          
            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese el nuevo precio de compra: ");
                scanf("%f", &productos[i].precioCompra);
            }

            printf("¿Desea cambiar la bodega? (S/N): ");
            scanf(" %c", &opcion);
          
            if (opcion == 'S' || opcion == 's') {
                printf("Ingrese la nueva bodega: ");
                scanf("%49s", productos[i].bodega);
            }

        }

        fprintf(archivo, "%s %s %s %d %.2f %s\n", productos[i].nombre,
                                                  productos[i].categoria,
                                                  productos[i].marca,
                                                  productos[i].codigo,
                                                  productos[i].precioCompra,
                                                  productos[i].bodega);
    }

    fclose(archivo);

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void cargarProductos(struct Producto productos[], int *numProductos) {
    FILE *archivo;
    archivo = fopen("productos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de productos.\n");
        return;
    }

    while (fscanf(archivo, "%49s %49s %49s %*[^0-9]%d %f %49s", productos[*numProductos].nombre,
                                                               productos[*numProductos].categoria,
                                                               productos[*numProductos].marca,
                                                               &productos[*numProductos].codigo,
                                                               &productos[*numProductos].precioCompra,
                                                               productos[*numProductos].bodega) == 6) {
        (*numProductos)++;
        if (*numProductos >= MAX_PRODUCTOS) {
            printf("Se alcanzó el límite máximo de productos.\n");
            break;
        }
    }

    fclose(archivo);
}

void cargarVentas(struct RegistroVenta ventas[], int *numVentas) {
    FILE *archivo;
    archivo = fopen("registroVentas.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de ventas.\n");
        return;
    }

    while (fscanf(archivo, "%49s %49s %19s %f %d", ventas[*numVentas].local,
                                                  ventas[*numVentas].vendedor,
                                                  ventas[*numVentas].fechaVenta,
                                                  &ventas[*numVentas].precioVenta,
                                                  &ventas[*numVentas].cantidad) == 5) {
        (*numVentas)++;
        if (*numVentas >= MAX_VENTAS) {
            printf("Se alcanzó el límite máximo de ventas.\n");
            break;
        }
    }

    fclose(archivo);
}

void venderProducto(struct RegistroVenta ventas[], int *numVentas) {
    char local[50];
    char vendedor[50];
    char fechaVenta[20];
    float precioVenta;
    int cantidad;

    printf("Ingrese el local: ");
    scanf("%49s", local);

    printf("Ingrese el vendedor: ");
    scanf("%49s", vendedor);

    printf("Ingrese la fecha de venta (YYYY-MM-DD): ");
    scanf("%19s", fechaVenta);

    printf("Ingrese el precio de venta: ");
    scanf("%f", &precioVenta);

    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &cantidad);

    printf("%d", ventas[1].cantidad);

    struct RegistroVenta nuevaVenta;
    strcpy(nuevaVenta.local, local);
    for (int i = 0; i < *numVentas; ++i) {
        if (strcmp(ventas[i].local, local) == 0){
          int nuevaCantidad = ventas[i].cantidad - cantidad;
          printf("%d", nuevaCantidad);
          nuevaVenta.cantidad = nuevaCantidad;
          break;
        }
    }
    strcpy(nuevaVenta.vendedor, vendedor);
    strcpy(nuevaVenta.fechaVenta, fechaVenta);
    nuevaVenta.precioVenta = precioVenta;

    ventas[*numVentas] = nuevaVenta;
    (*numVentas)++;

    actualizarArchivoVentas(ventas, *numVentas);

    printf("Venta registrada con éxito.\n");
}

void actualizarArchivoVentas(struct RegistroVenta ventas[], int numVentas) {
    FILE *archivo;
    archivo = fopen("registroVentas.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de ventas para actualizar.\n");
        return;
    }

    for (int i = 0; i < numVentas; ++i) {
        fprintf(archivo, "%s %s %s %.2f %d\n", ventas[i].local,
                                               ventas[i].vendedor,
                                               ventas[i].fechaVenta,
                                               ventas[i].precioVenta,
                                               ventas[i].cantidad);
    }

    fclose(archivo);
}





