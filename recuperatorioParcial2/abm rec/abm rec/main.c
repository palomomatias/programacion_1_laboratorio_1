#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include"funciones.h"
int main()
{
     ArrayList* listaPropietarios;
    listaPropietarios=al_newArrayList();

     char seguir='s';
int opcion=0;





 while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  alta \n");
        printf(" 2-  mostrar \n");
       // printf(" 3-  Atender Tramite\n");
    //    printf(" 4-  Listar no  Atendidos\n");
   //     printf(" 5-  Listar Atendidos\n");
        printf(" 6-  Salir\n");
        pedirMensajeInt("ingrese una opcion",&opcion);

        switch(opcion)
        {
        case 1:
            alta(listaPropietarios);
break;
        case 2:
mostrarTodo(listaPropietarios);
            break;
        case 3:

            break;
        case 4:


            break;
        case 5:

            break;
        case 6:
            seguir = 'n';
            break;
        }
         system("pause");
system("cls");
}
return 0;
}
