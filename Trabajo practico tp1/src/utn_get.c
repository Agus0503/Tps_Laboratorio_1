/*
 * utn_get.c
 *
 *  Created on: 20 sept 2022
 *      Author: DIEGO
 */
#include <stdio.h>
#include <string.h>
#include "utn_get.h"

//OBTENER NUMERO ENTERO ============================================================================
int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int bufferInt;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{

			printf("%s", mensaje);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*resultado = bufferInt;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

//OBTENER NUMERO FLOTANTE ============================================================================
int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){

	float bufferFloat;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{

			printf("%s", mensaje);
			scanf("%f", &bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*resultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

//OBTENER CARACTER ============================================================================

int getCaracter(char* resultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){

	char bufferChar;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{
			printf("%s", mensaje);
			scanf("%c", &bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo){
						*resultado = bufferChar;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
						reintentos --;
				}
		}while(reintentos>=0);
	}

	return retorno;
}

