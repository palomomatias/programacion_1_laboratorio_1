#include"funciones.h"
#include"ArrayList.h"
typedef struct
{

    int id;
    char equipo[50];
    int idCliente;
    int tiempo;
}nuevoAlquiler;

nuevoAlquiler* constructorAlquiler();
void set_alquilerId(nuevoAlquiler* this, int dato);
void set_alquilerIdPro(nuevoAlquiler* this, int dato);
void set_alquilerTiempo(nuevoAlquiler* this, int dato);
void set_alquilerNombre(nuevoAlquiler* this, char dato[]);
int get_alquilerId(nuevoAlquiler* this);
int get_alquilerTiempo(nuevoAlquiler* this);
int get_alquilerIdPro(nuevoAlquiler* this);
char* get_alquilerEquipo(nuevoAlquiler* this);
void mostrarAlquiler(ArrayList* this, ArrayList* clientes);
void mostraUnoAlquiler(nuevoAlquiler* p,ArrayList* this,eCliente* c);
int compareIdCliente(ArrayList* this,void* elemento);
void altaAlquiler(ArrayList* alquiler,ArrayList* alquilado,ArrayList* listaCliente);
void idAutoIncrementalAlquiler(ArrayList* this, nuevoAlquiler* aux,ArrayList* alquilado);
int pedirEquipo(nuevoAlquiler* aux);
