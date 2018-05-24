#include <stdio.h>
#include <stdlib.h>
#include"egresos.h"
#define tamPropetarios 15
#define TamCoches 30
#define TamEgreso 15
int main()
{
    ePropetarios listaPropetarios[tamPropetarios];
    eCoches listaCoches[TamCoches];
    eEgreso listaEgreso[TamEgreso];
    inicializadorEstadoEgreso(listaEgreso,TamEgreso);
    inicializadorEstadoCoches(listaCoches,TamCoches);
    inicializadorEstadoUsuario(listaPropetarios,tamPropetarios);
    inicializadorHardcodeoEgreso(listaEgreso);
    inicializadorHardcodeoPropetario(listaPropetarios);
    inicializadorHardcodeoCoches(listaCoches);

    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        mostrarPersonas(listaPropetarios,tamPropetarios);

        printf("\n");
        printf(" 1-  Alta de propetario\n");
        printf(" 2-  Modificar Propetario\n");
        printf(" 3-  Baja propetario\n");
        printf(" 4-  Alta de Coche\n");
        printf(" 5-  Egreso de Automovil\n");
        printf(" 6-  Recaudacion total \n");
        printf(" 7-  Recaudacion por marca \n");
        printf(" 8-  Buscar por Propetario\n");
        printf(" 9-  Mostrar propetario que tienen el auto audi\n");
        printf("10-  Listar ordenado por patente\n");
        printf("11-  Salir\n");

        pedirMensaje("elija una opcion\n",auxiliar);
        validar_numero(auxiliar);
        opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
            alta(listaPropetarios,tamPropetarios,listaCoches);

            break;
        case 2:

            modificar(listaPropetarios,tamPropetarios);

            break;
        case 3:
            darDebaja(listaPropetarios,tamPropetarios,listaCoches,TamCoches,listaEgreso);

            break;
        case 4:
            altaCoches(listaCoches,TamCoches,listaPropetarios,tamPropetarios);
            break;
        case 5:

            bajaCoche(listaCoches,listaPropetarios,listaEgreso,TamCoches,tamPropetarios,TamEgreso);
            break;
        case 6:
            recaudaciones(listaEgreso,TamEgreso);
            getch();
            break;
        case 7:
            recaudacionesMarca(listaEgreso,TamEgreso);
            getch();
            break;
        case 8:
            propetarioConAuto(listaPropetarios,listaCoches,TamCoches,tamPropetarios);
            break;
        case 9:
            buscarAudi(listaPropetarios,listaCoches,TamCoches,tamPropetarios);
            getch();
            break;
        case 10:
            mostrarOrdenadoPatente(listaCoches,TamCoches,listaPropetarios,tamPropetarios);
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("cls");
    }
    return 0;

}


//mostrarAuto(listaCoches,TamCoches);
//getch();

