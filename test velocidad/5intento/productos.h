#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define tamProductos 20

   typedef struct
    {
      int codigoProducto;
      char descripcion[256];
        int importe;
      int estado;
      int cantidad;

    }eProducto;
char auxiliar[50];
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
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoProducto (eProducto listado[], int limite);
/** \brief busco un lugar libre
 *
 * \param listado[] eUsuario
 * \param limite int limite
 * \return int
 *
 */
int buscarLugarLibre(eProducto listado[],int limite);
/** \brief busco el siguiente id autoincremental
 *
 * \param listado[] eUsuario
 * \param limite int
 * \return int
 *
 */
int siguienteIdProducto(eProducto listado[],int limite);
/** \brief doy de alta
 *
 * \param listado[] eUsuario
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
/** \brief modifico producto
 *
 * \param [] eProducto listado
 * \param limite int
 * \return void
 *
 */
void modificarProducto(eProducto listado [],int limite);

int buscarPorCodigoProducto(eProducto listado[],int limite, int id);
