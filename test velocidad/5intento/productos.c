#include "productos.h"
#define LIBRE 1
#define OCUPADO 0
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

        if(!(isalpha(palabra[i]))||(isspace(palabra[i]))||palabra[i]== ' \0')
        {
            printf("\nERROR SOLO PALABRA, REINGRESE");
            return 0;
        }



    }
    return 1;
}

int inicializadorEstadoProducto (eProducto listado[], int limite)
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
int buscarLugarLibre(eProducto listado[],int limite)
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
int siguienteIdProducto(eProducto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {


        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE||listado[i].estado==2)
            {
                if(listado[i].codigoProducto>retorno)
                {
                    retorno=listado[i].codigoProducto;
                }

            }
        }
    }

    return retorno+1;
}

int altaProducto(eProducto  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int importe;
    int cantidad;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
   do {

        printf("ingrese el importe:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    importe=atoi(auxiliar);
    listado[indice].importe=importe;
       do {

        printf("ingrese la cantidad:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    cantidad=atoi(auxiliar);
    listado[indice].cantidad=cantidad;
                         do
                {
                    printf("INGRESE LA DESCRIPCION \n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].descripcion,auxiliar);


            listado[indice].codigoProducto=siguienteIdProducto(listado,limite);
            listado[indice].estado = LIBRE;

        }
    }
    return retorno;
}
int buscarPorCodigoProducto(eProducto listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE && listado[i].codigoProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void mostrarProducto (eProducto mostrar [],int limite)
{

    int i;
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==LIBRE)
        {
            printf("CODIGO:%d NOMBRE: %s IMPORTE:%d CANTIDAD:%d  \n",mostrar[i].codigoProducto,mostrar[i].descripcion,mostrar[i].importe,mostrar[i].cantidad);

        }
    }


}

void modificarProducto(eProducto listado [],int limite)
{
    int opcion ;
    int i;
    int opcion2;
    int id;
    int importe;
    int cantidad;
    mostrarProducto(listado, limite);
    do
    {

        printf("ingrese el codigo de producto:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    id=opcion;
    opcion=buscarPorCodigoProducto(listado,limite,opcion);

    for(i=0; i<limite; i++)
    {

        if (opcion==listado[i].codigoProducto||id==listado[i].codigoProducto)
        {

               do
    {

        printf("que desea modificar ? \n 1-NOMBRE 2-IMPORTE 3-CANTIDAD\n");
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
                strcpy(listado[opcion].descripcion,auxiliar);
                printf("se a cambiado correctamente el nombre \n");


                break;
            case 2:
                  do
    {

        printf("INGRESE SU NUEVO IMPORTE:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    importe=atoi(auxiliar);
    listado[opcion].importe=importe;

                break;
            case 3:
                               do
    {

        printf("INGRESE SU NUEVA CANTIDAD:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    cantidad=atoi(auxiliar);
    listado[opcion].cantidad=cantidad;
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



























