#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		if(parser_JugadorFromText(pFile, pArrayListJugador) == 1)
		{
			puts("\n-----------------------------------------"
				"\nLISTA DE JUGADORES CARGADA CORRECTAMENTE"
				"\n-----------------------------------------");
		}else{
			puts("\n-----------------------------------------"
				"\nERROR EN LA CARGA DE LA LISTA"
				"\n-----------------------------------------");
			retorno = -1;
		}
	}

	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	FILE* pFile;
	pFile = fopen(path,"rb");

	if(pFile != NULL)
	{
		if(parser_JugadorFromBinary(pFile, pArrayListJugador) == 1)
		{
			puts("\n-----------------------------------------"
				 "\nLISTA DE JUGADORES CARGADA CORRECTAMENTE"
				 "\n-----------------------------------------");
		}else{
			puts("ERROR EN LA CARGA DE LA LISTA");
			retorno = -1;
		}
	}

	fclose(pFile);

    return retorno;

}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorno (1) si se ejecuto correctamente
 * 				   (-1) en caso contrario
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador;

	auxJugador = jug_new();

	int id = 371;
	char nombreCompleto[SIZE_CADENA];
	int edad;
	char posicion[SIZE_CADENA];
	char nacionalidad[SIZE_CADENA];
	int idSeleccion = 0;

	if(pArrayListJugador != NULL)
	{
		obtenerID(&id);
		puts("\n -*-*-* ALTA DE JUGADOR -*-*-* \n");
		obtenerCadena(nombreCompleto,SIZE_CADENA,"\nIngrese nombre: ", "\nEl dato ingesado es incorrecto", 50);
		mayusculaInicial(nombreCompleto);
		obtenerNumero(&edad, "\nIngrese edad: ", "\nEl dato ingresado es incorrecto", 19, 38,3);
		validarPosicion(auxJugador, posicion);
		mayusculaInicial(posicion);
		validarNacionalidad(auxJugador, nacionalidad);
		mayusculaInicial(nacionalidad);

		if(auxJugador != NULL)
		{
			jug_setId(auxJugador, id);
			jug_setNombreCompleto(auxJugador, nombreCompleto);
			jug_setEdad(auxJugador, edad);
			jug_setPosicion(auxJugador, posicion);
			jug_setNacionalidad(auxJugador, nacionalidad);
			jug_setIdSeleccion(auxJugador, idSeleccion);
			incrementarID(id);
			ll_add(pArrayListJugador, auxJugador);
			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador *auxJugador;
	int id;
	int maxID;
	char nombreCompleto[SIZE_CADENA];
	int edad;
	char posicion[SIZE_CADENA];
	char nacionalidad[SIZE_CADENA];
	int index;
	int opcion;

	if (pArrayListJugador != NULL)
	{
		obtenerID(&maxID);
		controller_listarJugadores(pArrayListJugador);
		obtenerNumero(&id, "Ingrese el ID a modificar: ","  ID incorrecto.\n", 1, maxID, 50);

		index = buscarPorID(pArrayListJugador, id);

		if (index == -1)
		{
			printf("\n El ID: %d no existe.\n", id);

		} else {
			auxJugador = ll_get(pArrayListJugador, index);

			puts("\nUsted selecciono el siguiente jugador para modificar: \n");
			mostrarUnJugador(auxJugador);

			do{
				obtenerNumero(&opcion, "Que dato desea modificar?"
						"\n1.Nombre"
						"\n2.Edad"
						"\n3.Posicion"
						"\n4.Nacionalidad"
						"\n5.Salir"
						"\nIngrese opcion: ", "¡Dato Incorrecto!", 1, 5, 50);

				switch (opcion)
				{
				case 1: /*NOMBRE*/
					mostrarUnJugador(auxJugador);
					if(obtenerCadena(nombreCompleto, sizeof(nombreCompleto),"\nIngrese nuevo nombre: ","\nNombre Incorrecto", 3) ==1)
					{
						mayusculaInicial(nombreCompleto);
						jug_setNombreCompleto(auxJugador, nombreCompleto);
						puts("Nombre actualizado correctamente\n");
						retorno = 1;
					}
					break;

				case 2: /*EDAD*/
					mostrarUnJugador(auxJugador);
					if(obtenerEnteroRemastered(&edad,"Ingrese nueva edad: ","Edad incorrecta.\n", 18, 37) == 1)
					{
						jug_setEdad(auxJugador, edad);
						puts("Edad actualizada correctamente \n");
						retorno = 1;
					}
					break;


				case 3:/*POSICION*/
					mostrarUnJugador(auxJugador);
					if(validarPosicion(auxJugador, posicion) == 1)
					{
						jug_getPosicion(auxJugador, posicion);
						jug_setPosicion(auxJugador, posicion);
						puts("\n ---------- Posicion actualizada correctamente ---------- \n");
						retorno = 1;
					}

					break;

				case 4:/*NACIONALIDAD*/
					mostrarUnJugador(auxJugador);
					if(validarNacionalidad(auxJugador, nacionalidad) == 1)
					{
						jug_getNacionalidad(auxJugador, nacionalidad);
						jug_setNacionalidad(auxJugador, nacionalidad);
						puts("\n ---------- Nacionalidad actualizada correctamente ---------- \n");
						retorno = 1;
					}

					break;

				case 5:
					printf("\n saliendo..\n");
					opcion = 6;
					break;


				default:
					printf("Opcion invalida\n");
				}

			} while (opcion != 6);
		}
	}

    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	Jugador *auxJugador;

	int retorno = -1;
	int index;
	int id;
	int ID_obtenido;
	int opcion;
	int maxID;

	obtenerID(&maxID);

	if (pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		obtenerEnteroRemastered(&id, "\nIngrese ID a dar de baja\n","\nID incorrecto ", 1, maxID);

		index = buscarPorID(pArrayListJugador, id);

		auxJugador = ll_get(pArrayListJugador, index);

		jug_getId(auxJugador, &ID_obtenido);


		puts("\nUsted selecciono el siguiente jugador para dar de baja: ");
		mostrarUnJugador(auxJugador);

		if(auxJugador->idSeleccion > 0)
		{
			puts("\n ALERTA!, el jugador seleccionado esta convocado ");
		}
		obtenerEnteroRemastered(&opcion,"\n\n Dar de baja?"
						"\n    1.Si"
						"\n    2.No,volver al inicio"
						"\n    Ingrese opcion: ",
						"     Error ",1,2);

			switch (opcion)
			{

			case 1:
				ll_remove(pArrayListJugador, index);
				jug_delete(auxJugador);
				decrementarID(id);
				retorno = 1;
				break;

			case 2:
				retorno = 0;
				break;

			default:
				puts("\nOpcion invalida.\n");
				break;
			}
	}

    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	Jugador *auxJugador;
	int retorno = -1;

	if (pArrayListJugador != NULL)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);

			mostrarUnJugador(auxJugador);

			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int opcion;

	obtenerNumero(&opcion,"\n    1. Ordernar jugadores por nombre."
   						  "\n    2. Ordenar jugadores por edad."
						  "\n    3. Ordenar jugadores por nacionalidad."
						  "\n    4. Cancelar."
						  "\n    Opcion:",
						  "    Opcion incorrecta",1,4,5);

	if (pArrayListJugador != NULL)
	{
		switch (opcion)
		{

		case 1: /* NOMBRE */
			obtenerEnteroRemastered(&opcion, "\nElija tipo de orden"
						"\n1.Ascendente"
						"\n2.Descendente"
						"\nIngrese opcion: ", "Opcion incorrecta", 1, 2);

				if(opcion == 1)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorNombreAsc, 1);
				} else if(opcion == 2)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorNombreDesc, 1);
				}

				retorno = 1;
				break;

			case 2: /* EDAD */
				obtenerEnteroRemastered(&opcion, "\nElija tipo de orden"
										"\n1.Ascendente"
										"\n2.Descendente"
										"\nIngrese opcion: ", "Opcion incorrecta", 1, 2);

				if(opcion == 1)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorEdadAsc, 1);
				} else if(opcion == 2)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorEdadDesc, 1);
				}

				retorno = 1;
				break;

			case 3: /* NACIONALIDAD */
				obtenerNumero(&opcion, "\n----------------------"
										"\n|Elija tipo de orden|"
										"\n|1.Ascendente       |"
										"\n|2.Descendente      |"
										"\n----------------------"
										"\nIngrese opcion: ", "Opcion incorrecta", 1, 2, 50);

				if(opcion == 1)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorNacionalidadAsc, 1);
				} else if(opcion == 2)
				{
					printf("\nOrdenando Lista..\n");
					ll_sort(pArrayListJugador, jug_ordenarPorNacionalidadDesc, 1);
				}
				retorno = 1;
				break;

			case 5: /* SALIR */
				printf("\nsaliendo..\n");
				retorno = 0;
				break;

			default:
				printf("\nError\n");
				break;
			}

			controller_listarJugadores(pArrayListJugador);

		}

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
   int retorno = -1;
   FILE* pFile = fopen(path,"w");

	if(pFile !=NULL && jug_guardarModoTextoCsv(pFile, pArrayListJugador) == 1)
	{
		retorno = 1;
	}

	fclose(pFile);

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int size;
	FILE* pFile;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL && path != NULL)
	{
		pFile = fopen(path,"wb");

		size = ll_len(pArrayListJugador);
		for (int i = 0; i < size; i++)
		{
			auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			fwrite(auxJugador, sizeof(Jugador), 1, pFile);
		}

		fclose(pFile);
		retorno = 1;
	}

    return retorno;
}


/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		if(parser_SeleccionFromText(pFile, pArrayListSeleccion) == 1)
		{
			puts("\n--------------------------------------------"
				 "\nLISTA DE SELECCIONES CARGADA CORRECTAMENTE"
				 "\n--------------------------------------------");
		}else{
			puts("ERROR EN LA CARGA DE LA LISTA");
			retorno = -1;
		}
	}

	fclose(pFile);

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* auxSeleccion;
	int id;
	char pais[SIZE_CADENA];
	char confederacion[SIZE_CADENA];
	int index;
	int opcion;

	if (pArrayListSeleccion != NULL)
	{
		obtenerID(&id);
		controller_listarSelecciones(pArrayListSeleccion);
		obtenerNumero(&id, "Ingrese el ID a modificar: ","ID incorrecto, por favor reingrese.\n", 0, (id-1), 50);

		index = ll_indexOf(pArrayListSeleccion, &id);

		if (index == -1)
		{
			printf("\nEl ID: %d no existe.\n", id);

		} else {
			auxSeleccion = ll_get(pArrayListSeleccion, index);
			mostrarUnaSeleccion(auxSeleccion);

			do {

				obtenerEnteroRemastered(&opcion, "Que dato desea modificar?"
						"\n1.ID"
						"\n2.Pais"
						"\n3.Confederacion"
						"\n4.Cancelar", "¡Dato Incorrecto!", 1, 4);

				switch (opcion)
				{
				case 1: /*ID*/
					mostrarUnaSeleccion(auxSeleccion);
					if(obtenerEnteroRemastered(&id,"\nIngrese nuevo id: ","ID incorrecto, reingrese.\n", 0, id))
					{
						selec_getId(auxSeleccion, &id);
						printf(" ID actualizado correctamente!\n");
						retorno = 1;

					}
					break;

				case 2: /*PAIS*/
					mostrarUnaSeleccion(auxSeleccion);
					if(obtenerCadena(pais, sizeof(pais),"\nIngrese nuevo Pais: ","\nPais Incorrecto", 3) ==1)
					{
						mayusculaInicial(pais);
						selec_getPais(auxSeleccion, pais);
						puts("\nNombre actualizado correctamente!\n");
						retorno = 1;
					}
					break;

				case 3: /*CONFEDERACION*/
					mostrarUnaSeleccion(auxSeleccion);
					if(obtenerCadena(confederacion, sizeof(confederacion),"\nIngrese nueva Confederacion: ","\nPais Incorrecto", 3) ==1)
					{
						mayusculaInicial(confederacion);
						selec_getConfederacion(auxSeleccion, confederacion);
						puts("\nConfederacion actualizada correctamente!\n");
						retorno = 1;
					}
					break;

				case 4:
					printf("\n...\n");
					retorno = 0;
					break;

				default:
					printf("ERROR\n");
				}
			} while (opcion != 4);
		}
	}

    return retorno;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion *auxSeleccion;
	int id;
	char pais[SIZE_CADENA];
	char confederacion[SIZE_CADENA];
	int convocados;
	int size;

	if (pArrayListSeleccion != NULL)
	{
		retorno = 1;

		size = ll_len(pArrayListSeleccion);
		for (int i = 0; i < size; i++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i);
			selec_getId(auxSeleccion, &id);
			selec_getPais(auxSeleccion, pais);
			selec_getConfederacion(auxSeleccion, confederacion);
			selec_getConvocados(auxSeleccion, &convocados);
			mostrarUnaSeleccion(auxSeleccion);
		}
	}else{
		puts("\nNo hay selecciones para listar");
	}

    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int opcion;
	obtenerNumero(&opcion, "\n----------------------"
							"\n|Elija tipo de orden |"
							"\n|1.Ascendente        |"
							"\n|2.Descendente       |"
							"\n----------------------"
							"\nIngrese opcion: ", "Opcion incorrecta", 1, 2, 50);

	if(opcion == 1)
	{
		printf("\nOrdenando Lista..\n");
		ll_sort(pArrayListSeleccion, ordenarSeleccionesAsc, 1);
	} else if(opcion == 2)
	{
		printf("\nOrdenando Lista..\n");
		ll_sort(pArrayListSeleccion, ordenarSeleccionesDesc, 1);
	}

	if(controller_listarSelecciones(pArrayListSeleccion) == 1)
	{
		retorno = 1;
	}

    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
    FILE* pFile = fopen(path,"w");

	if(pFile != NULL && selec_guardarModoTextoCsv(pFile, pArrayListSeleccion) == 1)
	{
		retorno = 1;
	}

	fclose(pFile);

    return retorno;
}


