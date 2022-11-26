/*
 * funcionesAuxiliares_Jugador.h
 *
 *  Created on: 12 nov 2022
 *      Author: DIEGO
 */

#ifndef FUNCIONESAUXILIARES_JUGADOR_H_
#define FUNCIONESAUXILIARES_JUGADOR_H_

#include "Jugador.h"
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"

int jug_obtenerDatos(Jugador* this,int* id,char* nombreCompleto,int* edad,char* posicion,char* nacionalidad,int* idSeleccion);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int obtenerID(int* id);
int obtenerMayorId(Jugador* this,int* id);
int guardarMaximoID_ModoTexto(FILE* pFile, LinkedList* pArrayList,int* maxID);
int controller_guardarMaximoID_ModoTexto(FILE* pFile,char* path, LinkedList* pArrayList);
int buscarPorID(LinkedList* pArrayList, int id);
int incrementarID(int id);
int decrementarID(int id);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int validarPosicion(Jugador* auxJugador,char* cadena);
int validarNacionalidad(Jugador* auxJugador,char* cadena);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int mostrarUnJugador(Jugador *jugador);
/*-------------------------------------------------------------------------------------------------------------------------------*/
void eliminarJugador(Jugador *this);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int jug_ordenarPorNombreAsc(void *unNombre, void *otroNombre);
int jug_ordenarPorNombreDesc(void *unNombre, void *otroNombre);

int jug_ordenarPorEdadAsc(void *unaEdad, void *otraEdad);
int jug_ordenarPorEdadDesc(void *unaEdad, void *otraEdad);

int jug_ordenarPorPosicion(void *unaPosicion, void *otraPosicion);
int jug_ordenarPorNacionalidadAsc(void *unaNacionalidad, void *otraNacionalidad);
int jug_ordenarPorNacionalidadDesc(void *unaNacionalidad, void *otraNacionalidad);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int cargarConvocados(char cadena[],LinkedList* pArrayListJugadores,LinkedList* pArrayListSelecciones);
int parser_jugadorABinario(FILE* pFile,Jugador* auxJugador);
/*-------------------------------------------------------------------------------------------------------------------------------*/
int jug_guardarModoTextoCsv(FILE* pFile, LinkedList* pArrayList);
/*-------------------------------------------------------------------------------------------------------------------------------*/
#endif /* FUNCIONESAUXILIARES_JUGADOR_H_ */
