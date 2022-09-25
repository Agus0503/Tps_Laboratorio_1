/*
 * obtener.c
 *
 *  Created on: 16 sept 2022
 *      Author: DIEGO
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "obtener.h"
#include "utn_get.h"

// ===================== SUB MENU CARGA DE COSTOS =====================

int subMenuGastos(float* pCostoHospedaje,float* pCostoComida,float* pCostoTransporte){

	int opcionGasto;
	int retorno;

	retorno = -1;

	do{
		printf("\nELIJA TIPO DE GASTO \n");
		printf("1- Costo de hospedaje \n");
		printf("2- Costo de comida \n");
		printf("3- Costo de transporte \n");
		printf("4- REGRESAR");
		printf("\nSeleccione opcion: ");
		scanf("%d", &opcionGasto);

		switch(opcionGasto){
			case 1:
				obtenerNumeroFlotante(pCostoHospedaje, "Ingrese importe: ", "ERROR, importe invalido\n", 1000, 175000, 0);
			break;

			case 2:
				obtenerNumeroFlotante(pCostoComida, "Ingrese importe: ", "ERROR, importe invalido\n", 1000, 175000, 0);
			break;

			case 3:
				obtenerNumeroFlotante(pCostoTransporte, "Ingrese importe: ", "ERROR, importe invalido\n", 1000, 175000, 0);
			break;
		}

	}while(opcionGasto != 4);

	return retorno;

}



// ===================== SUB MENU CARGA DE JUGADORES =====================

int subMenuJugadores(int* pCantidadArqueros,int* pCantidadDefensores,int* pCantidadMediocampistas,int* pCantidadDelanteros, int* banderaHablitacionA){

	int retorno;
	int posicion;

	retorno = -1;

	printf("\nELIJA POSICION \n");
	printf("1- ARQUERO \n");
	printf("2- DEFENSOR \n");
	printf("3- MEDIOCAMPISTA \n");
	printf("4- DELANTERO \n");
	printf("5- REGRESAR AL INICIO");
	printf("\nSeleccione opcion: ");
	scanf("%d", &posicion);

	if(pCantidadArqueros != NULL && pCantidadDefensores != NULL && pCantidadMediocampistas != NULL && pCantidadDelanteros != NULL && banderaHablitacionA != NULL){

			switch(posicion){
				case 1:
					if(*pCantidadArqueros < 2){
						validarCamiseta(1, 99);
						*pCantidadArqueros = *pCantidadArqueros + 1;
						retorno = 1;
					}else{
						printf("\nSE INGRESO EL NUMERO MAXIMO DE JUGADORES DE ESTA POSICION\n");
					}
				break;

				case 2:
					if(*pCantidadDefensores < 8){
						validarCamiseta(1, 99);
						*pCantidadDefensores = *pCantidadDefensores + 1;
						retorno = 1;
					}else{
						printf("\nSE INGRESO EL NUMERO MAXIMO DE JUGADORES DE ESTA POSICION\n");
					}
				break;

				case 3:
					if(*pCantidadMediocampistas < 8){
						validarCamiseta(1, 99);
						*pCantidadMediocampistas = *pCantidadMediocampistas + 1;
						retorno = 1;
					}else{
						printf("\nSE INGRESO EL NUMERO MAXIMO DE JUGADORES DE ESTA POSICION\n");
					}
				break;

				case 4:
					if(*pCantidadDelanteros < 4){
						validarCamiseta(1, 99);
						*pCantidadDelanteros = *pCantidadDelanteros + 1;
						retorno = 1;
					}else{
						printf("\nSE INGRESO EL NUMERO MAXIMO DE DE JUGADORES ESTA POSICION\n");
					}
				break;

				case 5:
				break;

				default:
					printf("\nError, elija las opciones disponbles: ");
				break;
				}


			}

	return retorno;
}


//DEFINO UN RANGO PARA EL NUMERO DE CAMISITA
void validarCamiseta(int minimo, int maximo){

	int camiseta;

	printf("NUMERO DE CAMISETA: ");
	scanf("%d", &camiseta);
	while(camiseta < minimo || camiseta > maximo){
		printf("ERROR, ingrese un numero de camiseta valido: ");
		scanf("%d", &camiseta);
	}

}

//CALCULO DE PROMEDIOS POR MERCADO
float calcularPromedioAfc(int* pCantidadJugadoresAfc){

	float promedio;

	if (pCantidadJugadoresAfc != NULL){

		promedio = (float) *pCantidadJugadoresAfc / TAMCONFEDERACIONES;
	}

	return promedio;
}

float calcularPromedioOfc(int* pCantidadJugadoresOfc){

	float promedio;

	if (pCantidadJugadoresOfc != NULL){

		promedio = (float) *pCantidadJugadoresOfc / TAMCONFEDERACIONES;
	}

	return promedio;
}

float calcularPromedioCaf(int* pCantidadJugadoresCaf){

	float promedio;

	if (pCantidadJugadoresCaf != NULL){

		promedio = (float) *pCantidadJugadoresCaf / TAMCONFEDERACIONES;
	}

	return promedio;
}

float calcularPromedioConcaf(int* pCantidadJugadoresConcaf){

	float promedio;

	if (pCantidadJugadoresConcaf != NULL){

		promedio = (float) *pCantidadJugadoresConcaf / TAMCONFEDERACIONES;
	}

	return promedio;
}

float calcularPromedioConmebol(int* pCantidadConmebol){

	float promedio;

	if (pCantidadConmebol != NULL){

		promedio = (float) *pCantidadConmebol / TAMCONFEDERACIONES;
	}

	return promedio;
}

float calcularPromedioUefa(int* pCantidadUefa){

	float promedio;

	if (pCantidadUefa != NULL){

		promedio = (float) *pCantidadUefa / TAMCONFEDERACIONES;
	}

	return promedio;
}

