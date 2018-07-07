#include <stdio.h>
#include <stdlib.h>
#include "parsaer.h"
int main()
{
ArrayList* empleado;
    ArrayList* filtro;
    empleado=al_newArrayList();
    parserRead(empleado);
    mostrarTodo(empleado);

    filtro=al_filter(empleado,funcionQueFiltra);
    if(filtro!=NULL&&filtro->len(filtro)>0)
    {
        mostrarTodo(filtro);
        parserWrite(filtro);
    }
    else
    {
        printf("\nNo hay empleados que cumplan los requisitos\n");
    }
return 0;
}
