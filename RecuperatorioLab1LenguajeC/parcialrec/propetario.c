#include "propetario.h"

int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)

    {
        if(isdigit(numero[i])==0||numero[i]==' ')
        {


            do
            {
                printf("\nError solo numero reingrese\n");
                gets(numero);
                fflush(stdin);
            }
            while(isdigit(numero[i])==0);

        }
    }
    return 1;
}

int validarPalabra(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {

        if(isalpha(palabra[i])==0)
        {
            do
            {
                printf("\nError solo palabra reingrese \n");
                gets(palabra);

                fflush(stdin);
            }
            while(isalpha(palabra[i])==0);


        }
    }
    return 1;
}


char pedirMensaje (char mensaje[], char auxiliarChar[])
{
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);




    return auxiliarChar;
}
int getInt (char mensaje[],int x)
{

    printf("%s", mensaje);
    scanf("%d", &x);
    return x;
}

int mostrarUno(ePropetarios parametro)
{
    printf("\nNOMBRE %s - ID %d\n",parametro.nombre,parametro.idPropetario);
}
int buscarPorId(ePropetarios listado[],int limite, int id)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == OCUPADO && listado[i].idPropetario == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int inicializadorEstadoUsuario(ePropetarios listado[],int limite)
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
    int i;
    int indice=-1;
    for(i=0; i<limite; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


void inicializadorHardcodeoPropetario(ePropetarios usuarios[])
{



    int idPropetario[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char numeroTarjetaCredit[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int edades[]={15,28,58,33};
    int i;
    for(i=0; i<4; i++)
    {
        usuarios[i].idPropetario=idPropetario[i];
        usuarios[i].estado = OCUPADO;
        strcpy(usuarios[i].numeroTarjetaCredito,numeroTarjetaCredit[i]);
        strcpy(usuarios[i].nombre, nombre[i]);
        strcpy(usuarios[i].direccion,direccion[i]);
        usuarios[i].edad=edades[i];
    }

}




void mostrarPersonas (ePropetarios mostrar [],int limite)
{
    int i;
    printf("id:\t  nombre:\t  tarjeta de credito:\t  direccion:\t edad:\t");
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==OCUPADO)
        {

            printf("\n%d\t %s\t           %s\t          %s\t       %d\t",mostrar[i].idPropetario,mostrar[i].nombre,mostrar[i].numeroTarjetaCredito,mostrar[i].direccion,mostrar[i].edad);

        }
    }

}
void modificar(ePropetarios listado [],int limite)
{
    int opcion ;
    int i;
    int opcion2;
    mostrarPersonas(listado, limite);
    pedirMensaje("\ningrese el id que quiere modificar\n",auxiliar);
    validar_numero(auxiliar);
    opcion=atoi(auxiliar);
    opcion=buscarPorId(listado,limite,opcion);


    if (opcion!=-1)
    {
        pedirMensaje("que desea modificar ? \n 1-Tarjeta De Credito:\n",auxiliar);
        validar_numero(auxiliar);
        opcion2=atoi(auxiliar);

        switch(opcion2)
        {
        case 1:

            pedirMensaje("ingrese su nueva tarjeta de credito\n",auxiliar);
            strcpy(listado[opcion].numeroTarjetaCredito,auxiliar);
            break;
        case 2:
            break;
        case 3:
            break;
        }

    }
    else
    {
        printf("el id no existe");
        getch();

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
            if(listado[i].estado == OCUPADO||listado[i].estado==BORRADO)
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


    mostrarPersonas(listado,limite);


}


