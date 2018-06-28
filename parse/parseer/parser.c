#include<string.h>
#include<stdio.h>
#include"parser.h"
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
void parserRead(char archivo[],ArrayList* this)
{
    char nombre[100];
    char mail[100];
    int cantLeidos;
    int i=0;
    destinatario* aux;
    FILE* pFile;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL)
    {
        do
        {
            cantLeidos=fscanf(pFile,"%[^,],%[^,\n]\n",nombre,mail);
            if(cantLeidos==2)
            {
                aux=(destinatario*)malloc(sizeof(destinatario));
                if(aux!=NULL)
                {
                    strcpy(aux->nombre,nombre);
                    strcpy(aux->mail,mail);
                    al_add(this,aux);

                }
            }
        }while(!feof(pFile));
        printf("Archivo cargado\n");
    }
    fclose(pFile);
}

ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra,ArrayList* listaDepurado)
{
   // ArrayList* listaDepurado;
    //listaDepurado=al_newArrayList();
    destinatario* aux;
    destinatario* auxBlack;
    int flag;
    int i;
    int j;
    if(destinatarios!=NULL&&listaNegra!=NULL)
    {
        for(i=0;i<destinatarios->len(destinatarios);i++)
        {
            flag=0;
            aux=destinatarios->get(destinatarios,i);
            for(j=0; j<listaNegra->len(listaNegra); j++)
            {
                auxBlack=listaNegra->get(listaNegra,j);
                if((strcmp(aux->mail,auxBlack->mail))==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                listaDepurado->add(listaDepurado,aux);
            }
        }
    }
    return listaDepurado;
}

void listar(ArrayList* listaDepurado)
{
    int contador=0;
    destinatario* aux;
    int i;
    for(i=0;i<listaDepurado->len(listaDepurado);i++)
    {
        aux=listaDepurado->get(listaDepurado,i);
        if(aux!=NULL)
        {
           printf("\n%s %s",aux->nombre,aux->mail);

        }
    }

}

