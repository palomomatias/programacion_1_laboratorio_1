#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tamUsuarios 100




int main()
{
 char seguir='s';
    int opcion=0;
    eUsuario listaUsuarios[tamUsuarios];
    inicializadorEstadoUsuario(listaUsuarios,tamUsuarios);
  //  inicializarUsuariosHardCode(listaUsuarios);

    while(seguir=='s')
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

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                                alta(listaUsuarios,tamUsuarios);

                break;
            case 2:
                mostrarPersonas(listaUsuarios,tamUsuarios);
                break;
            case 3:
                modificar(listaUsuarios,tamUsuarios);// acordate que esto va en el case 2 solo estoy tessteando el mostrar personas;
                break;
            case 4:
                darDebaja(listaUsuarios,tamUsuarios);
                break;
            case 5:
                ordenarPorNombre(listaUsuarios,tamUsuarios);
                break;
            case 6:
                break;
            case 7:
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

