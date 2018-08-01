#include"ArrayList.h"
#ifndef NUMERONATURAL_H_INCLUDED
#define NUMERONATURAL_H_INCLUDED

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
}numeroNatural;

#endif // NUMERONATURAL_H_INCLUDED

/** \brief Funcion que reserva espacio en memoria para una nueva estructura
 *
 * \return numeroNatural* Puntero a la nueva estructura
 *
 */
numeroNatural* constructor();


//-----------------------------------------------------------------------------------------------------------------------------\\

/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_numero(numeroNatural* this, int dato);


/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_par(numeroNatural* this, int dato);



/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_impar(numeroNatural* this, int dato);

/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_primo(numeroNatural* this, int dato);

/** \brief Funcion que guarda un string en una variable estruturada
 *
 * \param this numeroNatural* Variable en la que se guardara el string
 * \param dato[] char String a guardar
 * \return int
 *
 */
int set_nombre(numeroNatural* this, char nombre[]);



/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_numero(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_par(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_impar(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_primo(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo cadena de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo cadena
 * \return char* String obtenido
 *
 */
char* get_nombre(numeroNatural* this);
void parserRead(ArrayList* this);
void printAll(ArrayList* this);
void printOne(numeroNatural* this, int id);
void repetidos(ArrayList* this,ArrayList* clonado,ArrayList* repetido);
int compararNumeros(void* numero1, void* numero2);
int comprobarRepetidos(ArrayList* repetidos,numeroNatural* numero);
