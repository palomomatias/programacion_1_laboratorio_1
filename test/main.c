#include <stdio.h>
#include <stdlib.h>
#include "letras.h"
#include "ArrayList.h"
#include "utn.h"
#include "numeros.h"
int main()
{
    ArrayList* letras=al_newArrayList();
    ArrayList* A=al_newArrayList();
    ArrayList* numero=al_newArrayList();
    ArrayList* clonado=al_newArrayList();
    ArrayList* filtrado=al_newArrayList();
    int idLetras=0;
     char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  alta \n");
        printf(" 2-  mostrar \n");
        printf(" 3-  baja \n");
        printf(" 4-  listar borrados\n");
        printf(" 5-  modificar\n");
        printf(" 6-  ordenar por dni\n");
          printf(" 9-  Salir\n");
        opcion=getValidInt("ingrese una opcion\n","error reingrese una opcion del 1 a 9\n",1,15);

        switch(opcion)
        {
        case 1:
letras_parseIn(letras,"datos.csv",&idLetras);
         //  letra_evaluate(letras);
         completar(letras);
letra_mostrarLista(letras);
getch();
            break;
        case 2:
            // nuevaCadena(letras,A,B);
            filtro(letras,A);
            break;
        case 3:
            parserRead(numero);
         // numero->sort(numero,compararNumeros,0);

printAll(numero);
            break;
        case 4:

//clonado=al_clone(numero);
repetidos(numero,clonado,filtrado);


            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 11:
            seguir = 'n';
            break;

        }
        system("pause");
        system("cls");
    }
return 0;
}
