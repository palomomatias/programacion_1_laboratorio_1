#include "productos.h"
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

int mostrarUno(eProducto parametro)
{
    printf("\nNOMBRE %s - ID %d\n",parametro.descripcion,parametro.codigoProducto);
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

int inicializadorEstadoProdcuto(eProducto listado[],int limite)
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
int buscarLugarLibreProducto(eProducto listado[],int limite)
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

void inicializarUsuariosHardCode(eProducto usuarios[])
{


    int id[15] = {1,2,3,4,5,6,7,8,19,10,11,12,13,14,15};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int i;
    for(i=0; i<15; i++)
    {
        usuarios[i].codigoProducto=id[i];
        usuarios[i].estado = LIBRE;
        strcpy(usuarios[i].descripcion, nombre[i]);
    }

}

int altaProducto(eProducto  listado[],int limite)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibreProducto(listado,limite);
        if(indice >= 0)
        {

                         do
                {
                    printf("INGRESE SU NOMBRE\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].descripcion,auxiliar);
            listado[indice].codigoProducto=siguienteCodigoProducto(listado,limite);
            listado[indice].estado = LIBRE;

        }
    }
    return retorno;
}

void mostrarProducto(eProducto mostrar [],int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==LIBRE)
        {
            printf("Id:%d NOMBRE: %s \n",mostrar[i].codigoProducto,mostrar[i].descripcion);

        }
    }

}
void modificarProductos(eProducto listado [],int limite)
{
    int opcion ;
    int i;
    int opcion2;
    int id;
    mostrarProducto(listado, limite);
    do
    {

        printf("ingrese el id:\n");
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
                strcpy(listado[opcion].descripcion,auxiliar);
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


void darDebajaProducto(eProducto listado [],int limite)
{
    int opcion;
    int i;
    int opcion2;
    mostrarProducto(listado,limite);
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
        if (opcion==listado[i].codigoProducto)
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

int siguienteCodigoProducto(eProducto listado[],int limite)
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
void ordenarPorNombre(eProducto listado [],int limite)
{
    eProducto auxiliar;
    int i;
    int j;
    for(i=0; i<limite; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(listado[i].codigoProducto>listado[j].codigoProducto)
            {

                auxiliar=listado[i];
                listado[i]=listado[j];
                listado[j]=auxiliar;
            }

        }
    }


    mostrarProducto(listado,limite);


}
