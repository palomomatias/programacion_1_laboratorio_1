#include "coches.h"
#define ALPHA_ROMEO "ALFA ROMERO"
#define FERRARI "FERRARI"
#define AUDI "AUDI"
#define OTRO "OTRO"



int buscarporIdCoches(eCoches listado[],int limite, int id)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == OCUPADO && listado[i].idIngreso == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int inicializadorEstadoCoches(eCoches listado[],int limite)
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
int buscarLugarLibreCoches(eCoches listado[],int limite)

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
void inicializadorHardcodeoCoches(eCoches usuarios[])
{



    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int i;
    for(i=0; i<10; i++)
    {
        usuarios[i].idIngreso=id[i];
        usuarios[i].estado = OCUPADO;
        usuarios[i].marca=marca[i];
        usuarios[i].idPropetario=propietario[i];
        strcpy(usuarios[i].patente, patente[i]);
    }

}

char cambiarMarcas(eCoches listado[],int marca,char nombreMarca[])
{
    if(marca==1)
    {
        strcpy(nombreMarca,ALPHA_ROMEO);
    }
    else if(marca==2)
    {
        strcpy(nombreMarca,FERRARI);
    }
    else if(marca==3)
    {
        strcpy(nombreMarca,AUDI);
    }
    else
    {
        strcpy(nombreMarca,OTRO);
    }
    return nombreMarca;
}
int altaCoches(eCoches  listado[],int limite,ePropetarios listaPropetarios [],int limite2)
{
    int retorno = -1;
    int indice;
    int propetario;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;

        indice=buscarLugarLibreCoches(listado,limite);

        if(indice >= 0)
        {
            mostrarPersonas(listaPropetarios,limite2);
            pedirMensaje("\ningrese el id que quiere asociar",auxiliar);
            propetario=atoi(auxiliar);


            propetario=buscarPorId(listaPropetarios,limite2,propetario);

            if (propetario!=-1)
            {
                listado[indice].idIngreso=siguienteIdCoches(listado,limite);
                listado[indice].idPropetario=listaPropetarios[propetario].idPropetario;
                pedirMensaje("ingrese el numero de patente",&listado[indice].patente);
                pedirMensaje("ingrese la marca \n 1-ALPHA_ROMEO \n 2-FERRARI\n3-AUDI\n4-OTRO\n",auxiliar);
                validar_numero(auxiliar);
                listado[indice].marca=atoi(auxiliar);
                cambiarMarcas(listado,listado[indice].marca,listado[indice].nombreMarca);
                listado[indice].estado=OCUPADO;

            }


            else
            {
                printf("id no encontrado");
                getch();
            }
        }
        else
        {
            printf(" no hay lugar");
            getch();
        }
    }
    return retorno;
}
int siguienteIdCoches(eCoches listado[],int limite)
{


    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {


        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO||listado[i].estado==BORRADO)
            {

                retorno=listado[i].idIngreso;


            }
        }
    }

    return retorno+1;
}

void mostrarAuto (eCoches mostrar [],int limite)
{


    int i;
    printf("Id ingreso\tId propietario\t Patente    Marca \n");
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==OCUPADO)
        {
            cambiarMarcas(mostrar,mostrar[i].marca,mostrar[i].nombreMarca);
            printf("%d\t\t%d\t\t  %s\t     %s\n",mostrar[i].idIngreso,mostrar[i].idPropetario,mostrar[i].patente,mostrar[i].nombreMarca);
        }

    }
}
int buscarPropetarioConAuto(eCoches listaCoches[],ePropetarios listaPropetario[],int tamPropetarios,int TamCoches,int idcoches)
{
    int i;
    int propetarioCoche;
    for(i=0; i<tamPropetarios; i++)
    {


        if (listaPropetario[i].estado==OCUPADO&&listaCoches[idcoches].idPropetario==listaPropetario[i].idPropetario )
        {
            propetarioCoche=i;

        }
    }
    return propetarioCoche;

}

