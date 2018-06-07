#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    pFile=fopen("data.csv",r);
    char isEmptyString[];
    int isEmpty;
    int largo;
    char nombre[];
    char Apellido[];
    int id;
    Employee *pAuxiliar;
    if(pFile == NULL)


    {

        printf("archivo no cargado")
    }
    else
    {
        do
        {

            largo=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,isEmptyString);
            if(largo==4)
            {
            pAuxiliar=(Employee*)malloc(sizeof(Employee)*1);
            pAuxiliar->id=;
            strcpy(pAuxiliar->name,nombre);
            strcpy(pAuxiliar->lastName,apellido);



            }


        }
        while(!feof(pFile));
    }


    return 0;
}
