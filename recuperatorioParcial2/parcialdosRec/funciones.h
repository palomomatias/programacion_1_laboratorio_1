#include "ArrayList.h"
typedef struct
{
    int edad;
    char nombre[50];
    int id;
    char profesion[50];
    float sueldo;
}eTramite;

eTramite* constructor();
char* get_nombre(eTramite* this);
float get_salario(eTramite* this);
int get_edad(eTramite* this);
char* get_profesion(eTramite* this);

void mostrarTodo(ArrayList* this);
void mostraUno(eTramite* this);
int funcionQueFiltra(void* elemento);
void set_id(eTramite* this, int id);
void set_name(eTramite* this, char name[]);
void set_sueldo(eTramite* this, float sueldo);
void set_edad(eTramite* this, int edad);
void set_profesion(eTramite* this, char profesion[]);
