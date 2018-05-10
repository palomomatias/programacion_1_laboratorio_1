#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define tamPropetarios 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0
#include <ctype.h>
typedef struct {

    int idPropetario;
    char nombre[50];
    int estado;
    char direccion [50];
    int numeroTarjetaCredito;


}ePropetarios;
#endif
char auxiliar[tamPropetarios][50];
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoPropetario (ePropetarios listado[], int limite);
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
int buscarLugarLibre(ePropetarios listado[],int limite);
/** \brief doy de alta
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \return int
 *
 */
int altaPropetario(ePropetarios  listado[],int limite);
/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
void mostrarPropetario (ePropetarios mostrar [],int limite);
/** \brief doy de baja
 *
 * \param [] ePropetarios listado
 * \param limite int
 * \return void
 *
 */
void darDebajaPropetario(ePropetarios listado [],int limite);
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
/** \brief valido las entradas de string
 *
 * \param listado ePropetarios
 * \param auxString char
 * \return char
 *
 */
char validaStringEnter(ePropetarios listado ,char auxString);
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
int menu(ePropetarios listado[],int limite);
