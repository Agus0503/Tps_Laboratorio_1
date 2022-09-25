/*
 * obtener.h
 *
 *  Created on: 16 sept 2022
 *      Author: DIEGO
 */

#ifndef OBTENER_H_
#define OBTENER_H_

#define TAMEQUIPO 22
#define TAMCONFEDERACIONES 6

void validarCamiseta(int minimo, int maximo);

int rangoImporte(int minimo, int maximo);

int subMenuJugadores(int* pCantidadArqueros,int* pCantidadDefensores,int* pCantidadMediocampistas,int* pCantidadDelanteros, int* banderaHablitacionA);

int subMenuConfederaciones(int* auxCantidadCaf,int* auxCantidadUefa,int* auxCantidadConcaf,int* auxCantidadOfc,int* auxCantidadConmebol,int* auxCantidadAfc, int* auxCantidadTotal);

int subMenuGastos(float* pCostoHospedaje,float* pCostoComida,float* pCostoTransporte);

int calcularPromedios(float* pPromedioAfc, float* pPromedioOfc, float* pPromedioCaf, float* pPromedioConcaf, float* pPromedioConmebol, float* pPromedioUefa, int* pTotalJugadores);

float calcularPromedioAfc(int* pCantidadJugadoresAfc);

float calcularPromedioOfc(int* pCantidadOfc);

float calcularPromedioCaf(int* pCantidadCaf);

float calcularPromedioConcaf(int* pCantidadConcaf);

float calcularPromedioConmebol(int* pCantidadConmebol);

float calcularPromedioUefa(int* pCantidadUefa);

#endif /* OBTENER_H_ */
