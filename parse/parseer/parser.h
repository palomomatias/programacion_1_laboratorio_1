#include"ArrayList.h"
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

typedef struct
{
    char nombre[50];
    char mail[50];
}destinatario;

#endif // PARSER_H_INCLUDED
int validarPalabra(char palabra[]);
char pedirMensaje (char mensaje[], char auxiliarChar[]);
int validar_numero(char numero[]);
void parserRead(char archivo[],ArrayList* this);
ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra,ArrayList* listaDepurado);
void listar(ArrayList* listaDepurada);
