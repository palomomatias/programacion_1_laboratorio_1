#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
int mostrar;
int i;
ArrayList* lista;
lista=al_newArrayList();
Employee* e1;
Employee* e2;
e1=(Employee*)malloc(sizeof(Employee)*1);
e1->id=666;
strcpy(e1->name,"pedro");
strcpy(e1->lastName,"gomez");
e1->isEmpty=1;
al_add(lista,e1);


Employee* aux;// no se necesita hacer otro malloc
/*aux=(Employee*)al_get(lista,0);
employee_print(aux);
*/
e2=(Employee*)malloc(sizeof(Employee)*1);
e2->id=111;
strcpy(e2->name,"juan");
strcpy(e2->lastName,"jose");
e2->isEmpty=1;
al_add(lista,e2);
mostrar= al_len(lista);
// no se necesita hacer otro malloc
al_sort(lista,employee_compare,1);
for(i=0;i<mostrar;i++)
{aux=(Employee*)al_get(lista,i);
employee_print(aux);
}

printf("size del array %d",mostrar);
    return 0;
}
