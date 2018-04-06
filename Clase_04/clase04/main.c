#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

/*
reglas: dentro del main llamar la funcion, afuera de main definir la estructucra y hacer codigo logico
void: no retorna nada
1) prototipo firma de la funcion que es unica no puede haber 2 iguales, esta compuesta por el tipo de dato. arriba del main tengo
que poner la firma de la funcion
2) invocacion
3) definir la funcionalidad que va a hacer en la funcion punto y coma se lo saco y habro llaves
void saludar(void);prototipo (firma)de la funcion
int main()
{
    saludar();invocacion
    return 0;
}
void saludar(void)desarrolar o implementar(logica) la funcion
{
    printf("Hola mundo\n");
}
*/



int main()
{
int numero;
numero=getEntero("ingrese su edad","reingrese su edad",199,1);
printf("el entero ingresado es : %d",numero);

/*
   int numero;
   numero=getEntero("ingrese su edad",199,1);
   printf("en entero ingresado es : %d",numero);*/

/*
   numero=sumar(3,3);
   printf("%d\n",numero);
   float numero2;
   numero2=dividirEnteros(10,3);
   printf("%f\n",numero2);
   int sePudo;
   sePudo=pedirNumeroPar();
   if(sePudo==0)
   {
    printf("ok");
   }
   else
    {
    printf("mal");
   }
*/
    return 0;
}// del main


