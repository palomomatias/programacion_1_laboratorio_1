#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 7
#define OCUPADO 8
#define BORRADO 9
#include <ctype.h>
#define EGRESADO 6

typedef struct {

    int idPropetario;
    char nombre[50];
    int estado;
    char direccion [50];
    char numeroTarjetaCredito[50];
    int edad;


}ePropetarios;
#endif

char auxiliar[][50];
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoUsuario (ePropetarios listado[], int limite);
/** \brief inicializo el hardocodeo de usuarios
 *
 * \param usuarios[] ePropetarios
 * \return void
 *
 */
void inicializadorHardcodeoPropetario(ePropetarios usuarios[]);
/** \brief busco un lugar libre
 *
 * \param listado[] ePropetarios
 * \param limite int limite
 * \return int
 *
 */
int buscarLugarLibre(ePropetarios listado[],int limitse);
/** \brief doy de alta
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \return int
 *
 */

/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
void mostrarPersonas (ePropetarios mostrar [],int limite);
/** \brief doy de baja
 *
 * \param [] ePropetarios listado
 * \param limite int
 * \return void
 *
 */

/** \brief busco el siguiente id autoincremental
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \return int
 *
 */
int siguienteId(ePropetarios listado[],int limite);
/** \brief ordeno por nombre los usuarios
 *
 * \param [] ePropetarios listado
 * \param limite int
 * \return void
 *
 */
void ordenarPorNombre(ePropetarios listado [],int limite);

/** \brief pide entero
 *
 * \param
 * \param
 * \return
 *
 */
int getInt (char mensaje[],int x);
/** \brief pido un string
 *
 * \param
 * \param
 * \return
 *
 */
char pedirMensaje (char mensaje[], char auxiliarChar[]);
/** \brief busco el id
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \param id int
 * \return int
 *
 */
int buscarPorId(ePropetarios listado[] ,int limite, int id);
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
/** \brief muestro el menu s
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \return int
 *
 */


