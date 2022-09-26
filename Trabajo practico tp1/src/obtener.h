/*
 * obtener.h
 *
 *  Created on: 16 sept 2022
 *      Author: DIEGO
 */

#ifndef OBTENER_H_
#define OBTENER_H_

#define TAMCONFEDERACIONES 6

/// @brief
/// @param minimo
/// @param maximo
void validarCamiseta(int minimo, int maximo);

/// @brief
/// @param pCantidadArqueros
/// @param pCantidadDefensores
/// @param pCantidadMediocampistas
/// @param pCantidadDelanteros
/// @param banderaHablitacionA
/// @return Devuele valor 1 si se cumplen las condiciones
int subMenuJugadores(int* pCantidadArqueros,int* pCantidadDefensores,int* pCantidadMediocampistas,int* pCantidadDelanteros, int* banderaHablitacionA);

/// @brief
/// @param pCostoHospedaje
/// @param pCostoComida
/// @param pCostoTransporte
/// @return Devuele valor 1 si se cumplen las condiciones
int subMenuGastos(float* pCostoHospedaje,float* pCostoComida,float* pCostoTransporte);

/// @brief
/// @param pCantidadJugadores
/// @return Devuele promedio calculado
float calcularPromedio(int* pCantidadJugadores);

#endif /* OBTENER_H_ */
