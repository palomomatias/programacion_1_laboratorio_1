#include <stdio.h>
#include <stdlib.h>
#include"propetarios.h"

int main()
{
 char seguir='s';
    int opcion=0;
    ePropetarios listaPropetario [tamPropetarios];
   inicializadorEstadoPropetario(listaPropetario,tamPropetarios);
    inicializadorHardcodeoPropetario(listaPropetario);
    mostrarPropetario(listaPropetario,tamPropetarios);

    while(seguir=='s')
    {
           do
    {

        printf("1-  Alta de PROPETARIO\n");
        printf("2-  MODIFICAR PROPETARIO\n");
        printf("3-  BAJA DEL PROTETARIO\n");
  //      printf("4-  PUBLICAR PRODUCTOS\n");
    //    printf("5-  MODIFICAR PUBLICACION\n");
     //   printf("6-  CANCELAR PUBLICACION\n");
       // printf("7-  COMPRAR PRODUCTO\n");
      //  printf("8-  LISTAR PUBLICACIONES DEL USUARIO\n");
       // printf("9-  LISTAR PUBLICACIONES\n");
     //   printf("10- LISTAR USUARIOS\n");
        printf("11- Salir\n");

                fflush(stdin);
        gets(auxiliar);


        }          while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
            altaPropetario(listaPropetario,tamPropetarios);


            break;
        case 2:
            modificarPropetario(listaPropetario,tamPropetarios);

            getch();
            break;
        case 3:
             darDebajaPropetario(listaPropetario,tamPropetarios);
            getch();// acordate que esto va en el case 2 solo estoy tessteando el mostrar personas;
            break;
        case 4:
            darDebajaPropetario(listaPropetario,tamPropetarios);
            break;
        case 5:
            ordenarPorNombre(listaPropetario,tamPropetarios);
            getch();
            break;
        case 6:
            mostrarPropetario(listaPropetario,tamPropetarios);
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
