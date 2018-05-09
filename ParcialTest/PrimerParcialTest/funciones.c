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
int menu(eUsuario listado[],int limite)
{
    char seguir='s';
    int opcion=0;
    eUsuario listaUsuarios[tamUsuarios];
    inicializadorEstadoUsuario(listaUsuarios,tamUsuarios);
    // inicializarUsuariosHardCode(listaUsuarios);

    while(seguir=='s')
    {
           do
    {
        printf("1-  Alta de usuario\n");
        printf("2-  MODIFICAR DATOS DEL USUARIO\n");
        printf("3-  BAJA DEL USUARIO\n");
        printf("4-  PUBLICAR PRODUCTOS\n");
        printf("5-  MODIFICAR PUBLICACION\n");
        printf("6-  CANCELAR PUBLICACION\n");
        printf("7-  COMPRAR PRODUCTO\n");
        printf("8-  LISTAR PUBLICACIONES DEL USUARIO\n");
        printf("9-  LISTAR PUBLICACIONES\n");
        printf("10- LISTAR USUARIOS\n");
        printf("11- Salir\n");

                fflush(stdin);
        gets(auxiliar);


        }          while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
            alta(listaUsuarios,tamUsuarios);

            break;
        case 2:
            mostrarPersonas(listaUsuarios,tamUsuarios);
            getch();
            break;
        case 3:
            modificar(listaUsuarios,tamUsuarios);
            getch();// acordate que esto va en el case 2 solo estoy tessteando el mostrar personas;
            break;
        case 4:
            darDebaja(listaUsuarios,tamUsuarios);
            break;
        case 5:
            ordenarPorNombre(listaUsuarios,tamUsuarios);
            break;
        case 6:
            break;
        case 7:
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("cls");
    }
}
int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i]))||(isspace(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            return 0;
        }
    }
    return 1;
}

int validarPalabra(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {
        if(!(isalpha(palabra[i]))||(isspace(palabra[i])))
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
    printf("\nNOMBRE %s - ID %d\n",parametro.nombre,parametro.idUsuario);
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

                         do
                {
                    printf("INGRESE SU NOMBRE\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].nombre,auxiliar);
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
    int opcion ;
    int i;
    int opcion2;
    int id;
    mostrarPersonas(listado, limite);
    do
    {

        printf("ingrese el id:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    id=opcion;
    opcion=buscarPorId(listado,limite,opcion);

    for(i=0; i<limite; i++)
    {

        if (opcion==listado[i].idUsuario||id==listado[i].idUsuario)
        {

               do
    {

        printf("que desea modificar ? \n 1-NOMBRE\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion2=atoi(auxiliar);

            switch(opcion2)
            {
            case 1:
                do
                {
                    printf("INGRESE SU NUEVO NOMBRE\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[opcion].nombre,auxiliar);
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
   do
    {

        printf("ingrese el id que uqiere dar de baja:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    for(i=0; i<limite; i++)
    {
        fflush(stdin);
        if (opcion==listado[i].idUsuario)
        {
            fflush(stdin);
            mostrarUno(listado[i]);

             do
    {

       printf("esta seguro que quiere dar de baja ? \n aprete 1 para borrar 0 para cancelar ");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion2=atoi(auxiliar);

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





