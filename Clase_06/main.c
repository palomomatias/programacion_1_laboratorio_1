#include <stdio.h>
#include <stdlib.h>
/*




*/
int contarPares(int[],int);/*parametros actuales*/
int buscarChar(char[],int,char);



int main()
{
    int vector [5]={5,2,9,6,5};
    int a=9;
    int b=5;
    int c;
   //swap
    c=a;
    a=b;
    b=c;


    char letras [5]={'f','g','l','a','q'};
    int cantidad;
    int indexLetra;
    cantidad=contarPares(vector,5);
    indexLetra=buscarChar(letras,5,'a');
    if(indexLetra==-1)
    {
        printf("no se encuentra el caracter\n");
    }
    else
    {
        printf("el caracter se encuentra en el array\n");
    }

    printf("Cantidad de pares: %d\n",cantidad);

    return 0;
}
int contarPares(int array[],int cantidad)/*parametros formales*/
{
    int contadorPares=0;
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(array[i]%2==0)
        {
            contadorPares ++;
        }
    }
    return contadorPares;
}
int buscarChar(char array[],int cantidad,char caracter)/*sirve para enteros*/
{
    int index=-1;
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(array[i]==caracter)
        {
            index = i;
            break;
        }
    }
    return index;
}
