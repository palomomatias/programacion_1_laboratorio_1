#include "propetarios.h"
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

int mostrarUno(ePropetarios parametro)
{
    printf("\nNOMBRE %s - ID %d\n",parametro.nombre,parametro.idPropetario);
}
int buscarPorId(ePropetarios listado[],int limite, int id)
{

  int indice=-1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado==0)
        {
            if(listado[i].idPropetario==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int inicializadorEstadoPropetario(ePropetarios listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
        }
    }
    return retorno;
}
int buscarLugarLibre(ePropetarios listado[],int limite)
{
    {
        int i;
        int indice=-1;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==1)
            {
                indice=i;
                break;
            }
        }
        return indice;
    }
}

void inicializadorHardcodeoPropetario(ePropetarios usuarios[])
{



        int idPropetario[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    int numeroTarjetaCredito= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int i;
    for(i=0; i<4; i++)
    {
        usuarios[i].idPropetario=idPropetario[i];
        usuarios[i].estado = OCUPADO;
        usuarios[i].numeroTarjetaCredito=numeroTarjetaCredito[i];
        strcpy(usuarios[i].nombre, nombre[i]);
        strcpy(usuarios[i].direccion,direccion[i]);
    }

}

int altaPropetario(ePropetarios  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int id;
    int tarjeta;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {

   do {

        printf("ingrese EL ID:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    id=atoi(auxiliar);
    listado[indice].idPropetario=id;
                  do
                {
                    printf("INGRESE SU DIRECCIO\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].direccion,auxiliar);

                         do
                {
                    printf("INGRESE SU NOMBRE\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].nombre,auxiliar);
                 do {

        printf("ingrese EL su tarjeta de credito:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    tarjeta=atoi(auxiliar);
    listado[indice].numeroTarjetaCredito=tarjeta;
           //listado[indice].idPropetario=siguienteId(listado,limite);
            listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}

void mostrarPropetario (ePropetarios mostrar [],int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==OCUPADO)
        {
            printf("Id:%d NOMBRE: %s TARJETA %d\n",mostrar[i].idPropetario,mostrar[i].nombre,mostrar[i].numeroTarjetaCredito);

        }
    }

}
void modificarPropetario(ePropetarios listado [],int limite)
{
    int opcion ;
    int i;
    int opcion2;
    int id;
    int tarjeta;
    mostrarPropetario(listado, limite);
    do
    {

        printf("ingrese el id que quiere modificar:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    id=opcion;

    opcion=buscarPorId(listado,limite,opcion);
    fflush(stdin);

    for(i=0; i<limite; i++)
    {

        if (opcion==listado[i].idPropetario||id==listado[opcion].idPropetario)
        {

               do
    {

        printf("que desea modificar ? \n 1-TARJETA DE CREDITO\n");
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
                    printf("INGRESE  SU NUEVA TARJETA\n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validar_numero(auxiliar));
                tarjeta=atoi(auxiliar);

               listado[opcion].numeroTarjetaCredito=tarjeta;
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


void darDebajaPropetario(ePropetarios listado [],int limite)
{
    int opcion;
    int i;
    int opcion2;
    mostrarPropetario(listado,limite);
   do
    {

        printf("ingrese el id que quiere dar de baja:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    for(i=0; i<limite; i++)
    {
        fflush(stdin);
        if (opcion==listado[i].idPropetario)
        {
            fflush(stdin);
          //  mostrarPropetario(listado[i]);

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

int siguienteId(ePropetarios listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {


        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE||listado[i].estado==2)
            {
                if(listado[i].idPropetario>retorno)
                {
                    retorno=listado[i].idPropetario;
                }

            }
        }
    }

    return retorno+1;
}
void ordenarPorNombre(ePropetarios listado [],int limite)
{
    ePropetarios auxiliar;
    int i;
    int j;
    for(i=0; i<limite; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(listado[i].idPropetario>listado[j].idPropetario)
            {

                auxiliar=listado[i];
                listado[i]=listado[j];
                listado[j]=auxiliar;
            }

        }
    }


    mostrarPropetario(listado,limite);


}


