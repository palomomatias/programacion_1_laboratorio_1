#include <stdio.h>
#include <stdlib.h>
#define TAM 4
#include<string.h>

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
void modificarAlumno(int[], char[][20], int[], int[], float[], int);
void darDeBaja(int[], char[][20], int[], int[], float[], int);


int main()
{
    int legajo[TAM]= {1,55};
    char nombre[TAM][20]={"jose","maria"};
    int nota1[TAM]={4,3};
    int nota2[TAM]={4,3};
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    int j;
    char auxiliarChar [30];
    int auxiliarInt;

   do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
    system("/usr/bin/clear");
            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {system("/usr/bin/clear");
                printf("Alumno ingresado\n");

            }

            break;
        case 2:
system("/usr/bin/clear");

        mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);

            break;
        case 3:
system("/usr/bin/clear");
        modificarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);

            break;
        case 4:

            break;
        case 5:
                         for(i=0;i<TAM;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(strcmp(nombre[i],nombre[j])>0)
            {

           strcpy(auxiliarChar,nombre[i]);
           strcpy(nombre[i],nombre[j]);
           strcpy(nombre[j],auxiliarChar);

           auxiliarInt=legajo[i];
           legajo[i]=legajo[j];
           legajo[j]=auxiliarInt;

            auxiliarInt=nota1[i];
           nota1[i]=nota1[j];
           nota1[j]=auxiliarInt;

            auxiliarInt=nota2[i];
           nota2[i]=nota2[j];
           nota2[j]=auxiliarInt;

            auxiliarInt=promedio[i];
            promedio[i]=promedio[j];
            promedio[j]=auxiliarInt;
                }

        }
        }
            for(i=0;i<TAM;i++)
            {
                if (legajo[i]!=0)
                {
                    printf("nombre:%s legajo:%d NotaUno:%d NotaDos:%d Promedio:%.2f\n",nombre[i], legajo[i], nota1[i], nota2[i], promedio[i] );
                }
            }
            break;
        }

    }
    while(opcion!=9);

    return 0;
}


int buscarLibre(int legajo[], int tam)
{
    int i;
    int index=-1;
    for (i=0;i<tam;i++)
    {
        if (legajo[i]==0)
        {
          index=i;
          break;
        }
    }

    return index;
}

int cargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{

    int index ;


    index = buscarLibre(legajo, tam);
            if(index!=-1)
            {
    printf("ingrese un legajo\n",legajo);
    scanf("%d",&legajo[index]);
    printf("ingrese su nombre\n",nombre);
    //fflush(stdin);
    scanf("%*c%[^\n]",nombre[index]);
    printf("ingrese nota1\n",nota1);
    scanf("%d",&index[nota1]);
    printf("ingrese su nota2\n",nota2[index]);
    scanf ("%d",&index[nota2]);
    promedio[index]=calcularPromedio(nota1[index],nota2[index]);

//fgets( &nombre, 30, stdin );
            }

            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajo[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{


    int i;
    for(i=0; i<tam; i++)
            {
                if(legajo[i]!=0)
                {
                    printf("legajo:%d nombre:%s NotaUno:%d NotaDos:%d Promedio:%.2f\n", legajo[i], nombres[i], nota1[i], nota2[i], promedio[i] );

                }
            }


}

void modificarAlumno(int legajo[], char nombre [][20], int nota1[], int nota2[], float promedio[], int tam)
{
   int opcion;
   int opcionLegajo;
   char nombreAux[30];
   int i;
   int auxNota;
//system("/usr/bin/clear");//para linux es esto
/*for (j=0;j<TAM;j++)
{}*/
mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);

printf("ingrese el legajo que quiere modificar \n",opcionLegajo);
    scanf("%d",&opcionLegajo);

/* while(opcionLegajo!=legajo[j])
    {
            printf ("el legajo no existe REINGRESAR \n",opcionLegajo);
    scanf("%d",&opcionLegajo);
    }*/
for (i=0;i<TAM;i++)
{
   if (opcionLegajo==legajo[i])
   {printf("que desea modiicar?\n 1-NOMBRE \n 2-NOTAUNO \n 3-NOTADOS \n Elija una opcion: ");
    scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Su nombre actual es %s ingrese su nuevo nombre: \n",nombre[i],nombreAux);

            scanf("%*c%[^\n]",nombreAux);
            strcpy(nombre[i],nombreAux);
            printf("Su nuevo nombre es %s\n",nombre[i]);
               break;
        case 2:
            printf("su nota acutal es: %d ingrese se nueva nota:",nota1[i]);
            scanf("%d",&auxNota);
            while(auxNota>11&&auxNota<0)
            {
                printf("reingrese su nota entre 1 y 10:\n");
                scanf("%d",&auxNota);
            }
            nota1[i]=auxNota;
            printf("se a cambiado correcatamente la nota uno\n");



            break;
        case 3:
                       printf("su nota acutal es: %d ingrese se nueva nota:",nota2[i]);
            scanf("%d",&auxNota);
            while(auxNota>11||auxNota<0)
            {
                printf("reingrese su nota entre 1 y 10:\n");
                scanf("%d",&auxNota);
            }
            nota2[i]=auxNota;
            printf("se a cambiado correcatamente la nota dos\n");
                    break;
        }

   }
   }

}




