#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int estado;
    int idUsuario;

}eUsuario;
#endif
int inicializadorEstadoUsuario (eUsuario listado[], int limite);
void inicializarUsuariosHardCode(eUsuario usuarios[]);
int buscarLugarLibre(eUsuario listado[],int limite);
int alta(eUsuario  listado[],int limite);
void mostrarPersonas (eUsuario mostrar [],int limite);
void darDebaja(eUsuario listado [],int limite);
int siguienteId(eUsuario listado[],int limite);
void ordenarPorNombre(eUsuario listado [],int limite);
char validaStringEnter(eUsuario listado ,char auxString);
int getInt (char mensaje[]);
char getChar (char mensaje[], char auxiliarChar[]);
int buscarPorId(eUsuario listado[] ,int limite, int id);
int validarPalabra(char palabra[]);


