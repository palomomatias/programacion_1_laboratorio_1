#include "funciones.h"
#define LiBRE 0
#define OCUPADO 1
#define BORRADO 2
#define ATENDIDO 3
#include <ctype.h>
#include <string.h>
#include <time.h>
#include<stdio.h>
eTramite* constructor()
{
    eTramite* aux;
    aux=(eTramite*)malloc(sizeof(eTramite));
    return aux;
}

void set_id(eTramite* this, int id)
{
    this->id=id;
}

void set_name(eTramite* this, char name[])
{
    strcpy(this->nombre,name);
}

void set_sueldo(eTramite* this, float sueldo)
{
    this->sueldo=sueldo;
}

void set_edad(eTramite* this, int edad)
{
    this->edad=edad;
}

void set_profesion(eTramite* this, char profesion[])
{

        strcpy(this->profesion,profesion);
}

int get_id(eTramite* this)
{
    return this->id;
}

char* get_nombre(eTramite* this)
{
    return this->nombre;
}

float get_salario(eTramite* this)
{
    return this->sueldo;
}

int get_edad(eTramite* this)
{
    return this->edad;
}

char* get_profesion(eTramite* this)
{
    return this->profesion;
}

void mostrarTodo(ArrayList* this)
{
    int i;
    int len=this->len(this);
    eTramite* aux;
    printf("\nID\tNombre\t\tSalario\t\tEdad\tProfesion");
    for(i=0;i<len;i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            mostraUno(aux);
        }
    }
}
void mostraUno(eTramite* this)
{
    printf("\n%d\t%s\t\t%f\t%d\t%s",get_id(this),get_nombre(this),get_salario(this),get_edad(this),get_profesion(this));
}

int funcionQueFiltra(void* elemento)
{
    if(get_edad((eTramite*)elemento)>30&&strcmp(get_profesion((eTramite*)elemento),"programador")==0)
    {
        return 1;
    }
}

