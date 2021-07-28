/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Menu.h"

int main(void) {
	system("cls");
	setbuf(stdout,NULL);
	int option;
	char auxDoc[MAX_NOMBRE];
	LinkedList* listaLibros = ll_newLinkedList();

	do{
	    	menu_principal (&option);
	        switch(option)
	        {
	            case 1:
	            	printf("\nINGRESE EL NOMBRE DEL ARCHIVO A LEER (Datos.csv): ");
	            	scanf("%s",auxDoc); //Lee el dato ingresado del auxiliar
	            	fflush(stdin); //Limpia el buffer de entrada

	            	printf("CARGANDO DATOS...\n");
	            	printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	                if(controller_loadFromText(auxDoc,listaLibros) == 0) //Si se cumple la carga del texto
	                {
	                	printf("\nSE LEYERON LOS DATOS\n");
	                }
	                else //Si no se cumple la carga del texto
	                {
	                	printf("\nNO SE LEYERON LOS DATOS\n");
	                }
	                break; //Se detiene la ejecucion
	           case 2:

	        	   if(controller_sort(listaLibros)!=0) //Si se cumple el ordenamiento de la lista de libros
	        	   {
	        		   printf("\nNO HAY AUTORES PARA ORDENAR");
	        	   }
	        	   else //Si no se cumple el ordenamiento
	        	   {
	        		   printf("\nSE ORDENO POR AUTOR");
	        	   }
	        	   break;
	           case 3:
	        	   if(controller_ListBooks(listaLibros)!=0) //Si se cumple el controlador de la lista de libros
	        	   {
	        		   printf("\nNO HAY LIBROS PARA MOSTRAR");
	        	   }
	        	   break;
	          case 4:
	        	  if(ll_map(listaLibros, eLibro_calcularDescuento)==0)//Si se cumple el mapeo de la lista de libros
	        	  {
	        		  printf("\nSE APLICARON LOS DESCUENTOS CORRESPONDIENTES");
	        	  }
	        	  else //Si no se cumple el mapeo
	        	  {
	        		  printf("\nNO SE OBTUVIERON LOS MONTOS");
	        	  }
	        	   break;
	           case 5:
	        	   if(controller_saveAsText("mapeado.csv",listaLibros)==0) //Si se cumple el controlador de guardado como texto
	        	   {
	        		   printf("\nSE GUARDARON LOS DATOS EN [mapeado.csv] ");
	        	   }
	        	   else //Si no se cumple el controlador
	        	   {
	        		   printf("\nNO SE GUARDARON LOS DATOS");
	        	   }
	        	   break;
	           case 6:
	        	   printf("\nFIN DEL PROGRAMA.");
	        	   break;
	        }
	}while(option != 6); //Mientras la funcion no sea falsa (distinto de 6) se podra ejecutar las opciones
	return EXIT_SUCCESS; //Termina la ejecucion de la funcion
}
