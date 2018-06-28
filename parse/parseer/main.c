#include <stdio.h>
#include <stdlib.h>
#include"ArrayList.h"
#include"parser.h"

int main()
{

      char seguir='s';
int opcion=0;
char auxiliar[55];
    ArrayList* destinatario;
  ArrayList* black_list;
  ArrayList* depurado;
  destinatario=al_newArrayList();
  black_list=al_newArrayList();
depurado=al_newArrayList();




 while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  CARGAR DESTINATARIOS\n");
        printf(" 2-  CARGAR BLACKLIST\n");
        printf(" 3-  DEPURAR \n");
        printf(" 4-  Listar \n");
        printf(" 5-  Salir\n");
        pedirMensaje("elija una opcion\n",auxiliar);
        validar_numero(auxiliar);
        opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:

parserRead("destinatarios.csv",destinatario);
            break;
        case 2:
   parserRead("black_list.csv",black_list);
            break;
        case 3:
             depurar(destinatario,black_list,depurado);
            break;
        case 4:
           printf("nombre\t  mail\t");
           listar(depurado);

            break;

        case 5:
            seguir = 'n';
            break;
        }
         system("pause");
system("cls");
 }
    return 0;
}
