#include <stdio.h>
#include <stdlib.h>

int main()
{
     //int vector [5]={5,2,9,6,5};
    char vector[5]={'w','a','v','e','b'};
    int i;
    char auxiliar;
    int j;
    for(i=0;i<4;i++)/*se pone cuando i-1*/
    {
        for(j=i+1;j<5;j++)/* para que no se repita es j+1*/
        {
            if(vector[i]>vector[j])//criterio de ordenamiento
            {
                auxiliar=vector[i];
                vector[i]=vector[j];
                vector[j]=auxiliar;

            }
        }

    }

                for(i=0;i<5;i++)
            {
                printf("%c\n",vector[i]);
            }

    /*int a=9;
    int b=5;
    int c;
   //swap
    c=a;
    a=b;
    b=c;
    printf("a=%d--b=%d--c=%d",a,b,c);*/

    return 0;
}
