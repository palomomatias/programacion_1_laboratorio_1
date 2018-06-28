#include <stdio.h>
#include <stdlib.h>
#include"ArrayList.h"
#include"funciones.h"

int main()
{

      char seguir='s';
int opcion=0;
char auxiliar[55];
    ArrayList* pendientesUrgente;
  ArrayList* pendientesRegular;
  ArrayList* atendidosUrgente;
  ArrayList* atendidosRegular;
  eTramite* tramite;

  pendientesUrgente=al_newArrayList();
  pendientesRegular=al_newArrayList();
  atendidosUrgente=al_newArrayList();
atendidosRegular=al_newArrayList();




 while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  Turno Urgente\n");
        printf(" 2-  Turno Regular\n");
        printf(" 3-  Atender Tramite\n");
        printf(" 4-  Listar no  Atendidos\n");
        printf(" 5-  Listar Atendidos\n");
        printf(" 6-  Salir\n");
        pedirMensaje("elija una opcion\n",auxiliar);
        validar_numero(auxiliar);
        opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
cargarTramite(pendientesUrgente);
printf("Turno urgente cargado\n");
break;
            break;
        case 2:
            cargarTramite(pendientesRegular);
printf("Turno regular cargado\n");
            break;
        case 3:
             if(!pendientesUrgente->isEmpty(pendientesUrgente))
        {
            printf("Cliente urgente atendido:\n");
            atenderTramite(pendientesUrgente,atendidosUrgente);
        }
        else
        {
             if(!pendientesRegular->isEmpty(pendientesRegular))
              {
               printf("Cliente a ser atendido (REGULAR):");
               atenderTramite(pendientesRegular,atendidosRegular);
              }
              else
              {
                  printf("No hay usuarios para mostrar\n");
              }

        }

            break;
        case 4:
             if(!pendientesUrgente->isEmpty(pendientesUrgente))
         {
          printf("\tturnos urgentes\n");

          mostrarTramites(pendientesUrgente);
         }
       if(!pendientesUrgente->isEmpty(pendientesRegular))
        {
          printf("\tturnos regulares\n");

         mostrarTramites(pendientesRegular);
        }

            break;
        case 5:
                 if(!atendidosUrgente->isEmpty(atendidosUrgente))
         {
           atendidosUrgente->sort(atendidosUrgente,compararInt,1);

           printf("\nTramites urgentes\n");

           mostrarTramites(atendidosUrgente);
         }

       if(!atendidosRegular->isEmpty(atendidosRegular))
       {

          atendidosRegular->sort(atendidosRegular,compararInt,1);

          printf("\nTramites regulares\n");

          mostrarTramites(atendidosRegular);
}
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
