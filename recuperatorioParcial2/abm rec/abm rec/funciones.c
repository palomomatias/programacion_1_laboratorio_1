#include "funciones.h"
#include <stdio.h>
#define LiBRE 0
#define OCUPADO 1
#define BORRADO 2

eCliente* constructor()
{
    eCliente* aux;
    aux=(eCliente*)malloc(sizeof(eCliente));
    return aux;
}
void set_dni(eCliente* this, int dato)
{
    this->dni=dato;
}
void set_id(eCliente* this, int dato)
{
    this->id=dato;
}
void set_nombre(eCliente* this, char dato[])
{
    strcpy(this->nombre,dato);
}
void set_apellido(eCliente* this, char dato[])
{
    strcpy(this->apellido,dato);
}
int get_id(eCliente* this)
{
    return this->id;
}

char* get_nombre(eCliente* this)
{
    return this->nombre;
}


int get_dni(eCliente* this)
{
    return this->dni;
}
char* get_apellido(eCliente* this)
{
    return this->apellido;
}
void mostrarTodo(ArrayList* this)
{
    int i;
    int len=this->len(this);
    eCliente* aux;
    printf("\nid\tDni\tNombre\tApellido\tEstado\n");
    for(i=0; i<len; i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            mostraUno(aux);
        }
    }
}
void mostraUno(eCliente* this)
{
    printf("\n%d  \t%d\t%s\t%s\t%d\n",get_id(this),get_dni(this),get_nombre(this),get_apellido(this),this->estado);
}




char pedirMensajeInt(char mensaje[],int* dato)
{
    char auxiliarChar[50];
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);
    validar_numero(auxiliarChar);
    *(dato)=atoi(auxiliarChar);

    return 1;
}
char pedirMensajeString(char mensaje[], char auxiliarChar[])
{
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);


    validarPalabra(auxiliarChar);

    return auxiliarChar;
}
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
void idAutoIncremental(ArrayList* this, eCliente* aux)
{
    int contador=1;
    eCliente* auxiliar;
    int i;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            auxiliar=al_get(this,i);
            if(auxiliar->estado==OCUPADO)
            {
                contador=contador+1;
            }
        }


    }
    aux->id=contador;
}
void alta(ArrayList* this)
{
    eCliente* aux;
    int dni;
    char nombre[50];
    char apellido[50];
    int id;
    if(this!=NULL)
    {
        aux=constructor();
        if(aux!=NULL)
        {
            pedirMensajeInt("ingrese su dni\n",&dni);
            pedirMensajeString("ingrse su nombre\n",nombre);
            pedirMensajeString("ingrese su apellido\n",apellido);
            idAutoIncremental(this,aux);
            aux->estado=OCUPADO;
            set_apellido(aux,apellido);
            set_nombre(aux,nombre);
            set_dni(aux,dni);
         //   set_id(aux,id);
            this->add(this,aux);
s
        }
        else
        {
            free(aux);
        }
    }
}











