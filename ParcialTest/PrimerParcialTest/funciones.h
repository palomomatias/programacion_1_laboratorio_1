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

