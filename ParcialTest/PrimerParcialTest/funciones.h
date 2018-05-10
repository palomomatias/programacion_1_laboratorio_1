#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define tamUsuarios 100
typedef struct {

    char nombre[50];
    int estado;
    int idUsuario;

}eUsuario;
#endif
char auxiliar[tamUsuarios][50];
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
int inicializadorEstadoUsuario (eUsuario listado[], int limite);
/** \brief inicializo el hardocodeo de usuarios
 *
 * \param usuarios[] eUsuario
 * \return void
 *
 */
void inicializarUsuariosHardCode(eUsuario usuarios[]);
/** \brief busco un lugar libre
 *
 * \param listado[] eUsuario
 * \param limite int limite
 * \return int
 *
 */
int buscarLugarLibre(eUsuario listado[],int limite);
/** \brief doy de alta
 *
 * \param listado[] eUsuario
 * \param limite int
 * \return int
 *
 */
int alta(eUsuario  listado[],int limite);
/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
void mostrarPersonas (eUsuario mostrar [],int limite);
/** \brief doy de baja
 *
 * \param [] eUsuario listado
 * \param limite int
 * \return void
 *
 */
void darDebaja(eUsuario listado [],int limite);
/** \brief busco el siguiente id autoincremental
 *
 * \param listado[] eUsuario
 * \param limite int
 * \return int
 *
 */
int siguienteId(eUsuario listado[],int limite);
/** \brief ordeno por nombre los usuarios
 *
 * \param [] eUsuario listado
 * \param limite int
 * \return void
 *
 */
void ordenarPorNombre(eUsuario listado [],int limite);
/** \brief valido las entradas de string
 *
 * \param listado eUsuario
 * \param auxString char
 * \return char
 *
 */
char validaStringEnter(eUsuario listado ,char auxString);
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
 * \param listado[] eUsuario
 * \param limite int
 * \param id int
 * \return int
 *
 */
int buscarPorId(eUsuario listado[] ,int limite, int id);
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
 * \param listado[] eUsuario
 * \param limite int
 * \return int
 *
 */
int menu(eUsuario listado[],int limite);

