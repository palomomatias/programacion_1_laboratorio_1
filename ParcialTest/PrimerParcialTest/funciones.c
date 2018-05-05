#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0
#include <ctype.h>

/*
gets(auxString);
x=validastringentero(auxstring)
if(x==1)
    {
edad=atoi(auxstring);
int isAlpha(char)
int isdigit(char)
int isspace(char)


*/
int validarPalabra(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {
        if(!(isalpha(palabra[i])))
        {
            printf("\nERROR SOLO PALABRA, REINGRESE");
            return 0;
        }
    }
    return 1;
}


char getChar (char mensaje[], char auxiliarChar[])
{
    ;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}
int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}

int mostrarUno(eUsuario parametro)
{
    printf("\n %s - %d",parametro.nombre,parametro.idUsuario);
}
int buscarPorId(eUsuario listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE && listado[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int inicializadorEstadoUsuario(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}
int buscarLugarLibre(eUsuario listado[],int limite)
{
    {
        int i;
        int indice=-1;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==0)
            {
                indice=i;
                break;
            }
        }
        return indice;
    }
}

void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1,2,3,4,5,6,7,8,19,10,11,12,13,14,15};
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

            printf("ingrese su Nombre\n");
            fflush(stdin);
            gets(listado[indice].nombre);
            listado[indice].idUsuario=siguienteId(listado,limite);
            listado[indice].estado = LIBRE;

        }
    }
    return retorno;
}

void mostrarPersonas (eUsuario mostrar [],int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==LIBRE)
        {
            printf("Id:%d NOMBRE: %s \n",mostrar[i].idUsuario,mostrar[i].nombre);

        }
    }

}
void modificar(eUsuario listado [],int limite)
{
    int opcion;
    int i;
    int opcion2;
    char auxiliar[20];
    mostrarPersonas(listado, limite);
    opcion=getInt("ingrese el id que quiere modificar");
    for(i=0; i<limite; i++)
    {
        if(opcion==listado[i].idUsuario)
        {
            opcion2=getInt("que desea modificar ? \n 1-NOMBRE\n");
            switch(opcion2)
            {
            case 1:
                //
                do
                {
                    printf("INGRESE SU NUEVO NOMBRE\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                rcpy(listado[i].nombre,auxiliar);
                printf("se a cambiado correctamente el nombre \n");


                break;
            case 2:
                break;
            case 3:
                break;
            }
            break;
        }
        else
        {
            printf("el id no existe");
            break;
        }

    }
}


void darDebaja(eUsuario listado [],int limite)
{
    int opcion;
    int i;
    int opcion2;
    mostrarPersonas(listado,limite);
    printf("ingrese el id que quiere borrar");
    scanf("%d",&opcion);
    for(i=0; i<limite; i++)
    {
        fflush(stdin);
        if (opcion==listado[i].idUsuario)
        {
            fflush(stdin);
            mostrarUno(listado[i]);
            printf("esta seguro que quiere dar de baja ? \n aprete 1 para borrar 0 para cancelar ");
            scanf("%d",&opcion2);

            if (opcion2==1)
            {
                fflush(stdin);
                printf("Se a dado de baja");
                listado[i].estado=2;
                break;
            }
            else
            {
                printf("no se a dado de baja");
            }

        }

    }

}

int siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {


        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE||listado[i].estado==2)
            {
                if(listado[i].idUsuario>retorno)
                {
                    retorno=listado[i].idUsuario;
                }

            }
        }
    }

    return retorno+1;
}
void ordenarPorNombre(eUsuario listado [],int limite)
{
    eUsuario auxiliar;
    int i;
    int j;
    for(i=0; i<limite; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(listado[i].idUsuario>listado[j].idUsuario)
            {

                auxiliar=listado[i];
                listado[i]=listado[j];
                listado[j]=auxiliar;
            }

        }
    }


    mostrarPersonas(listado,limite);


}





