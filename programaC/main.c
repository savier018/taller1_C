#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct Usuario usuarios[MAX_USUARIOS];
    struct Producto productos[MAX_PRODUCTOS];
    struct RegistroVenta ventas[MAX_PRODUCTOS];
  
    int numUsuarios = 0;
    int numProductos = 0;
    int numVentas = 0;
    
    cargarUsuarios(usuarios, &numUsuarios);
    cargarProductos(productos, &numProductos);
    cargarVentas(ventas, &numVentas);
  
    char usuario[20];
    char contraseña[20];

    printf("%s", "BIENVENIDO AL SISTEMA DE VENTA DE PRODUCTOS\n");
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", usuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", contraseña);
    printf("%s", "\n");

    int index = -1;
    for (int i = 0; i < numUsuarios; ++i) {
        if (strcmp(usuarios[i].username, usuario) == 0 && strcmp(usuarios[i].password, contraseña) == 0){
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Inicio de sesión exitoso.\n");
        printf("Bienvenido, %s.\n", usuario);

        if (strcmp(usuarios[index].rol, "Administrador") == 0) {
            printf("Usted es un Administrador.\n");
            printf("%s", "\n");
        } else if (strcmp(usuarios[index].rol, "Bodeguero") == 0) {
            printf("Usted es un Bodeguero.\n");
        } else if (strcmp(usuarios[index].rol, "Vendedor") == 0) {
            printf("Usted es un Vendedor.\n");
        } else {
            printf("Rol no reconocido.\n");
        }

        if (strcmp(usuarios[index].rol, "Administrador") == 0) {
            int opcion = 0;
            printf("%s", "Escoga una opción: \n");
            printf("1. Registrar nuevo usuario.\n");
            printf("2. Actualizar usuario.\n");
            printf("%s", "Opción: ");
            scanf("%d", &opcion);
            switch (opcion) {
              case 1:
                crearUsuario(usuarios, &numUsuarios);
              break;
              case 2:
                actualizarUsuarios(usuarios, numUsuarios);
              break;
            }            
        }

        if (strcmp(usuarios[index].rol, "Bodeguero") == 0) {
            int opcion = 0;
            printf("%s", "Escoga una opción: \n");
            printf("1. Registrar nuevo producto.\n");
            printf("2. Actualizar producto.\n");
            printf("%s", "Opción: ");
            scanf("%d", &opcion);
            switch (opcion) {
              case 1:
                crearProducto(productos, &numProductos);
              break;
              case 2:
                actualizarProductos(productos, numProductos);
              break;
            }            
        }

        if (strcmp(usuarios[index].rol, "Vendedor") == 0) {
            int opcion = 0;
            printf("%s", "Escoga una opción: \n");
            printf("1. Registrar nueva venta.\n");
            printf("%s", "Opción: ");
            scanf("%d", &opcion);
            switch (opcion) {
              case 1:
                venderProducto(ventas, &numVentas);
              break;
            }
    } else {
        printf("Inicio de sesión fallido. Usuario no encontrado.\n");
    }
    return 0;
  }
}

