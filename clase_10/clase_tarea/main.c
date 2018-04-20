#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

//int buscarLegajo(int legajos [],int tam,int leg);
int main()
{
    int legajos [T]={1,2,3,4,5};
    char vectorString[T][30]={"juan","ana","maria","pedro","lucia"};
    float vectorFloat[T]={5.3,2.2,6.9,4.1,2.21};
    int i;
    int j;
    char auxiliar [30];
    int auxiliarInt;
    float auxiliarFlo;

    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(vectorString[i],vectorString[j])>0)
            {

           strcpy(auxiliar,vectorString[i]);
           strcpy(vectorString[i],vectorString[j]);
           strcpy(vectorString[j],auxiliar);

                }
                if(legajos[i]>legajos[j])
                {
                    auxiliarInt=legajos[i];
                    legajos[i]=legajos[j];
                    legajos[j]=auxiliarInt;
                }
                if(vectorFloat[i]>vectorFloat[j])
                {
                    auxiliarFlo=vectorFloat[i];
                    vectorFloat[i]=vectorFloat[j];
                    vectorFloat[j]=auxiliarFlo;
                }
        }
    }
        for(i=0;i<5;i++)
            {
                printf("%s %d %.2f \n",vectorString[i],legajos[i],vectorFloat[i]);
            }

return 0;
}


