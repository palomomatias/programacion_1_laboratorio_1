
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0
#include <ctype.h>
#define TAMPRODUCTOS 10
typedef struct {

    char descripcion[50];
    int estado;
    int codigoProducto;
    int cantidad;
    int importE;

}eProducto;
char auxiliar[TAMPRODUCTOS][50];
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoProducto (eProducto listado[], int limite);
/** \brief inicializo el hardocodeo de usuarios
 *
 * \param usuarios[] eProducto
 * \return void
 *
 */
void inicializarUsuariosHardCode(eProducto usuarios[]);
/** \brief busco un lugar libre
 *
 * \param listado[] eProducto
 * \param limite int limite
 * \return int
 *
 */
int buscarLugarLibreProducto(eProducto listado[],int limite);
/** \brief doy de alta
 *
 * \param listado[] eProducto
 * \param limite int
 * \return int
 *
 */
int altaProducto(eProducto  listado[],int limite);
/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
void mostrarProducto (eProducto mostrar [],int limite);
/** \brief doy de baja
 *
 * \param [] eProducto listado
 * \param limite int
 * \return void
 *
 */
void darDebajaProducto(eProducto listado [],int limite);
/** \brief busco el siguiente id autoincremental
 *
 * \param listado[] eProducto
 * \param limite int
 * \return int
 *
 */
int siguienteCodigoProducto(eProducto listado[],int limite);
/** \brief ordeno por nombre los usuarios
 *
 * \param [] eProducto listado
 * \param limite int
 * \return void
 *
 */
void ordenarPorNombre(eProducto listado [],int limite);
/** \brief valido las entradas de string
 *
 * \param listado eProducto
 * \param auxString char
 * \return char
 *
 */
char validaStringEnter(eProducto listado ,char auxString);
/** \brief pide entero
 *
 * \param
 * \param
 * \return
 *
 */
int getInt (char mensaje[]);
/** \brief pido un string
 *
 * \param
 * \param
 * \return
 *
 */
char getChar (char mensaje[], char auxiliarChar[]);
/** \brief busco el id
 *
 * \param listado[] eProducto
 * \param limite int
 * \param id int
 * \return int
 *
 */
int buscarPorCodigoProducto(eProducto listado[] ,int limite, int id);
/** \brief valido que sean solo palabras
 *
 * \param palabra[] char
 * \return int
 *
 */
int validarPalabra(char palabra[]);
/** \brief valido que sean solos numeros
 *
 * \param numero[] char
 * \return int
 *
 */
int validar_numero(char numero[]);
void modificarProductos(eProducto listado[],int limite);
