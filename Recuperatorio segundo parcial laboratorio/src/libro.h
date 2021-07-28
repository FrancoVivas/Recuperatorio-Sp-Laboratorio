/*
 * libro.h
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

#define MAX_NOMBRE 70
#define DESCUENTO_1 0.20
#define DESCUENTO_2 0.10
#define PRECIO_1 300
#define PRECIO_2 200

typedef struct{
	int id;
	char titulo[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precio;
	int editorial;
}eLibro;

typedef struct{
	int editorial;
	char editorialDetalle[MAX_NOMBRE];
}eEditorial;

/** brief Constructor que obtiene el espacio en memoria para los libros
 * @return retorna NULL sino se pudo reservar espacio
 */
eLibro* eLibro_new();
/** \brief Nueva estructura de Libros ingresando los valores por parametros.
 *
 * @param id parametro que recibe el ID a cargar.
 * @param titulo parametro que recibe el titulo del libro.
 * @param autor  parametro que recibe el nombre del autor.
 * @param precio  parametro que recibe el precio.
 * @param editorial  parametro que recibe la editorial.
 * @return this retorna el Libro con los datos que se recibieron por parametro, en caso contrario retorna NULL.
 *
 */
eLibro* eLibro_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial);
/** \brief Libera la memoria que se asingno a un libro
 *
 * @param this direccion de memoria de un Libro.
 *
 */
void eLibro_delete(eLibro *this);
/** \brief Coloca el ID a una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param id valor que se colocara en el ID del Libro
 * @return retorna 0 si se pudo colocar el ID, y -1 si no se coloco
 *
 */
int eLibro_setId(eLibro* this,int id);
/** \brief Obtiene el ID de una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param id puntero al ID del Libro
 * @return retorna 0 Si pudo obtener el ID y -1 si no pudo obtener el ID
 *
 */
int eLibro_getId(eLibro* this,int* id);
/** \brief Coloca el titulo del Libro en una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param titulo cadena que se colocara el titulo del Libro
 * @return retorna 0 si se pudo colocar el titulo, y -1 si no se coloco
 *
 */
int eLibro_setTitulo(eLibro* this,char* titulo);
/** \brief Obtiene el titulo del Libro de la estructura Libro.
 *
 * @param this puntero a Empleado.
 * @param titulo puntero a la cadena titulo del Libro
 * @return retorna 0 Si pudo obtener el titulo y -1 si no pudo obtener
 *
 */
int eLibro_getTitulo(eLibro* this,char* titulo);
/** \brief Coloca el nombre del autor del Libro en una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param autor cadena que se colocara el nombre del autor del Libro
 * @return retorna 0 si se pudo colocar el autor, y -1 si no se coloco
 *
 */
int eLibro_setAutor(eLibro* this,char* autor);
/** \brief Obtiene el nombre del autor del Libro de la estructura Libro.
 *
 * @param this puntero a Libro.
 * @param autor puntero a la cadena del nombre del autor del libro
 * @return retorna 0 Si pudo obtener el autor y -1 si no pudo obtener
 *
 */
int eLibro_getAutor(eLibro* this,char* autor);
/** \brief Coloca el precio del Libro en una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param precio valor que se colocara en el precio del Libro
 * @return retorna 0 si se pudo colocar el precio, y -1 si no se coloco
 *
 */
int eLibro_setPrecio(eLibro* this,float precio);
/** \brief Obtiene el precio del Libro de la estructura Libro.
 *
 * @param this puntero a Libro.
 * @param precio puntero al precio del libro
 * @return retorna 0 Si pudo obtener el precio y -1 si no pudo obtener
 *
 */
int eLibro_getPrecio(eLibro* this,float* precio);
/** \brief Coloca el ID de la editorial a una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param editorial valor que se colocara en el ID editorial del Libro
 * @return retorna 0 si se pudo colocar el ID editorial, y -1 si no se coloco
 *
 */
int eLibro_setEditorial(eLibro* this,int editorial);
/** \brief Obtiene el ID editorial de una estructura Libro.
 *
 * @param this puntero a Libro.
 * @param editorial puntero al ID editorial del Libro
 * @return retorna 0 Si pudo obtener el ID editorial y -1 si no pudo obtener el ID
 *
 */
int eLibro_getEditorial(eLibro* this,int* editorial);
/** \brief Compara elementos por el nombre
 *
 *@param pThis1 puntero a void
 *@param pThis2 puntero a void
 *@return retorna 0 si tienen el mismo nombre, -1 si el primer nombre esta primero, 1 si el segundo nombre esta primero.
 *
 */
int eLibro_compareByAutor(void* pThis1, void* pThis2);
/** \brief Obtiene el nombre de la editorial a partir del id de la editorial
 *
 * @param this puntero a Libro.
 * @param editorialId entero que contiene el id de la editorial
 * @param detalleEditorial cadena que recibe el nombre de la editorial
 * @return retorna 0 si se obutvo el nombre de la editorial, y -1 sino se obutvo
 */
int eLibro_getEditorialDetalle (eLibro* this,int editorialId,char* detalleEditorial);
/** \brief Realiza el descuento en los precios de los libros
 *
 */
void eLibro_calcularDescuento(void* this);

#endif /* LIBRO_H_ */
