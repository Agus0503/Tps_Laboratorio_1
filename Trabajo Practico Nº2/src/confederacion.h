/*
 * confederacion.h
 *
 *  Created on: 20 nov 2022
 *      Author: DIEGO
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include "inputs.h"
#include "funciones.h"

#define SIZE_CONFEDERACIONES 6

typedef struct{

	int id;
	char nombre[SIZE_CADENA];
	char region[SIZE_CADENA];
	int anioCreacion;
	int isEmpty; //Agrego campo isEmpty para ABM de confederaciones
}sConfederacion;


/*-------------------------------------------------------------------------------------------------------------------------------------------*/
void menuConfederacion();
int ordenarConfPorId(sConfederacion array[], int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
void mostrarUnaConf(sConfederacion confederacion);
int mostrarTodasConf(sConfederacion* array, int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int conf_BuscarPorID(sConfederacion array[], int size, int ID);
int conf_ObtenerIndexLibre(sConfederacion array[], int size);
sConfederacion conf_CargarDatos(void);
int conf_Alta(sConfederacion array[], int size);
int conf_Baja(sConfederacion array[], int size);
sConfederacion conf_ModificarUno(sConfederacion conf);
int conf_Modificacion(sConfederacion array[], int size) ;

#endif /* CONFEDERACION_H_ */
