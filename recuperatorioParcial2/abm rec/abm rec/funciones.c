#include "funciones.h"
#include "utn.h"
#include <stdio.h>


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
void set_estado(eCliente* this, int dato)
{
    this->estado=dato;
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
    printf("* ID ----- NOMBRE -------- APELLIDO ------ DNI *\n\n");
    for(i=0; i<len; i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            mostraUno(aux,this);
        }
    }
}
void mostraUno(eCliente* p,ArrayList* this)
{

    //printf("   %-8d%-15s%-18s%-d\n", al_indexOf(this, p),p->nombre,p->apellido, p->dni);
    printf("   %-8d%-15s%-18s%-d\n",get_id(p),get_nombre(p),get_apellido(p),get_dni(p));

}

void idAutoIncremental(ArrayList* this, eCliente* aux,ArrayList* borrados)
{
    int auxId=this->len(this)+1;
    eCliente* auxiliar;
    int i;
    int j;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {

            while(((eCliente*)*(this->pElements+i))->id==auxId)
            {
                auxId++;

            }

        }
                                for(j=0; j<al_len(borrados); j++)
            {

                while(((eCliente*)*(borrados->pElements+j))->id==auxId)
                {
                    auxId++;

                }


            }



    }
    aux->id=auxId;
}
void alta(ArrayList* this,ArrayList* borrados)
{
    eCliente* aux;
    int dni;
    char nombre[50];
    char apellido[50];
    int i;
    if(this!=NULL)
    {
        aux=constructor();
        if(aux!=NULL)
        {
         dni=getValidInt("ingrese dni\n","error ingrese un dni valido\n",1,99999999);
         getValidString("ingrese su nombre\n","error reingre se nombre\n",nombre);
         getValidString("ingrese su apellido\n","error reingre se apellido\n",apellido);
                idAutoIncremental(this,aux,borrados);
            //aux->estado=OCUPADO;Barboza04
                aux->estado==1;
            set_apellido(aux,apellido);
            set_nombre(aux,nombre);
            set_dni(aux,dni);
//            set_id(aux,auxId);
            this->add(this,aux);

        }
        else
        {
            free(aux);
        }
    }
}
int compare_id(ArrayList* this,int id)
{
    int i;
    int len;
    eCliente* aux;
    if(this!=NULL)
    {
        len=this->len(this);
        for(i=0; i<len; i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL&&aux->id==id)
            {
                return i;
            }
        }
    }
    return -1;
}

void baja(ArrayList* this, ArrayList* borrados)
{
    eCliente* aux;
    int id;
    int indice;
    int opcion;
    if(this!=NULL)
    {
        mostrarTodo(this);
       id=getValidInt("ingrese el id que quiere dar de baja\n","error reingrese ",0,100);
        indice=compare_id(this,id);//(lprovenzano));
        //   indice=(eCliente*)al_get(this, id);
        if(indice!=-1)
        {
           opcion=getValidInt("estas seguro que quiere dar de baja?\n- 1 para dar de baja\n- 2 Para cancelar\n","error reingrese",1,2);
            if (opcion==1)
            {
                aux=this->pop(this,indice);
                this->add(borrados,aux);
                printf("se dio de baja\n");
                getch();
            }
            else
            {
                printf("no se dio de baja \n");
                getch();
            }
        }
        else
        {
            printf("id no encontrado\n");
            getch();
        }
    }

}

void modificar(ArrayList* this)
{
    eCliente* aux;
    int id;
    int indice;
    int opcion;
    char nombre[50];
    char apellido[50];
    int dni;
    if(this!=NULL)
    {
        mostrarTodo(this);
    id=getValidInt("ingrese el id que quiere modifica \n","error reingrese el numero \n",1,99);
    indice=compare_id(this,id);
        if(indice!=-1)
        {
            aux=this->get(this,indice);
            opcion=getValidInt("que desea modifica?\n1-NOMBRE\n2-APELLIDO\n3-DNI\n","error reingrese \n",1,3);
            switch(opcion)
            {
            case 1:
                getValidString("ingrese su nuevo nombre:\n","error solo letras reingrese\n",nombre);
                set_nombre(aux,nombre);
                printf("se modifico correctamente\n");
                break;
            case 2:
                 getValidString("ingrese su nuevo apellido:\n","error solo letras reingrese\n",apellido);
                set_apellido(aux,apellido);
                printf("se modifico correctamente\n");
                break;
            case 3:
                dni=getValidInt("ingrese su nuevo dni","error reingrese",1,99999999);
                set_dni(aux,dni);
                printf("se modifico correctamente\n");
                break;
            }
        }
        else{
            printf("id no encontrado\n");
        }



    }



}







