/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Diego Agustin Ostua Larramendia
 Division    : C
 Description : Trabajo Practico Nº2 LABO I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void){

	setbuf(stdout,NULL);

	int opcionPrincipal;

	sJugdador arrayJugadores[SIZE_JUGADORES];

	do{
        system("cls||clear");

		puts("Que desea realizar?\n"
				"1.Alta"
				"\n2.Baja"
				"\n3.Modificacion"
				"\n4.Informes"
				"\n5.SALIR");
		printf("\nINGRESE OPCION: ");
		scanf("%d", &opcionPrincipal);

		switch (opcionPrincipal){

		//ALTA
			case 1:
				if(Alta(arrayJugadores, SIZE_JUGADORES)) {
					puts("ALTA EXITOSA");
				} else {
					puts("ERROR. NO HAY MAS ESPACIO DISPONIBLE PARA ALMACENAR");
				}
			break;

		//BAJA
			case 2:
				if(Baja(arrayJugadores,SIZE_JUGADORES)){
					puts("\n BAJA EXITOSA");
					informes(arrayJugadores, SIZE_JUGADORES);
				} else {
					puts("\n BAJA CANCELADA");
				}
			break;

		//MODIFICACION
			case 3:
				if(Modificacion(arrayJugadores, SIZE_JUGADORES)) {
					puts("---------------------------------\n");
					puts("MODIFICACION EXITOSA\n");
					puts("---------------------------------\n");
					informes(arrayJugadores, SIZE_JUGADORES);
				} else {
					puts("---------------------------------\n");
					puts("MODIFICACION CANCELADA");
					puts("---------------------------------\n");
				}
				break;

		//LISTAS
			case 4:
				if(informes(arrayJugadores, SIZE_JUGADORES)){
					puts("Se anda mostrando");
				}else{
					puts("No hay nada para mostrar");
				}
				break;

			case 5:
				puts("Adios...");
			break;

			default:
				puts("-------------------------------------------\n");
				puts("ERROR, La opcion seleccionada es incorrecta\n");
				puts("-------------------------------------------\n");
			break;
		}

	}while(opcionPrincipal != 5);

	return EXIT_SUCCESS;
}
