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
void mostraUno(eCliente* this);

char pedirMensajeString(char mensaje[], char auxiliarChar[]);
int validar_numero(char numero[]);
int validarPalabra(char palabra[]);
void idAutoIncremental(ArrayList* this, eCliente* aux);
char pedirMensajeInt(char mensaje[],int* dato);

