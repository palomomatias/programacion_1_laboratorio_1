#include <stdio.h>
#include <stdlib.h>
#include "productos.h"
char auxiliar[50];
int main()
{

    eProducto listaProductos[tamProductos];
    inicializadorEstadoProducto(listaProductos,tamProductos);
 char seguir='s';
    int opcion=0;
     while(seguir=='s')
    {
           do
    {
        printf("1-  Alta de usuario\n");
        printf("2-  MODIFICAR DATOS DEL USUARIO\n");
        printf("3-  BAJA DEL USUARIO\n");
        printf("4-  PUBLICAR PRODUCTOS\n");
        printf("5-  MODIFICAR PUBLICACION\n");
        printf("6-  CANCELAR PUBLICACION\n");
        printf("7-  COMPRAR PRODUCTO\n");
        printf("8-  LISTAR PUBLICACIONES DEL USUARIO\n");
        printf("9-  LISTAR PUBLICACIONES\n");
        printf("10- LISTAR USUARIOS\n");
        printf("11- Salir\n");

                fflush(stdin);
        gets(auxiliar);


        }          while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
            altaProducto(listaProductos,tamProductos);

            break;
        case 2:
       modificarProducto(listaProductos,tamProductos);
            break;
        case 3:

            getch();// acordate que esto va en el case 2 solo estoy tessteando el mostrar personas;
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            break;
        case 7:
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("cls");
    }
    return 0;
}
