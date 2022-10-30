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
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
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

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (int i = 0; i < size; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
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

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
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

	retorno = obtener_Tipo_Short(&aux.aniosContrato, "\nIngrese años de contrato: ", "¡Dato invalido!", 1, 99, 0);

	while(retorno == -1){
		retorno = obtener_Tipo_Short(&aux.aniosContrato, "\nIngrese años de contrato: ", "¡Dato invalido!", 1, 99, 0);
	}

	return aux;
}

int Alta(sJugdador array[], int size){

	sJugdador aux;
	int retorno;
	retorno = 0;

	//BUSCO ESPACIO EN ARRAY
	int index = buscarEspacioLibre(array, size);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		aux = cargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		aux.id = obtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		aux.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = aux;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}

	return retorno;
}

int Baja(sJugdador array[], int size){

	int retorno = 0;
	int id;
	int index;
	int bandera = 0;

	//LISTO TODOS LOS Gen
	if (informes(array, size)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (bandera) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		obtenerNumero(&id, "Ingrese ID a dar de baja: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);

		//BUSCO INDEX POR ID EN ARRAY
		while (BuscarPorID(array, size, id) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			obtenerNumero(&id, "Ingrese ID a dar de baja: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = BuscarPorID(array, size, id);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECsizeENTE
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

	//LISTO TODOS LOS Gen
	if (informes(array, size)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (bandera) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		obtenerNumero(&id, "Ingrese ID a Modificar: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
		//BUSCO INDEX POR ID EN ARRAY
		while (BuscarPorID(array, size, id) == -1) {
			puts("NO EXISTE ID.");
			obtenerNumero(&id, "Ingrese ID a Modificar: ", "\n¡El ID ingresado no existe!\n", 1, 1000, 0);
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			//printf("INGRESE ID A DAR DE BAJA: ");
			//scanf("%d", &id);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = BuscarPorID(array, size, id);

		//LLAMO A FUNCION QUE MODIFICA Gen
		//auxiliar = eGen_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECsizeENTE
		retorno = 1;
	}

	return retorno;
}

void eGen_MostrarUno(sJugdador aux){
	//PRINTF DE UN SOLO Gen
	printf("%5d\n", aux.id);
}

int informes(sJugdador array[], int size){

	int retorno;
	int cantidad;
	retorno = 0;
	cantidad = 0;

	//CABECERA
	puts("\nLISTADO:");
//	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	puts("===========================================================================================================\n");
	puts("|  ID  |       NOMBRE       |      POSICION      | CAMISETA |   SUELDO   | CONFEDERACION | AÑOS DE CONTRATO|\n");
	puts("===========================================================================================================\n");
//	puts("|  %d   |      %s     |     %s      |    %d    |  %.2f  |     %s      | 	%d	|\n", id, nombre, POSICION, camiseta, sueldo, CONFEDERACION, aniosContrato );
	puts("----------------------------------------------------------------------------------------------------------\n");
	puts("\n");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (int i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
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

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && arrayConf != NULL && sizeConf > 0 && sizeJugadores > 0) {
				for (int i = 0; i < sizeJugadores - 1; i++) {
					for (int j = i + 1; j < sizeJugadores; j++) {
						//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if (array[i].isEmpty == OCUPADO	&& array[j].isEmpty == OCUPADO) {
							//CRITERIO DE ORDENAMIENTO
							if (strcmp(arrayConf[i].nombre,arrayConf[j].nombre)>0) {
								//INTERCAMBIO POSICIONES EN ARRAY
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
