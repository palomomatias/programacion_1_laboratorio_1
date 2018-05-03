#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0


char pedirMensaje(char mensaje [],char dato [])
{
    printf("%s")
}
int inicializadorEstadoUsuario (eUsuario listado [], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;listado[i].idUsuario= 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idUsuario= 0;


        }
    }
    return retorno;
}

int buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int i;
    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].estado = LIBRE;
        strcpy(usuarios[i].nombre, nombre[i]);
    }

}

int alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
                printf("ingrese su id ");
                scanf("%d",&listado[indice].idUsuario);
                printf("ingrese su Nombre");
                fflush(stdin);
                //
                gets(listado[indice].nombre);
                listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}

void mostrarPersonas (eUsuario mostrar [],int limite)
{
    int i;
    for(i=0; i<limite; i++)
            {
                if(mostrar[i].idUsuario!=0)
                {
                    printf("Id:%d NOMBRE: %s \n",mostrar[i].idUsuario,mostrar[i].nombre);

                }
            }

}
void modificar(eUsuario listado [],int limite)
{
mostrarPersonas(listado, limite);
}
