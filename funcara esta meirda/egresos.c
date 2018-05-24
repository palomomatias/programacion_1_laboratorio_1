#include"egresos.h"



int inicializadorEstadoEgreso(eEgreso listado[], int limite)
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
void inicializadorHardcodeoEgreso(eEgreso usuarios[])
{

    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};
    int i;
    for(i=0; i<10; i++)
    {

        usuarios[i].estado = EGRESADO;
        usuarios[i].marca=marca[i];
        usuarios[i].importe=importe[i];

    }
}

int siguienteIdEgreso(eEgreso listado[],int limite)
{


    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {


        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO||listado[i].estado==EGRESADO)
            {

                retorno=listado[i].idEgreso;


            }
        }
    }

    return retorno+1;
}
int buscarLugarLibreEgreso(eEgreso listado[],int limite)

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

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int tasarEstadia(int marca,int horas)
{
    int valor;
    if(marca==1)
    {
        valor=horas*150;
    }
    else if(marca==2)
    {
        valor=horas*175;
    }
    else if(marca==3)
    {
        valor=horas*200;
    }
    else if (marca==4)
    {
        valor=horas*250;
    }
    return valor;
}
void bajaCoche(eCoches listaCoches[],ePropetarios listaPropetarios[],eEgreso listadoEgresos[],int TamCoches,int tamPropetarios,int TamEgreso)
{
    int id;
    int propetarioCoche;
    int opcion;
    int horas;
    int total;
    int egresos;
    mostrarAuto(listaCoches,TamCoches);
    pedirMensaje("\n ingrese el id de ingreso para dar de baja\n",auxiliar);
    validar_numero(auxiliar);
    id=atoi(auxiliar);
    id=buscarporIdCoches(listaCoches,TamCoches,id);
    propetarioCoche=buscarPropetarioConAuto(listaCoches,listaPropetarios,tamPropetarios,TamCoches, id);
    if (id!=-1)
    {

        horas=devolverHorasEstadia();
        total=tasarEstadia(listaCoches[id].marca,horas);
        cambiarMarcas(listaCoches,listaCoches[id].marca,listaCoches[id].nombreMarca);
        printf("\nNombre propetario: %s-- Patente %s-- Marca:%s-- Valor de la estadia: $%d\n",listaPropetarios[propetarioCoche].nombre,listaCoches[id].patente,listaCoches[id].nombreMarca,total);
        pedirMensaje("estas seguro que quiere dar de baja ?\n aprete 1 si quiere borrar: \n",auxiliar);
        validar_numero(auxiliar);
        opcion=atoi(auxiliar);

        if(opcion==1)
        {
            egresos=buscarLugarLibreEgreso(listadoEgresos,TamEgreso);
            listadoEgresos[egresos].idEgreso=siguienteIdEgreso(listadoEgresos,TamEgreso);
            listadoEgresos[egresos].estado=EGRESADO;
            listadoEgresos[egresos].importe=total;
            listadoEgresos[egresos].marca=listaCoches[id].marca;
            listaCoches[id].estado=BORRADO;
            printf("se a egresado ");
            getch();
        }

        else
        {
            printf("no se a dado de baja el automovil");
            getch();
        }

    }
    else
    {
        printf("id no encontrado");
        getch();
    }
}

int recaudaciones(eEgreso listaEgreso[],int tamanio)
{
    float total;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listaEgreso[i].estado==EGRESADO)
        {
            total=total+listaEgreso[i].importe;

        }
    }
    printf("la recaudacion total es: $%.2f",total);
}

int recaudacionesMarca(eEgreso listaEgreso[],int tamanio)
{
    float alpha;
    float ferrari;
    float audi=0;
    float otro;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listaEgreso[i].estado==EGRESADO)
        {
            if(listaEgreso[i].marca==1)
            {
                alpha=alpha+listaEgreso[i].importe;
            }
            else if(listaEgreso[i].marca==2)
            {
                ferrari=ferrari+listaEgreso[i].importe;
            }
            else if(listaEgreso[i].marca==3)
            {
                audi=audi+listaEgreso[i].importe;
            }
            else if (listaEgreso[i].marca==4)
            {
                otro=otro+listaEgreso[i].importe;
            }

        }
    }
    printf("\nRecaudacion de Alfa Romeo: $ %.2f",alpha);
    printf("\nRecaudacion de Ferrari: $ %.2f",ferrari);
    printf("\nRecaudacion de Audi: $ %.2f",audi);
    printf("\nRecaudacion de otras marcas: $ %.2f",otro);
}
int propetarioConAuto(ePropetarios listaPropetario[],eCoches listaCoche[],int TamCoches,int tamPropetarios)
{
    int id;
    int i;
    mostrarPersonas(listaPropetario,tamPropetarios);
    pedirMensaje("\ningrese el id que quiere buscar\n",auxiliar);
    id=atoi(auxiliar);
    id=buscarPorId(listaPropetario,tamPropetarios,id);
    if(id!=-1)
    {
        if(listaCoche[id].estado==OCUPADO)
        {


            printf("Propietario: %s\n",listaPropetario[id].nombre);
            for(i=0; i<TamCoches; i++)
            {
                if(listaPropetario[id].idPropetario==listaCoche[i].idPropetario)
                {
                    cambiarMarcas(listaCoche,listaCoche[i].marca,listaCoche[i].nombreMarca);
                    printf("Marca: %s\n",listaCoche[i].nombreMarca);
                    printf("Patente: %s\n",listaCoche[i].patente);

                }




            }

        }
        else
        {
            printf("no tiene coches este usuario");
            getch();
        }
        getch();
    }
    else
    {
        printf("id no encontrado");
        getch();
    }


}

int buscarAudi(ePropetarios listaPropetario[],eCoches listaCoche[],int TamCoches,int tamPropetarios)
{
    int i;
    int j;


    printf("\nPropietarios que tienen  Audi\t");
    for(i=0; i<TamCoches; i++)
    {
        if(listaCoche[i].estado==OCUPADO&&listaCoche[i].marca==3)
        {

            for(j=0; j<tamPropetarios; j++)
            {
                if(listaCoche[i].idPropetario==listaPropetario[j].idPropetario&&listaPropetario[j].estado==OCUPADO)
                {

                    printf("\n%s",listaPropetario[j].nombre);
                }
            }
        }
    }
}

int ordenarPatente(eCoches listaCoche [],int TamCoches)
{
    eCoches CocheAuxiliar;
    int i;
    int j;
    for (i=0; i<TamCoches; i++)
    {
        if(listaCoche[i].estado==OCUPADO)
            for(j=i+1; j<TamCoches; j++)
            {
                if(strcmpi(listaCoche[i].patente,listaCoche[j].patente)>0)
                {
                    CocheAuxiliar=listaCoche[i];
                    listaCoche[i]=listaCoche[j];
                    listaCoche[j]=CocheAuxiliar;
                }

            }
    }
}
int mostrarOrdenadoPatente(eCoches listaCoche[],int TamCoches,ePropetarios listaPropetario[],int tamPropetarios)
{

    int propetarioCoche;
    int i;
    int ordenado;
    ordenado=ordenarPatente(listaCoche,TamCoches);
    system("cls");
    printf("patente\t nombre\tmarca\n");

    for (i=0; i<TamCoches; i++)
    {
        propetarioCoche=buscarPorId(listaPropetario,tamPropetarios,listaCoche[i].idPropetario);
        if(listaCoche[i].estado==OCUPADO&&listaPropetario[propetarioCoche].estado==OCUPADO)
        {


            cambiarMarcas(listaCoche,listaCoche[i].marca,listaCoche[i].nombreMarca);

            printf("%s\t %s\t %s\n",listaCoche[i].patente,listaPropetario[propetarioCoche].nombre,listaCoche[i].nombreMarca);
        }
    }
    getch();
}


void darDebaja(ePropetarios listado [],int limite,eCoches listacoche[],int TamCoches,eEgreso listaEgreso[])
{
    int opcion;
    int i;
    int opcion2;
    mostrarPersonas(listado,limite);
    pedirMensaje("\ningrese el id que quiere dar de baja",auxiliar);
    validar_numero(auxiliar);
    opcion=atoi(auxiliar);
    opcion=buscarPorId(listado,limite,opcion);
    if(opcion!=-1)
    {
        pedirMensaje("esta seguro que quiere dar de baja?\n 1-para dar de baja \n 2-para cancelar ?",auxiliar);
        validar_numero(auxiliar);
        opcion2=atoi(auxiliar);
        if(opcion2==1)
        {
            for(i=0; i<TamCoches; i++)
            {
                if(listado[opcion].idPropetario==listacoche[i].idPropetario)
                {

                    listacoche[i].estado==BORRADO;
                    listacoche[i].idIngreso==BORRADO;
                    listaEgreso[i].estado=BORRADO;
                }


            }

            listado[opcion].estado=BORRADO;
            printf("SE A DADO DE BAJA \n");
            getch();
        }

        else
        {
            printf("NO SE A DADO DE BAJA \n");
            getch();
        }

    }
    else
    {
        printf("id no existe \n");
        getch();
    }




}
int alta(ePropetarios  listado[],int limite,eCoches listacoche[])
{
    int retorno = -1;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;

        indice=buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {

            pedirMensaje("ingrese su Nombre\n",auxiliar);
            validarPalabra(auxiliar);
            strcpy(listado[indice].nombre,auxiliar);
            listado[indice].idPropetario=siguienteId(listado,limite);
            pedirMensaje("ingrese su Tarjeta \n",listado[indice].numeroTarjetaCredito);
            pedirMensaje("ingrese su direccion\n",listado[indice].direccion);
            listado[indice].estado=OCUPADO;
            listacoche[indice].estado=LIBRE;


        }
        else
        {
            printf(" no hay lugar");
            getch();
        }
    }
    return retorno;
}
