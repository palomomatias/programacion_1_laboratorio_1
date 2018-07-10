#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include"funciones.h"
#include"utn.h"
#include "nuevoAlquiler.h"
#include"alquilar.h"
int main()
{
    ArrayList* listaPropietarios;
    listaPropietarios=al_newArrayList();
    ArrayList* listaBorrados;
    listaBorrados=al_newArrayList();
    ArrayList* alquiler;
    alquiler=al_newArrayList();
    ArrayList* alquilado;
    alquilado=al_newArrayList();
    parserRead(listaPropietarios);
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {

        al_sort(listaPropietarios,compareid,1);
        printf("\n");
        printf(" 1-  alta \n");
        printf(" 2-  mostrar \n");
        printf(" 3-  baja \n");
        printf(" 4-  listar borrados\n");
        printf(" 5-  modificar\n");
        printf(" 6-  ordenar por dni\n");
        printf(" 7-  alquilar\n");
        printf(" 8-  mostrar alquilados\n");
        printf(" 9-  Salir\n");
        opcion=getValidInt("ingrese una opcion\n","error reingrese una opcion del 1 a 9\n",1,15);

        switch(opcion)
        {
        case 1:
            alta(listaPropietarios,listaBorrados);
            parserWrite(listaPropietarios);
            break;
        case 2:
            mostrarTodo(listaPropietarios);
            break;
        case 3:
            baja(listaPropietarios,listaBorrados);
            break;
        case 4:
            mostrarTodo(listaBorrados);


            break;
        case 5:
            modificar(listaPropietarios);
            break;
        case 6:

            al_sort(listaPropietarios,compararInt,1);
            mostrarTodo(listaPropietarios);
            break;
        case 7:
            altaAlquiler(alquiler,alquilado,listaPropietarios);

            break;

        case 8:
            if(!alquiler->isEmpty(alquiler))
            {


                mostrarAlquiler(alquiler,listaPropietarios);
            }
            else
            {
                printf("no hay nada alquilado\n");
            }
            break;
        case 9:
            if(!alquiler->isEmpty(alquiler))
            {
                terminarAlquiler(alquiler,alquilado,listaPropietarios);
            }
            else
            {
                printf("necesita tener alguien alquilando para entrar a este menu");
                getch();
            }
            break;
        case 10:

            if(!alquilado->isEmpty(alquilado))
            {
                mostrarTodoTest(alquilado);
            }
            else
            {
                printf("no hay nada para mostrar");
                getch();
            }

            break;
        case 11:
            seguir = 'n';
            break;

        }
        system("pause");
        system("cls");
    }
    return 0;
}
