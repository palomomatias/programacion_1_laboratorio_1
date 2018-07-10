#include"alquilar.h"
#include<stdlib.h>
#include"nuevoAlquiler.h"
#include<time.h>
eAlquilado* constructorAlquilado()
{
    eAlquilado* aux;
    aux=(eAlquilado*)malloc(sizeof(eAlquilado));
    return aux;
}
int devolverDias(eAlquilado* aux)
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    aux->tiempo=horas;
    return horas ;
}
int compare_idAlquilado(ArrayList* this,int id)
{
    int i;
    int len;
    eAlquilado* aux;
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
void terminarAlquiler(ArrayList* alquiler, ArrayList* alquilado,ArrayList* listaclientes)
{

    int indice;
    nuevoAlquiler* auxAlquiler;
    eAlquilado* aux;
    int id;
    int opcion;
    int tiempo;
    if(aux!=NULL)
    {
        aux=constructorAlquilado();
        mostrarAlquiler(alquiler,listaclientes);
        //   mostrarTodoTest(alquiler);
        id=getValidInt("ingrese el id para dar fin de aquiler\n","error reingrese \n",1,99);
        indice=compare_idAlquilado(alquiler,id);
        if(indice!=-1)
        {
            opcion=getValidInt("deseas continuar con la operacion?\n- 1 para continuar\n- 2 Para cancelar\n","error reingrese",1,2);
            if (opcion==1)
            {
                tiempo=devolverDias(aux);
                // aux->id=id;
                //aux->equipo=auxAlquiler->equipo;

                aux=alquiler->pop(alquiler,indice);
                alquiler->add(alquilado,aux);
                aux->tiempo=tiempo;
            }
            else
            {
                printf("se cancelo la operacion \n");
                getch();
            }
        }
        else
        {
            printf("id de alquiler incorrecto \n");
            getch();
        }
    }
}
void mostrarTodoTest(ArrayList* this)
{
    int i;
    int len=this->len(this);
    eAlquilado* aux;
    printf("* ID ----- equipo -------- tiempo ------ idpro *\n\n");
    for(i=0; i<len; i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            mostraUnoTest(aux,this);
        }
    }
}
void mostraUnoTest(eAlquilado* p,ArrayList* this)
{

    //printf("   %-8d%-15s%-18s%-d\n", al_indexOf(this, p),p->nombre,p->apellido, p->dni);
    printf("   %-8d%-15s%-18d%-d\n",p->id,p->equipo,p->tiempo,p->idCliente);

}
