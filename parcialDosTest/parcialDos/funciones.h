#include "Arraylist.h"
typedef struct
{
    int dni;
    char nombre[50];
    int idTurno;
    int estado;
}eTramite;

eTramite* etramite_new();
int setDni(eTramite* tramite,int dni);
int setNombre(eTramite* tramite,char* nombre);
int setidTurno(eTramite* tramite,int turno);
int getDni(eTramite* tramite);
char* getNombre(eTramite* tramite);
int getidTurno(eTramite* tramite);
int siguienteTurno(ArrayList* this);

int validar_numero(char numero[]);
int validarPalabra(char palabra[]);
int validarPalabra(char palabra[]);
int compararChar(void* characterA,void* characterB);
int compararInt(void* enteroA ,void* enteroB);
void mostrarTodo(ArrayList* this);
int altaTramite(ArrayList* this);
int atenderTramite(ArrayList* thisPendiendtes, ArrayList* thisAtendidos);
int mostrarTramites(ArrayList* this);
int mostrarUno(eTramite* this);
int idAutoIncremental(ArrayList* this,eTramite* aux);
