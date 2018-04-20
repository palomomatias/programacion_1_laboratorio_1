#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

int buscarInt (int[],int,int);
int main()
{
    int legajos [T]={1,2,3,4,5};
    char vectorString[T][30]={"juan","ana","maria","pedro","lucia"};
    float vectorFloat[T]={5.3,2.2,6.9,4.1,2.21};
    int i;
    int j;
    char auxiliar [20];
    int auxiliarInt;
    int auxInt;
    float auxiliarFlo;

                auxInt=buscarInt(legajos,T,3);
             if(auxInt!=-1)

             {printf("\indice: %d \n",auxInt);
             }
             else
             {
                 printf("legajo inexistente\n");
             }


    for(i=0;i<T;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(strcmp(vectorString[i],vectorString[j])>0)
            {

           strcpy(auxiliar,vectorString[i]);
           strcpy(vectorString[i],vectorString[j]);
           strcpy(vectorString[j],auxiliar);

           auxiliarInt=legajos[i];
           legajos[i]=legajos[j];
           legajos[j]=auxiliarInt;

           auxiliarFlo=vectorFloat[i];
           vectorFloat[i]=vectorFloat[j];
           vectorFloat[j]=auxiliarFlo;

                }

        }
    }
        for(i=0;i<5;i++)
            {
                printf("%s -- %d -- %.2f \n",vectorString[i],legajos[i],vectorFloat[i]);
            }





return 0;
}



int buscarInt (int enteros [],int tam,int cual)
   {
       int indice=-1;
       int i;
       for(i=0;i<tam;i++)
       {
           if(enteros[i]==cual)

           {
               indice=i;
               break;
           }
       }
   return indice;
    }

