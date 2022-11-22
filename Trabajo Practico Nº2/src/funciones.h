/*
 * funciones.h
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "inputs.h"
#include "confederacion.h"

#define LIBRE 0
#define OCUPADO 1
#define SIZE_JUGADORES 3000

typedef struct{

	int id;
	char nombre[SIZE_CADENA];
	char posicion[SIZE_CADENA];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}sJugador;


/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Busco un espacio libre en la lista
///
/// @param array lista pasada por parametro
/// @param size tamaño de la lista
/// @return 1 en caso de encontrar un espacio, -1 si no se encontro
int buscarEspacioLibre(sJugador array[], int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Imprimo un jugador
///
/// @param jugador
void mostrarUno(sJugador jugador);
/// @brief Imprimo todos los jugadores disponibles
///
/// @param jugador
/// @param size tamaño de la lista
/// @return
int mostrarTodos(sJugador* jugador, int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Calculo el promedio y el total de salario de los jugadores
///
/// @param array lista pasada por parametro
/// @param size tamaño de la lista
/// @return
int calcularPromedio_y_total(sJugador array[], int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Doy de alta un jugador
///
/// @param jugadores
/// @param size tamaño de la lista
/// @return
int alta(sJugador* jugadores, int size);
/// @brief Cargo todos los datos del alta en la lista de jugadores
///
/// @param jugadores
/// @param size tamaño de la lista
/// @param id
/// @param nombre
/// @param posicion
/// @param numeroCamiseta
/// @param idConfederacion
/// @param salario
/// @param aniosContrato
/// @return
int cargarDatos(sJugador* jugadores, int size, int id, char nombre[],char posicion[],short numeroCamiseta,int idConfederacion,float salario,short aniosContrato);
/// @brief Doy de baja un jugador
///
/// @param jugador
/// @param size tamaño de la lista
/// @param id Busco la coincidencia para dar de baja
/// @return
int baja(sJugador* jugador, int size, int id);
/// @brief
///
/// @param array
/// @param size tamaño de la lista
/// @param id Busco la coincidencia para modificar
/// @return
int modificacion(sJugador array[], int size,int id);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Ordeno la lista Ascendentemente por numero de ID
///
/// @param array
/// @param size tamaño de la lista
/// @return
int ordenarPorId(sJugador array[], int size);
/// @brief
///
/// @param array
/// @param size tamaño de la lista
/// @return
int ordenarPorNombre(sJugador array[], int size);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Valido que la posicion ingresada sea correcta
///
/// @param auxJugador puntero a estructura para escribir datos
/// @param cadena Puntero a char para guardar y sobreescribir dato
/// @return
int validarPosicion(sJugador* auxJugador,char* cadena);
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/// @brief Verifico que haya almenos 1 Alta
///
/// @param array
/// @param size tamaño de la lista
/// @return
int verificarAlta(sJugador* array,int size);


#endif /* FUNCIONES_H_ */
