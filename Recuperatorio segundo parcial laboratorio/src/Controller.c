/*
 * Controller.c
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */


#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBooks)
{
    int verificar;
    int retorno = -1;
    FILE* file = NULL;

    if(pArrayListBooks != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	verificar = parser_BookFromText(file, pArrayListBooks);
        	if(verificar == 0)
        	{
        		retorno = 0;
        	}

        }
    }

    fclose(file);
    return retorno;
}
int controller_ListBooks(LinkedList* pArrayListBooks)
{
    int retorno = -1;
    int i;
    int pantalla = 999;
    int respuesta;
    int respuesta2;
    int id;
    char titulo[MAX_NOMBRE];
    char autor[MAX_NOMBRE];
    float precio;
    char editorial[MAX_NOMBRE];
    int editorialId;
    eLibro* pAuxLibro = eLibro_new();

    if(pArrayListBooks != NULL)
    {
    	if(ll_len(pArrayListBooks)>0)
    	{
        printf("|*******|**************************************************************|*****************|************|***********************|\n");
        printf("|   ID  |                        TITULO                                |      AUTOR      |   PRECIO   |       EDITORIAL       |\n");
        printf("|*******|**************************************************************|*****************|************|***********************|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListBooks); i++)
        {
        	pAuxLibro = (eLibro*)ll_get(pArrayListBooks, i);

        	eLibro_getId(pAuxLibro, &id);
        	eLibro_getTitulo(pAuxLibro, titulo);
        	eLibro_getAutor(pAuxLibro, autor);
        	eLibro_getPrecio(pAuxLibro, &precio);
        	eLibro_getEditorial(pAuxLibro, &editorialId);
        	eLibro_getEditorialDetalle (pAuxLibro,editorialId,editorial);


            printf("| %5d | %60s | %15s | %10.2f |  %20s |\n", id,titulo,autor, precio,editorial);

            if(i == pantalla)
             {
        		do
        		{
        			respuesta = utn_getRespuesta ("\nPRESIONE [S] PARA MOSTRAR MAS EMPLEADOS: ","\nERROR", 3);
        			pantalla+=999;
        		}while(respuesta != 0);
              }
        	}
        	respuesta2 = utn_getRespuesta ("\nPRESIONE [S] PARA CONTINUAR: ","\nERROR", 3);

        }while(respuesta2 != 0);
        retorno = 0;

    	}
    }
    return retorno;
}
int controller_sort (LinkedList* pArrayListBooks)
{
	int retorno = -1;
	int orden = 0;

	 if(pArrayListBooks != NULL && ll_len(pArrayListBooks) > 0)
	 {
		 ll_sort(pArrayListBooks, eLibro_compareByAutor, orden);
		 retorno = 0;
	 }
	 return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListBooks)
{
    FILE* file = NULL;
    int retorno = -1;
    int eLibroQTY;
    int i;
    eLibro* pAuxLibro;

    if(pArrayListBooks != NULL)
    {
        eLibroQTY = ll_len(pArrayListBooks);

        file = fopen(path, "w");

        if(file != NULL
           && eLibroQTY > 0 && eLibroQTY <= 700
           && fprintf(file, "id,titulo,autor,precio,editorialId\n") != -1)
        {
            for(i = 0; i < eLibroQTY; i++)
            {
            	pAuxLibro = (eLibro*)ll_get(pArrayListBooks, i);
                if(fprintf(file, "%d,%s,%s,%.2f,%d\n",
                		pAuxLibro->id,
						pAuxLibro->titulo,
						pAuxLibro->autor,
						pAuxLibro->precio,
						pAuxLibro->editorial) == -1)
                {
                    break;
                }

            }
        }

        if(i > 0 && i == eLibroQTY)
        {
        	retorno = 0;
        }
    }

    fclose(file);
    free(pAuxLibro);
    return retorno;
}
