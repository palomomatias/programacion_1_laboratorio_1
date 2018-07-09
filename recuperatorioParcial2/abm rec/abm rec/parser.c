#include "parser.h"
#include<stdio.h>
int parserRead(ArrayList* this)
{
    char id[5];
    char nombre[50];
    char apellido[50];
    char dni[44];

    eCliente* aux;
    int leidos;
    if(this!=NULL)
    {
        FILE* pFile;
        pFile=fopen("data.csv","r");
        if(pFile!=NULL)
        {
            do
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,apellido,dni);
                if(leidos==4)
                {
                    aux=constructor();
                    if(aux!=NULL)
                    {
                        set_id(aux,atoi(id));
                        set_nombre(aux,nombre);
                        set_apellido(aux,apellido);
                        set_dni(aux,atoi(dni));
                        this->add(this,aux);
                    }
                }
            }
            while(!feof(pFile));
            printf("\nArchivo leido con exito\n");
            system("cls");
        }
        else
        {
            printf("\nArchivo no encontrado\n");
            system("cls");
        }
        fclose(pFile);
    }
}


void parserWrite(ArrayList* this)
{
    int i;
    eCliente* aux;
    FILE* pFile;
    pFile=fopen("data.csv","w");
    if(pFile!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%s,%d\n",get_id(aux),get_nombre(aux),get_apellido(aux),get_dni(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}
