/*
 * Menu.c
 *
 *  Created on: 28 jul. 2021
 *      Author: N3630024213
 */


#include "Menu.h"

void menu_principal (int* opcion)
{
	printf("\n ");
    printf("\n |***********************************************************************************|\n");
    printf(" |                                  MENU PRINCIPAL                                   |\n");
    printf(" |***********************************************************************************|\n");
	printf(" |  [1] Cargar archivo.                                                              |\n");
	printf(" |  [2] Ordenar por autor.                                                           |\n");
	printf(" |  [3] Listar libros.                                                               |\n");
	printf(" |  [4] Generar descuento.                                                           |\n");
	printf(" |  [5] Guardar archivo [mapeado.csv].                                               |\n");
	printf(" |  [6] Salir del programa.                                                          |\n");
	printf(" |***********************************************************************************|\n\n");
	utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 6, 3);

}
