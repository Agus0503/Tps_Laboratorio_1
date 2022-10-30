/*
 * funciones.h
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <ctype.h>

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define SIZE_JUGADORES 3000

typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}sConfederacion;

typedef struct{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}sJugdador;

void InicializarJugador(sJugdador array[], int size);
int buscarEspacioLibre(sJugdador array[], int size);
int BuscarPorID(sJugdador array[], int size, int ID);
sJugdador cargarDatos();
sConfederacion cargarConfederacion();
int Alta(sJugdador array[], int size);
int Baja(sJugdador array[], int size);
int Modificacion(sJugdador array[], int size);
void eGen_MostrarUno(sJugdador aux);
int informes(sJugdador array[], int size);
int ordenamiento(sJugdador array[], int sizeJugadores,sConfederacion arrayConf[],int sizeConf);

#endif /* FUNCIONES_H_ */
