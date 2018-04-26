#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombreLocalidad[50];
    int estado;

}eLocalidad;


#endif
void loc_MostrarUno(eLocalidad aux);
void loc_MostrarListado(eLocalidad listado [],int largo);
void loc_Alta(eLocalidad listado [],int largo);
void loc_Baja(eLocalidad listado [],int largo,int idParaBorrar);
void loc_Modificacion(eLocalidad listado [],int largo,int idParamodificar);
void loc_ordenarDescPorNombre(eLocalidad listado [],int largo);
void loc_ordenarDescPorID(eLocalidad listado [],int largo);
