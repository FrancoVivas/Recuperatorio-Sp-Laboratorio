/*
 * libro.c
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */


#include "libro.h"

eLibro* eLibro_new()
{
    eLibro* pAuxBook;

    pAuxBook = (eLibro*)malloc(sizeof(eLibro));

    return pAuxBook;
}
void eLibro_delete(eLibro *this)
{

    if(this != NULL)
    {
        free(this);
    }
}
eLibro* eLibro_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial)
{
    eLibro* this = eLibro_new();
    void *retorno = NULL;
    if(this != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && editorial != NULL)
    {
    	if(!eLibro_setId(this, atoi(id)) &&
    	!eLibro_setTitulo(this, titulo) &&
    	!eLibro_setAutor(this, autor) &&
		!eLibro_setPrecio(this,atof(precio)) &&
    	!eLibro_setEditorial(this, atoi(editorial)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		eLibro_delete(this);
    		retorno = this;
    	}

    }
    return retorno;
}
int eLibro_setId(eLibro* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0 && validarEntero(id)==0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eLibro_getId(eLibro* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eLibro_setTitulo(eLibro* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL && validarNombre(titulo, MAX_NOMBRE) == 0)
    {
    	strcpy(this->titulo, titulo);
    	retorno = 0;
    }

    return retorno;
}
int eLibro_getTitulo(eLibro* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo !=NULL)
    {

        strcpy(titulo, this->titulo);
        retorno = 0;
    }

    return retorno;
}
int eLibro_setAutor(eLibro* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor != NULL)
    {
    	if(validarNombre(autor, MAX_NOMBRE)==0)
    	{
    		strcpy(this->autor, autor);
    		retorno = 0;
    	}
    }

    return retorno;
}
int eLibro_getAutor(eLibro* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor !=NULL)
    {
        strcpy(autor, this->autor);
        retorno = 0;
    }

    return retorno;
}
int eLibro_setPrecio(eLibro* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0 && validarFlotante(precio)==0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}
int eLibro_getPrecio(eLibro* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}
int eLibro_setEditorial(eLibro* this,int editorial)
{
    int retorno = -1;

    if(this != NULL && editorial != 0 && validarEntero(editorial)== 0)
    {
    	this->editorial= editorial;
        retorno = 0;
    }

    return retorno;
}
int eLibro_getEditorial(eLibro* this,int* editorial)
{
    int retorno = -1;

    if(this != NULL && editorial != 0)
    {
        *editorial = this->editorial;
        retorno = 0;
    }

    return retorno;
}
int eLibro_compareByAutor(void* pThis1, void* pThis2)
{
    int comparar;
    eLibro* pAuxBook1 = (eLibro*)pThis1;
    eLibro* pAuxBook2 = (eLibro*)pThis2;
    char autor1[MAX_NOMBRE];
    char autor2[MAX_NOMBRE];

    if(pAuxBook1 != NULL && pAuxBook2 != NULL)
    {
    	eLibro_getAutor(pThis1, autor1);
    	eLibro_getAutor(pThis2, autor2);
        comparar = strcmp(autor1, autor2);
    }

    return comparar;
}
int eLibro_getEditorialDetalle (eLibro* this, int editorialId,char* detalleEditorial)
{
	int retorno = -1;
	int auxId;
	if(this != NULL && detalleEditorial != NULL)
	{
		eLibro_getEditorial(this, &auxId);
		if(auxId == editorialId)
		{
			//strcpy(arrayEditorial->editorialDetalle,detalleEditorial);
			switch(editorialId)
			{
			case 1:
				strcpy(detalleEditorial,"Planeta");
				break;
			case 2:
				strcpy(detalleEditorial,"SIGLO XXI EDITORES");
				break;
			case 3:
				strcpy(detalleEditorial,"Pearson");
				break;
			case 4:
				strcpy(detalleEditorial,"Minotauro");
				break;
			case 5:
				strcpy(detalleEditorial,"Salamandra");
				break;
			case 6:
				strcpy(detalleEditorial,"Penguin Books");
				break;
			}

			retorno = 0;
		}
	}

	return retorno;
}
void eLibro_calcularDescuento(void* this)
{
	int editorial;
	float precio;
	float precioDescuento;
	if(this != NULL)
	{
		eLibro_getEditorial(this, &editorial);
		eLibro_getPrecio(this, &precio);

		if(editorial == 1 && precio >= PRECIO_1)
		{
			precioDescuento = precio - (precio * DESCUENTO_1);
			eLibro_setPrecio(this, precioDescuento);
		}
		if(editorial == 2 && precio <= PRECIO_2)
		{
			precioDescuento = precio - (precio * DESCUENTO_2);
			eLibro_setPrecio(this, precioDescuento);

		}
	}
}
