#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombreEmpleado[50];
    int estado;

}eEmpleado;


#endif
void emp_MostrarUno(eEmpleado aux);
void emp_MostrarListado(eEmpleado listado [],int largo);
void emp_Alta(eEmpleado listado [],int largo);
void emp_Baja(eEmpleado listado [],int largo,int idParaBorrar);
void emp_Modificacion(eEmpleado listado [],int largo,int idParamodificar);
void emp_ordenarDescPorNombre(eEmpleado listado [],int largo);
void emp_ordenarDescPorID(eEmpleado listado [],int largo);
