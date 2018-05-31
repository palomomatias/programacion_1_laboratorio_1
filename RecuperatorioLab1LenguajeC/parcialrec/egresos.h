
#include"coches.h"

typedef struct
{
    int idEgreso;
    int marca;
    int estado;
    float importe;
}eEgreso;

int inicializadorEstadoEgreso(eEgreso listado[], int limite);
void inicializadorHardcodeoEgreso(eEgreso usuarios[]);
int siguienteIdEgreso(eEgreso listado[],int limite);
int devolverHorasEstadia();
int tasarEstadia(int marca,int horas);
void bajaCoche(eCoches listaCoches[],ePropetarios listaPropetarios[],eEgreso listadoEgresos[],int cochestam,int protam,int egretam);
int buscarLugarLibreEgreso(eEgreso listado[],int limite);
int recaudaciones(eEgreso listaEgreso[],int tamanio);
int recaudacionesMarca(eEgreso listaEgreso[],int tamanio);
int propetarioConAuto(ePropetarios listaPropetario[],eCoches listaCoche[],int TamCoches,int tamPropetarios);
int buscarAudi(ePropetarios listaPropetario[],eCoches listaCoche[],int TamCoches,int tamPropetarios);
int ordenarPatente(eCoches listaCoche [],int TamCoches);
int mostrarOrdenadoPatente(eCoches listaCoche[],int TamCoches,ePropetarios listaPropetario[],int tamPropetarios);
void darDebaja(ePropetarios listado [],int limite,eCoches listacoche[],int TamCoches,eEgreso listaEgreso[]);
int alta(ePropetarios  listado[],int limite,eCoches listacoche[]);
void ordenarDescendiente (ePropetarios ordenar[],int tamPropetarios);
void ordenarAscendente (ePropetarios ordenar[],int tamPropetarios);
void pedirEdad(ePropetarios lista[],int tamPropetarios);
int buscarPorEdad(ePropetarios listado[],int limite, int edad);
void mostrarPersonasPoredad (ePropetarios mostrar [],int limite,int edad);
