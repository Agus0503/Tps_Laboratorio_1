/*
 * nexo.h
 *
 *  Created on: 20 nov 2022
 *      Author: DIEGO
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "inputs.h"
#include "funciones.h"
#include "confederacion.h"


void mostrar(sJugador jugador,sConfederacion conf[],int size);
int mostrarTodo(sJugador jugador[],int sizeJug ,sConfederacion conf[]);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
void mostrarConfConJugadores(sJugador jugador,sConfederacion arrayConf[],int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int mostrarJugadoresConmebol(sJugador arrayJug[],sConfederacion arrayConf[],int size);
int mostrarJugadoresUefa(sJugador arrayJug[],sConfederacion arrayConf[],int size);
int mostrarJugadoresAfc(sJugador arrayJug[],sConfederacion arrayConf[],int size);
int mostrarJugadoresCaf(sJugador arrayJug[],sConfederacion arrayConf[],int size);
int mostrarJugadoresConcacaf(sJugador arrayJug[],sConfederacion arrayConf[],int size);
int mostrarJugadoresOfc(sJugador arrayJug[],sConfederacion arrayConf[],int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int confMasAniosDeContrato(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int PorcentajeJugadores_por_Confederacion(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int regionConMasJugadores(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
void mostrarRegionConJugadores(sJugador jugador,sConfederacion arrayConf[],int size);
#endif /* NEXO_H_ */
