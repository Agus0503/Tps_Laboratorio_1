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
/// @param pCantidadJugadoresAfc
/// @return Devuele promedio calculado
float calcularPromedioAfc(int* pCantidadJugadoresAfc);

/// @brief
/// @param pCantidadOfc
/// @return Devuele promedio calculado
float calcularPromedioOfc(int* pCantidadOfc);

/// @brief
/// @param pCantidadCaf
/// @return Devuele promedio calculado
float calcularPromedioCaf(int* pCantidadCaf);

/// @brief
/// @param pCantidadConcaf
/// @return Devuele promedio calculado
float calcularPromedioConcaf(int* pCantidadConcaf);

/// @brief
/// @param pCantidadConmebol
/// @return Devuele promedio calculado
float calcularPromedioConmebol(int* pCantidadConmebol);

/// @brief
/// @param pCantidadUefa
/// @return Devuele promedio calculado
float calcularPromedioUefa(int* pCantidadUefa);

#endif /* OBTENER_H_ */
