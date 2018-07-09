#include"ArrayList.h"
#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    char nombre[50];
    int id;
    char apellido[50];
    int dni;
    int estado;
}eCliente;

#endif // ESTRUCTURA_H_INCLUDED
eCliente* constructor();
void set_apellido(eCliente* this, char dato[]);
void set_nombre(eCliente* this, char dato[]);
void set_id(eCliente* this, int dato);
void set_dni(eCliente* this, int dato);
int get_id(eCliente* this);
char* get_nombre(eCliente* this);
int get_dni(eCliente* this);
char* get_apellido(eCliente* this);
void mostrarTodo(ArrayList* this);
void mostraUno(eCliente* P,ArrayList* this);
void set_estado(eCliente* this, int dato);
void idAutoIncremental(ArrayList* this, eCliente* aux,ArrayList* borrados);
int compare_id(ArrayList* this,int id);
void baja(ArrayList* this, ArrayList* borrados);
void alta(ArrayList* this,ArrayList* borrados);
