/*
 * inputs.h
 *
 *  Created on: 1 nov 2022
 *      Author: DIEGO
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "LinkedList.h"

int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int obtener_Tipo_Short(short* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
//void obtenerString(char *mensaje,char *palabra);
char pedirChar(char cadena);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int obtenerString(char cadena[], int longitud);
int obtenerCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int isNombre(char* cadena,int longitud);
int validarNombre(char *cadena, int longitud);
int esCadenaValida( char* cadena, int limite);
/*-------------------------------------------------------------------------------------------------------------------------------*/
void minuscula(char cadena[]);
void mayusculaInicial(char cadena[]);

#endif /* INPUTS_H_ */
