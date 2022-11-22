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
#define SIZE_CADENA 50

int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int obtener_Tipo_Short(short* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

char pedirChar(char cadena);

int auxCadena(char cadena[], int longitud);
int validarNombre(char *cadena, int longitud);
int obtenerCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esCadenaValida(char* cadena,int longitud);
int isNumerica(char* cadena, int limite);
void minuscula(char cadena[]);
void mayusculaInicial(char cadena[]);

#endif /* INPUTS_H_ */
