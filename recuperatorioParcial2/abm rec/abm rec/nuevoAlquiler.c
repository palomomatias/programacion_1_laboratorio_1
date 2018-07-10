#include"nuevoAlquiler.h"
#include<stdlib.h>
#include<string.h>

nuevoAlquiler* constructorAlquiler()
{
    nuevoAlquiler* aux;
    aux=(nuevoAlquiler*)malloc(sizeof(nuevoAlquiler));
    return aux;
}
void set_alquilerId(nuevoAlquiler* this, int dato)
{
    this->id=dato;
}
void set_alquilerIdPro(nuevoAlquiler* this, int dato)
{
    this->idCliente=dato;
}
void set_alquilerTiempo(nuevoAlquiler* this, int dato)
{
    this->tiempo=dato;
}
void set_alquilerEquipo(nuevoAlquiler* this, char dato[])
{
    strcpy(this->equipo,dato);
}
int get_alquilerId(nuevoAlquiler* this)
{
    return this->id;
}
int get_alquilerTiempo(nuevoAlquiler* this)
{
    return this->tiempo;
}
int get_alquilerIdPro(nuevoAlquiler* this)
{
    return this->idCliente;
}
char* get_alquilerEquipo(nuevoAlquiler* this)
{
    return this->equipo;
}
int idAutoIncrementalAlquiler(ArrayList* this, nuevoAlquiler* aux,ArrayList* alquilado)
{
    int auxId=this->len(this)+1;
    nuevoAlquiler* auxiliar;
    int i;
    int j;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {

            while(((nuevoAlquiler*)*(this->pElements+i))->id==auxId)
            {
                auxId++;

            }

        }
        for(j=0; j<al_len(alquilado); j++)
        {

            while(((nuevoAlquiler*)*(alquilado->pElements+j))->id==auxId)
            {
                auxId++;

            }


        }



    }
    aux->id=auxId;
}
void mostrarAlquiler(ArrayList* this, ArrayList* clientes)
{
    int i;
    int len=this->len(this);
    nuevoAlquiler* aux;
    eCliente* cliente;
    int j;
    printf("* ID ----- EQUIPO -------- DIAS ------ IDPRO-------NOMBRECLIENTE *\n\n");
    for(i=0; i<len; i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            for(j=0; j<clientes->len(clientes); j++)
            {
                cliente=this->get(clientes,j);
                if(aux->idCliente==cliente->id)
                {
                    mostraUnoAlquiler(aux,this,cliente);
                }
            }

        }
    }
}
void mostraUnoAlquiler(nuevoAlquiler* p,ArrayList* this,eCliente* c)
{

    //printf("   %-8d%-15s%-18s%-d\n", al_indexOf(this, p),p->nombre,p->apellido, p->dni);
    printf("   %-8d%-15s%-18d%-8d%-s\n",get_alquilerId(p),get_alquilerEquipo(p),get_alquilerTiempo(p),get_alquilerIdPro(p),get_nombre(c));

}

int compareIdCliente(ArrayList* this,void* elemento)
{
    int retorno=-1;
    nuevoAlquiler* aux;
    eCliente* aux2;
    int i;
    for(i=0; i<al_len(this); i++)
    {
        aux=al_get(this,i);
        aux2=al_get(this,i);
        if(aux2->id==elemento)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void altaAlquiler(ArrayList* alquiler,ArrayList* alquilado,ArrayList* listaCliente)
{
    nuevoAlquiler* aux;
    int tiempo;
    //  char equipo[50];
    int indice;
    int id;

    int opcion;
    if(alquiler!=NULL)
    {
        aux=constructorAlquiler();
        if(aux!=NULL)
        {
            mostrarTodo(listaCliente);
            id=getValidInt("ingrese el id de cleinte\n","error reingrese\n",1,99);
            indice=compareIdCliente(listaCliente,id);
            if(indice!=-1)
            {
                tiempo=getValidInt("ingrese los dias que se va a quedar\n","error solo numeros\n");
                opcion=getValidInt("ingrese el equipo que quiere alquilar\n1- AMOLADORA\n2- MEZCLADORA\n3- TALADRO\n","Error ingrese solo numeros\n",1,3);


                switch(opcion)
                {
                case 1:
                    strcpy(aux->equipo,"AMOLADORA");
                    break;
                case 2:
                    strcpy(aux->equipo,"MEZCLADORA");
                    break;
                case 3:
                    strcpy(aux->equipo,"TALADRO");
                    break;

                }
                set_alquilerTiempo(aux,tiempo);
                set_alquilerIdPro(aux,id);
                idAutoIncrementalAlquiler(alquiler,aux,alquilado);

                alquiler->add(alquiler,aux);
                printf("se dio de alta correctamente\n");
                getch();
            }
            else
            {
                printf("id no valido");
                getch();
            }



        }
    }
}

