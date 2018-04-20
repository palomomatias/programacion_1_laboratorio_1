#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);


int main()
{
    int legajo[TAM]= {55,20};
    char nombre[TAM][20]={"jose","maria"};
    int nota1[TAM]={4,3};
    int nota2[TAM]={4,3};
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado\n");
            }
            break;
        case 2:

        mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);


        break;
        case 3:

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
    scanf("%d",&index[legajo]);
    printf("ingrese su nombre\n",nombre);
    fflush(stdin);
    gets(index[nombre]);
    printf("ingrese nota1\n",nota1);
    scanf("%d",&index[nota1]);
    printf("ingrese su nota2\n",nota2[index]);
    scanf ("%d",&index[nota2]);
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
                    printf("%d %s %d %d %f\n", legajo[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}

