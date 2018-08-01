#include "numeros.h"
#include <stdlib.h>
#include <stdio.h>
numeroNatural* constructor()
{
    numeroNatural* aux;
    aux=(numeroNatural*)malloc(sizeof(numeroNatural));
    return aux;
}

int set_numero(numeroNatural* this, int dato)
{
    this->numero=dato;
}

int set_par(numeroNatural* this, int dato)
{
    this->par=dato;
}

int set_impar(numeroNatural* this, int dato)
{
    this->impar=dato;
}

int set_primo(numeroNatural* this, int dato)
{
    this->primo=dato;
}

int set_nombre(numeroNatural* this, char dato[])
{
    strcpy(this->nombre,dato);
}

int get_numero(numeroNatural* this)
{
    return this->numero;
}

int get_par(numeroNatural* this)
{
    return this->par;
}

int get_impar(numeroNatural* this)
{
    return this->impar;
}

int get_primo(numeroNatural* this)
{
    return this->primo;
}

char* get_nombre(numeroNatural* this)
{
    return this->nombre;
}
void parserRead(ArrayList* this)
{
    char nombre[50];
    char numero[10];
    char par[10];
    char impar[10];
    char primo[10];
    numeroNatural* aux;
    int leidos;
    FILE* pFile;
    pFile=fopen("data.csv","r");
    if(pFile!=NULL&&this!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",numero,nombre,par,impar,primo);
            if(leidos==5)
            {
                aux=constructor();
                if(aux!=NULL)
                {
                    if(atoi(numero)>=0&&strlen(nombre)<=50&&atoi(par)==0||atoi(par)==1&&atoi(impar)==0||atoi(impar)==1&&atoi(primo)==0||atoi(primo)==1)
                    {
                        set_numero(aux,atoi(numero));
                        set_nombre(aux,nombre);
                        set_par(aux,atoi(par));
                        set_impar(aux,atoi(impar));
                        set_primo(aux,atoi(primo));
                        this->add(this,aux);
                    }
                }
            }
        }while(!feof(pFile));
        printf("\nArchivo leido con exito\n");
    }
    else
    {
        printf("\nArchivo no encontrado\n");
        system("cls");
    }
    fclose(pFile);
}
void printOne(numeroNatural* this, int id)
{
    printf("%d\t%d\t%s",id,get_numero(this),get_nombre(this));
    if(strlen(get_nombre(this))<8)
    {
        printf("\t\t\t");
    }
    else if(strlen(get_nombre(this))==16||strlen(get_nombre(this))>=18)
    {
        printf("\t");
    }
    else if(strlen(get_nombre(this))<17)
    {
        printf("\t\t");
    }

    printf("%d\t%d\t%d\n",get_par(this),get_impar(this),get_primo(this));
}
void printAll(ArrayList* this)
{
    int i;
    int indice=1;
    int len;
    numeroNatural* aux;
    if(this!=NULL)
    {
        len=this->len(this);
        printf("\nID\tNumero\tNombre\t\t\tPar\tImpar\tPrimo\n");
        for(i=0; i<len; i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                printOne(aux, indice);
                indice++;
            }

        }
    }
}
void repetidos(ArrayList* this,ArrayList* clonado,ArrayList* repetido)
{
    int i;
    int j;
    int numero;
    numeroNatural* aux;
    numeroNatural* num;
    int flag=0;
       ArrayList* C=al_newArrayList();

    if(this!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
           //  if(comprobarRepetidos(clonado,aux)==1)
        //     {


         //   num=al_get(this,i);
            for(j=i+1;j<al_len(this);j++)
           {
                num=al_get(this,j);
                numero=get_numero(num);



                if(aux->numero==numero[i])
                {
           al_remove(clonado,aux);
 flag=1;

                }




//}
 if(flag==0){
              al_add(clonado,aux);


             }


            }


        }




    }
//printAll(C);
printf("repetidos");
    printAll(clonado);


}

int compararNumeros(void* numero1, void* numero2)
{
    int retorno;
    if(get_numero((numeroNatural*)numero1)>get_numero((numeroNatural*)numero2))
    {
        retorno=1;
    }
    else if(get_numero((numeroNatural*)numero1)<get_numero((numeroNatural*)numero2))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
int comprobarRepetidos(ArrayList* repetidos,numeroNatural* numero)
{
    int i;
    int len;
    int retorno=1;
    numeroNatural* auxiliar;

    if(repetidos!=NULL && numero!=NULL)
    {
        len=repetidos->len(repetidos);
        for(i=0;i<len;i++)
        {
            auxiliar=repetidos->get(repetidos,i);
            if(auxiliar->numero==numero->numero)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}




