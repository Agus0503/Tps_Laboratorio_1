/*
 * utn_get.h
 *
 *  Created on: 20 sept 2022
 *      Author: DIEGO
 */

#ifndef UTN_GET_H_
#define UTN_GET_H_

/// @brief
/// @param resultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @brief
/// @param resultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


#endif /* UTN_GET_H_ */
