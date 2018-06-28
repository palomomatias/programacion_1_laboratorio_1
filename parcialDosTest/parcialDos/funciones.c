#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define LiBRE 0
#define OCUPADO 1
#define BORRADO 2
#define ATENDIDO 3
eTramite* etramite_new()
{
    eTramite* tramite;
    tramite =(eTramite*) malloc(sizeof(eTramite));
    return tramite;
}
int setDni(eTramite* this,int dni)
{
   int retorno=0;

    if(this!=NULL)
    {
        this->dni=dni;
        retorno=1;
    }
 return retorno;
}

int setNombre(eTramite* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
 return retorno;
}

int setidTurno(eTramite* this,int turno)
{
    int retorno=0;
    int i;
    eTramite* auxiliar;

    if(this!=NULL)
    {

        //    auxiliar=al_get(this,i);
         //   if(auxiliar->estado==OCUPADO||auxiliar->estado==ATENDIDO)
           // {


            this->idTurno=turno;
             retorno=1;



      //  }

    }
 return retorno;
}




int getDni(eTramite* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        retorno=this->dni;
    }

 return retorno;
}

char* getNombre(eTramite* this)
{
    char* retorno=NULL;
    if(this!=NULL)
    {
        retorno=this->nombre;
    }

 return retorno;
}

int getidTurno(eTramite* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        retorno=this->idTurno;
    }
 return retorno;
}
int siguienteTurno(ArrayList* this)
{
    eTramite* auxiliar;
    int retorno=0;
    int i;
    if(this!=NULL)
    {
  //for(i=0;i<al_len(this);i++)
    //    {
      //      auxiliar=al_get(this,i);
        //    if(auxiliar->estado==OCUPADO||auxiliar->estado==ATENDIDO)



       //{
retorno=this->len(this)+1;

        //}

        //}

    }
 return retorno;
}
int idAutoIncremental(ArrayList* this, eTramite* aux)
{
    int contador=0;
    eTramite* auxiliar;
    int i;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            auxiliar=al_get(this,i);
            if(auxiliar->estado==OCUPADO||auxiliar->estado==ATENDIDO)
            {
            //    if(auxiliar->estado==ATENDIDO)
              //  {


                contador=contador+1;
            //}
            }
        }


    }
    aux->idTurno=contador;
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
char pedirMensaje (char mensaje[], char auxiliarChar[])
{
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);




    return auxiliarChar;
}
int cargarTramite(ArrayList* this)
{
    int retorno=-2;
    char auxDni[20];
    char auxNombre[50];
    int dni;
    int turno;

    eTramite* tramite;
    if(this!=NULL)
    {
        retorno=-1;

        tramite=etramite_new();
        pedirMensaje("ingrese dni\n",auxDni);
        validar_numero(auxDni);
        dni=atoi(auxDni);
        setDni(tramite,dni);

        pedirMensaje("ingrese Su Nombre\n",auxNombre);
        validarPalabra(auxNombre);
        setNombre(tramite,auxNombre);
        turno=siguienteTurno(this);
        setidTurno(tramite,turno);
        tramite->estado=OCUPADO;
      //  mostrarUno(tramite);





      this->add(this,tramite);
    }
return retorno;
}
int compararInt(void* enteroA ,void* enteroB)
{
    int retorno;

    eTramite* intA;
    eTramite* intB;

    intA=(eTramite*)enteroA;
    intB=(eTramite*)enteroB;

  if(intA->dni<intB->dni)
  {
      retorno=-1;
  }
  else if(intA->dni>intB->dni)
  {
      retorno=1;
  }
  else
  {
      retorno=0;
  }

  return retorno;
}


int compararChar(void* characterA,void* characterB)
{
    int retorno;

    eTramite* charA;
    eTramite* charB;

    charA=(eTramite*)characterA;
    charB=(eTramite*)characterB;

    retorno=strcmp(charA->nombre,charB->nombre);

  return retorno;
}
int mostrarUno(eTramite* this)
{
    int retorno=0;

    if(this!=NULL)
    {
        //printf("\ndni\t      turno\t    nombre\t");
        printf("\n%d\t      %d\t          %s\n",this->dni,this->idTurno,this->nombre);
        retorno=1;
    }
 return retorno;
}
void mostrarTodo(ArrayList* this)
{
    eTramite* aux;
    int i;
    if(this!=NULL)
    {
       printf("\ndni\t      turno\t    nombre\t");
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            mostrarUno(aux);
        }
    }
}
/*int altaTramite(ArrayList* this)
{
    int retorno=-2;
    char auxDni[20];
    char auxNombre[50];
    int dni;
    int turno;

    eTramite* tramite;
    if(this!=NULL)
    {
        retorno=-1;

        tramite=etramite_new();

       pedirMensaje("ingrese su dni",auxDni);
       validar_numero(auxDni);
      dni= atoi(auxDni);
        setDni(tramite,dni);

       pedirMensaje("ingrese su nombre",auxNombre);
       validarPalabra(auxNombre);
        setNombre(tramite,auxNombre);

        turno=siguienteTurno(this);
        setidTurno(tramite,turno);

        mostrarUno(tramite);

      this->add(this,tramite);
    }
 return retorno;
}*/
int atenderTramite(ArrayList* thisPendientes, ArrayList* thisAtendidos)
{
    int retorno=-1;
    eTramite* tramiteActual;

    if(thisPendientes!=NULL && thisAtendidos!=NULL)
    {
            tramiteActual = (eTramite*) thisPendientes->pop(thisPendientes,0);
        thisAtendidos->add(thisAtendidos,tramiteActual);
            mostrarUno(tramiteActual);
            tramiteActual->estado=ATENDIDO;
            retorno=0;

    }
    return retorno;
}
int mostrarTramites(ArrayList* this)
{
    int retorno=-1;
    int i;
    int len;
    eTramite* traActual;

    if(this!=NULL)
    {
        len=this->len(this);

        for(i=0;i<len;i++)
        {
            traActual=(eTramite*)this->get(this,i);

        }
        retorno=0;
        mostrarTodo(this);
    }
    return retorno;
}
