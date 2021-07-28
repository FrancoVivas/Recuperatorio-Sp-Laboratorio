/*
 * Parser.h
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "libro.h"
/** \brief Parsea los datos los datos de los libros desde el archivo ingresado por el usuario
 *
 * @param path char* archivo que contiene los datos a parsear
 * @param pArrayListBook LinkedList* Array de tipo LinkedList.
 * @return int retorna 0 si los datos se fueron parseados, y -1 sino se parsearon
 *
 */
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook);

#endif /* PARSER_H_ */
