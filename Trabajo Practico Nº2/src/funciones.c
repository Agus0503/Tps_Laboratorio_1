/*
 * funciones.c
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#include "funciones.h"
#include "inputs.h"

static int obtenerID(void);
static int obtenerID(void) {
	static int jugador_idIncremental = 0;
	return jugador_idIncremental++;
}

void InicializarJugador(sJugdador array[], int size){

	if (array != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int buscarEspacioLibre(sJugdador array[], int size){

	int retorno;
	retorno = -1;

	if (array != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (array[i].isEmpty == LIBRE) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPorID(sJugdador array[], int size, int ID){
	int retorno = -1;
	int i;

	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

sJugdador cargarDatos(){

	sJugdador aux;
	int retorno;

	aux.id = obtenerID();

	obtenerString("\nIngrese nombre del jugador: ", aux.nombre);

	obtenerString("\nIngrese posicion del jugador: ", aux.posicion);

	retorno = obtener_Tipo_Short(&aux.numeroCamiseta, "\nIngrese numero de camiseta: ", "¡Dato invalido!", 1, 99, 0);

	while(retorno == -1){
		retorno = obtener_Tipo_Short(&aux.numeroCamiseta, "\nIngrese numero de camiseta: ", "¡Dato invalido!", 1, 99, 0);
	}

	retorno = obtenerNumeroFlotante(&aux.salario, "\nIngrese salario: ", "¡Dato invalido!", 50000, 500000, 2);

	while(retorno == -1){
		retorno = obtenerNumeroFlotante(&aux.salario, "\nIngrese salario: ", "¡Dato invalido!", 50000, 500000, 2);
	}

	cargarConfederacion();

	retorno = obtener_Tipo_Short(&aux.aniosContrato, "\nIngrese años de contrato: ", "¡Dato invalido!", 1, 99, 0);

	while(retorno == -1){
		retorno = obtener_Tipo_Short(&aux.aniosContrato, "\nIngrese años de contrato: ", "¡Dato invalido!", 1, 99, 0);
	}

	return aux;
}

sConfederacion cargarConfederacion(){

	sConfederacion aux;

	puts("Seleccione ID de confederacion correspondiente: "
			"1.UEFA"
			"2.CONMEBOL"
			"3.AFC"
			"4.CAF"
			"5.CONCAF"
			"6.OFC");

	obtenerNumero(&aux.id, "INGRESE ID", "INGRESO INCORRECTO!", 1, 6, 0);

	return aux;
}

int Alta(sJugdador array[], int size){

	sJugdador aux;
	int retorno;
	retorno = 0;

	int index = buscarEspacioLibre(array, size);

	if (index != -1) {
		aux = cargarDatos();
		aux.id = obtenerID();
		aux.isEmpty = OCUPADO;
		array[index] = aux;

		retorno = 1;
	}

	return retorno;
}

int Baja(sJugdador array[], int size){

	int retorno = 0;
	int id;
	int index;
	int bandera = 0;

	if (informes(array, size)) {
		bandera = 1;
	}

	if (bandera) {
		obtenerNumero(&id, "Ingrese ID a dar de baja: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);

		while (BuscarPorID(array, size, id) == -1) {
			puts("NO EXISTE ID.");

			obtenerNumero(&id, "Ingrese ID a dar de baja: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
		}

		index = BuscarPorID(array, size, id);

		array[index].isEmpty = BAJA;

		retorno = 1;
	}

	return retorno;
}


int Modificacion(sJugdador array[], int size){

	int retorno;
	int id;
	int index;
	int bandera;
	sJugdador auxiliar;
	retorno = 0;
	bandera = 0;

	if (informes(array, size)) {
		bandera = 1;
	}

	if (bandera) {
		obtenerNumero(&id, "Ingrese ID a Modificar: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
		while (BuscarPorID(array, size, id) == -1) {
			puts("NO EXISTE ID.");
			obtenerNumero(&id, "Ingrese ID a Modificar: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
		}

		index = BuscarPorID(array, size, id);

		array[index] = auxiliar;

		retorno = 1;
	}

	return retorno;
}


int informes(sJugdador array[], int size){

	int retorno;
	int cantidad;
	retorno = 0;
	cantidad = 0;

	puts("\nLISTADO:");
	puts("===========================================================================================================\n");
	puts("|  ID  |       NOMBRE       |      POSICION      | CAMISETA |   SUELDO   | CONFEDERACION | AÑOS DE CONTRATO|\n");
	puts("===========================================================================================================\n");
//	puts("|  %d   |      %s     |     %s      |    %d    |  %.2f  |     %s      | 	%d	|\n", id, nombre, POSICION, camiseta, sueldo, CONFEDERACION, aniosContrato );
	puts("----------------------------------------------------------------------------------------------------------\n");
	puts("\n");

	if (array != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (array[i].isEmpty == OCUPADO) {
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

int ordenamiento(sJugdador array[], int sizeJugadores,sConfederacion arrayConf[],int sizeConf){

	int retorno;
	sJugdador aux;
	sConfederacion auxConf;
	retorno = 0;

		if (array != NULL && arrayConf != NULL && sizeConf > 0 && sizeJugadores > 0) {
				for (int i = 0; i < sizeJugadores - 1; i++) {
					for (int j = i + 1; j < sizeJugadores; j++) {
						if (array[i].isEmpty == OCUPADO	&& array[j].isEmpty == OCUPADO) {
							if (strcmp(arrayConf[i].nombre,arrayConf[j].nombre)>0) {
								auxConf = arrayConf[i];
								arrayConf[i] = arrayConf[j];
								arrayConf[j] = auxConf;
							}

							if(strcmp(array[i].nombre,array[j].nombre)>0){
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}
					}
				}

				retorno = 1;
			}

	return retorno;
}
