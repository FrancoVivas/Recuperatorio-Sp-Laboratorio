/*
 * Controller.h
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"
/** \brief Carga los datos de los libros desde el archivo ingresado por el usuario.
 *
 * @param path char* recibe el archivo de texto a leer
 * @param pArrayListBooks LinkedList* array de tipo LinkedList
 * @return int retorna 0 si se pudo leer el archivo de texto, y -1 sino se leyo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBooks);
/** \brief Muestra en pantalla los libros
 *
 * @param pArrayListBooks LinkedList* Array de tipo LinkedList.
 * @return int retorna 0 si se mostraron los libros y -1 sino hay libros a mostrar
 *
 */
int controller_ListBooks(LinkedList* pArrayListBooks);
/** \brief Ordena a los libros
 *
 * @param pArrayListBooks LinkedList*  LinkedList* Array de tipo LinkedList.
 * @return int retorna 0 si se ordeno y - 1 sino se ordeno
 *
 */
int controller_sort (LinkedList* pArrayListBooks);
/** \brief Guarda los datos de la estructura en el archivo mapeado.csv (modo texto).
 *
 * @param path char* Path archivo donde se guardaran los datos
 * @param pArrayListBooks LinkedList* Array de tipo LinkedList.
 * @return int retorna 0 si se guardo el archivo y -1 sino se guardo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBooks);

#endif /* CONTROLLER_H_ */
