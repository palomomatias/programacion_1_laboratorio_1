#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include"funciones.h"
#include"utn.h"
int main()
{
    ArrayList* listaPropietarios;
    listaPropietarios=al_newArrayList();
    ArrayList* listaBorrados;
    listaBorrados=al_newArrayList();
    parserRead(listaPropietarios);

    char seguir='s';
    int opcion=0;





    while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  alta \n");
        printf(" 2-  mostrar \n");
        printf(" 3-  baja \n");
        printf(" 4-  listar borrados\n");
        printf(" 5-  modificar\n");
        printf(" 6-  Salir\n");
        opcion=getValidInt("ingrese una opcion\n","error reingrese una opcion del 1 a 9\n",1,9);

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
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
