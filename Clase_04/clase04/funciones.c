#include "Funciones.h"
#include <stdio.h>

/** \brief max,mim y validar
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param maximo int
 * \param minimo int
 * \return int
 *
 */
int getEntero(char* mensaje,char* mensajeError, int maximo, int minimo)
 {
     int entero=-1;
     do{
        printf("%s",mensaje);
        scanf("%d",&entero);
        if(entero<maximo&&entero>minimo)
        {
            break;
        }
        else
        {printf("%s",mensajeError);}

        }while(0);
        return entero;


 }

/*int getEntero(char* mensaje,int maximo, int minimo)
{
    int entero;
    do{
        printf("%s",mensaje);
        scanf("%d",&entero);
    }while(entero< minimo || entero>maximo);
    return entero;
}*/
/** \brief
 *
 * \param numeroUno int
 * \param numeroDos int
 * \return int
 *
 */
int sumar(int numeroUno,int numeroDos)
{
    int resultado=0;
    resultado= numeroUno+numeroDos;
    return resultado;
}
/** \brief
 *
 * \param dividiendo int
 * \param divisor int
 * \return float
 *
 */
float dividirEnteros(int dividiendo,int divisor)
{
   float resultado=0;
   resultado=(float)dividiendo/divisor;
   return resultado;
}

/** \brief
 *
 * \return int
 *
 */
int pedirNumeroPar()
{
    int respuesta=-1;
    int numero;
    printf("ingrese un numero");
    scanf("%d",&numero);

    if(numero%2==0 && numero!=0)
    {
        respuesta=0;
    }

    return respuesta;


}
