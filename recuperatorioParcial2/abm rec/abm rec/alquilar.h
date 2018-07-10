#include "ArrayList.h"
typedef struct
{
    int id;
    char equipo[50];
    int tiempo;
}eAlquilado;
int compare_idAlquilado(ArrayList* this,int id);
void terminarAlquiler(ArrayList* alquiler, ArrayList* alquilado,ArrayList* listaclientes);
eAlquilado* constructorAlquilado();
int devolverDias(eAlquilado* aux);
void mostrarTodoTest(ArrayList* this);
void mostraUnoTest(eAlquilado* p,ArrayList* this);

