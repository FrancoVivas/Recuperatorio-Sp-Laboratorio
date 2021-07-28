/*
 * Parser.c
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */


#include "Parser.h"
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
    int cantidad;
    int retorno = -1;
    char buffer[5][200];
    eLibro* pAuxLibro = NULL;

    if(pFile != NULL && pArrayListBook != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
    	do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

        	if(cantidad < 5)
            {
        		printf("\nFIN");
        		break;
            }
        	else
        	{
        		if(strcmp(buffer[4],"Planeta")==0)
        		{
        			strcpy(buffer[4], "1");
        		}
        		if(strcmp(buffer[4],"SIGLO XXI EDITORES")==0)
    			{
        			strcpy(buffer[4], "2");
    			}
    			if(strcmp(buffer[4],"Pearson")==0)
    			{
    				strcpy(buffer[4], "3");
    			}
    			if(strcmp(buffer[4],"Minotauro")==0)
    			{
    				strcpy(buffer[4], "4");
    			}
    			if(strcmp(buffer[4],"SALAMANDRA")==0)
    			{
    				strcpy(buffer[4], "5");
    			}
    			if(strcmp(buffer[4],"PENGUIN BOOKS")==0)
    			{
    				strcpy(buffer[4], "6");
    			}
        		pAuxLibro = eLibro_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

                if(pAuxLibro != NULL && ll_add(pArrayListBook, (eLibro*)pAuxLibro) == 0)
                {
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}
