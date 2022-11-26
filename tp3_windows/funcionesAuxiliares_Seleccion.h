/*
 * funcionesAuxiliares_Seleccion.h
 *
 *  Created on: 13 nov 2022
 *      Author: DIEGO
 */

#ifndef FUNCIONESAUXILIARES_SELECCION_H_
#define FUNCIONESAUXILIARES_SELECCION_H_

#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"

/*-------------------------------------------------------------------------------------*/
int selec_obtenerDatos(Seleccion* this,int* id,char* pais,char* confederacion,int* convocados);
/*-------------------------------------------------------------------------------------*/
int mostrarUnaSeleccion(Seleccion *seleccion);
/*-------------------------------------------------------------------------------------*/
int selec_buscarPorID(LinkedList* pArrayList, int id);
/*-------------------------------------------------------------------------------------*/
int ordenarSeleccionesAsc(void* unaSeleccion,	void* otraSeleccion);
int ordenarSeleccionesDesc(void* unaSeleccion,	void* otraSeleccion);
/*-------------------------------------------------------------------------------------*/
int selec_guardarModoTextoCsv(FILE* pFile, LinkedList* pArrayList);

#endif /* FUNCIONESAUXILIARES_SELECCION_H_ */
