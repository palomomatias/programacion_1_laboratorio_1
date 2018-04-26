#include "localidad.h"
void loc_MostrarUno(eLocalidad aux)
{
    printf("\nid:%d localidad:%s",aux.id,aux.nombreLocalidad);
}

void loc_MostrarListado(eLocalidad listado [],int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
       // printf("\n%s",listado[i].nombreLocalidad);
       loc_MostrarUno(listado[i]);
    }
}
