#include "propetario.h"




typedef struct
{

    int idIngreso;
    int idPropetario;
    int estado;
    int marca;
    char nombreMarca[50];
    char patente[50];


}eCoches;


/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoCoches(eCoches listado[], int limite);
/** \brief inicializo el hardocodeo de usuarios
 *
 * \param usuarios[] eCoches
 * \return void
 *
 */
void inicializadorHardcodeoCoches(eCoches usuarios[]);
/** \brief busco un lugar libre
 *
 * \param listado[] eCoches
 * \param limite int limite
 * \return int
 *
 */
int buscarLugarLibreCoches(eCoches listado[],int limitse);
/** \brief doy de alta
 *
 * \param listado[] eCoches
 * \param limite int
 * \return int
 *
 */
int altaCoches(eCoches  listado[],int limite,ePropetarios listaPropetarios [],int limite2);
/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
int mostrarCoches (eCoches mostrar [],int limite);
/** \brief doy de baja
 *
 * \param [] eCoches listado
 * \param limite int
 * \return void
 *
 */
void darDebajaCoches(eCoches listado [],int limite);
/** \brief busco el siguiente id autoincremental
 *
 * \param listado[] eCoches
 * \param limite int
 * \return int
 *
 */
int siguienteIdCoches(eCoches listado[],int limite);
/** \brief ordeno por nombre los usuarios
 *
 * \param [] eCoches listado
 * \param limite int
 * \return void
 *
 */
void ordenarPorCoches(eCoches listado [],int limite);


/** \brief busco el id
 *
 * \param listado[] eCoches
 * \param limite int
 * \param id int
 * \return int
 *
 */
int buscarporIdCoches(eCoches listado[] ,int limite, int id);
char cambiarMarcas(eCoches listado[],int marca,char nombreMarca[]);
void mostrarAuto (eCoches mostrar [],int limite);
int buscarPropetarioConAuto(eCoches listaCoches[],ePropetarios listaPropetario[],int tamPropetarios,int TamCoches,int idcoches);


