#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para cadena de texto
/*
para saber donde termina una palbra es con \0 se agrega solo


*/

int main()
{
    //char palabra[15]="hola";//se puede hacer solo cuando lo declaras y es con comillas
    char palabra1[15];
    char palabra2[15];
    char buffer[1024];
    int i;
    int cant;
    int com;

    printf("ingrese una palabra\n");
    fflush(stdin);//siempre hay que vaciar el coso
    gets(buffer);//no hay que poner %s
    while(strlen(buffer)>14)
    {
         printf("ingrese una palabra\n");
    fflush(stdin);//siempre hay que vaciar el coso
    gets(buffer);//no hay que poner %s
    }


    cant=strlen(palabra1);// cuenta la cantidad de caracterer sin el espacio
    //strcpy(palabra2,palabra1);//primero destinto segundo lugar origen y se puede poner una palabra/ letra en el origen
    strcpy(palabra1,buffer);
    strcpy(palabra2,"Gato");
    strupr(palabra1);//convierte todo a mayusucula
    strlwr(palabra2);//"         " todo a minus
    //strcat(buffer,palabra2);//contatenar de a pares
    strcpy(buffer,palabra1);//cuando quiero uno solo

    com=stricmp(palabra1,palabra2);// para comparar palabras y devuelve entero

    //printf("cantidad de carateres de palabra1:%d\n",cant);
    printf("palabra 1:%s\n palabra 2 : %s \n buffer :%s\n",palabra1,palabra2,buffer);
    printf("comparacion es :%d\n",com);


    return 0;
}
