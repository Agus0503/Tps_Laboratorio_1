/*
 * inputs.h
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int obtener_Tipo_Short(short* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

char pedirChar(char cadena);

int getString(char cadena[], int longitud);

void obtenerString(char *mensaje,char *palabra);

#endif /* INPUTS_H_ */
