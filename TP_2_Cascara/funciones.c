#include "funciones.h"
int obtenerEspacioLibre(EPersona lista[], TAM)
{
    int i;
    int index=-1;
    for (i=0;i<TAM;i++)
    {
        if (lista[i].dni==0)
        {
          index=i;
          break;
        }
    }

    return index;
}

void inicializarEstado(EPersona estados[], int TAM)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        estados[i].estado = 0;
    }
}



int buscarPorDni(EPersona lista[], int dni,int TAM)
{
    int i;
    printf("ingrese el dni que quiere buscar");
    scanf("%d",dni);
    for(i=0,i<TAM;i++)
    {
        if(dni==lista[i].dni)
        {
            printf("DNI: %d NOMBRE : %s EDAD: %d",lista[i].dni,lista[i].nombre,lista[i].edad);
        }
        else
        {
            printf("error no existe ese dni reingrese");
        }
    }



}

void mostrarPersonas (EPersona mostrar [],int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(mostrar[i].estado!=0)
                {
                    printf("DNI:%d EDAD:%d NOMBRE: %s "mostrar[i].dni,mostrar[i].edad,mostrar[i].nombre);

                }
            }

}
