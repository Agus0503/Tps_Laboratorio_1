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
			puts("LISTA DE JUGADORES CARGADA CORRECTAMENTE");
		}else{
			puts("ERROR EN LA CARGA DE LA LISTA");
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
			puts("LISTA DE JUGADORES CARGADA CORRECTAMENTE");
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

	int id = 370;
	char nombreCompleto[SIZE_CADENA];
	int edad;
	char posicion[SIZE_CADENA];
	char nacionalidad[SIZE_CADENA];
	int idSeleccion = 0;

	if(pArrayListJugador != NULL)
	{
		obtenerID(&id);
		obtenerCadena(nombreCompleto,SIZE_CADENA,"\nIngrese nombre: ", "\nEl dato ingesado es incorrecto", 3);
		mayusculaInicial(nombreCompleto);
		obtenerNumero(&edad, "\nIngrese edad: ", "\nEl dato ingresado es incorrecto", 20, 37,3);
		obtenerCadena(posicion, SIZE_CADENA, "\nIngrese posicion: ", "\nEl dato ingresado es incorrecto", 3);
		obtenerCadena(nacionalidad, SIZE_CADENA, "\nIngrese nacionalidad: ", "\nEl dato ingresado es incorrecto", 3);

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
	int idSeleccion;
	int index;
	int opcion;


	if (pArrayListJugador != NULL)
	{
		obtenerID(&maxID);
		controller_listarJugadores(pArrayListJugador);
		printf("Seleccione entre [1-%d]\n",(maxID));
		obtenerNumero(&id, "Ingrese el ID a modificar: ","  ID incorrecto.\n", 1, maxID, 5);

		index = buscarPorID(pArrayListJugador, id);

		if (index == -1)
		{
			printf("\n El ID: %d no existe.\n", id);

		} else {
			auxJugador = ll_get(pArrayListJugador, index);
			mostrarUnJugador(auxJugador);

			do{
				obtenerNumero(&opcion, "Que dato desea modificar?"
						"\n1.Nombre"
						"\n2.Edad"
						"\n3.Posicion"
						"\n4.Nacionalidad"
						"\n5.ID de Seleccion"
						"\n6.Salir"
						"\nIngrese opcion: ", "¡Dato Incorrecto!", 1, 6, 0);

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
					if(obtenerNumero(&edad,"Ingrese nueva edad: ","Edad incorrecta.\n", 18, 37, 5) == 1)
					{
						jug_setEdad(auxJugador, edad);
						puts("Edad actualizada correctamente \n");
						retorno = 1;
					}
					break;


				case 3:/*POSICION*/
					mostrarUnJugador(auxJugador);
					if(obtenerCadena(posicion, sizeof(posicion),"\nIngrese nueva posicion: ","\nDato incorrecto\n", 5) == 1)
					{
						mayusculaInicial(posicion);
						jug_setPosicion(auxJugador, posicion);
						puts(" Posicion actualizada correctamente\n");
						retorno = 1;
					}
					break;

				case 4:/*NACIONALIDAD*/
					mostrarUnJugador(auxJugador);
					if(obtenerCadena(nacionalidad, sizeof(nacionalidad),"\nIngrese nueva nacionalidad: ","\nDato incorrecto\n", 5) == 1)
					{
						mayusculaInicial(nacionalidad);
						jug_setNacionalidad(auxJugador, nacionalidad);
						puts("Nacionalidad actualizada correctamente\n");
						retorno = 1;
					}
					break;

				case 5:/*ID SELECCION*/
					mostrarUnJugador(auxJugador);
					if(obtenerNumero(&idSeleccion,"\nIngreses nuevo id de seleccion: ","ID incorrecto\n", 0, maxID, 5)){
						jug_setIdSeleccion(auxJugador, idSeleccion);
						printf("ID de seleccion actualizado correctamente\n");
						retorno = 1;
					}
					break;

				case 6:
					printf("\n saliendo..\n");
					retorno = 0;
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

		obtenerNumero(&id, "\nIngrese ID a dar de baja\n","\nID incorrecto ", 1, maxID, 5);

		index = buscarPorID(pArrayListJugador, id);

		auxJugador = ll_get(pArrayListJugador, index);

		jug_getId(auxJugador, &ID_obtenido);


			obtenerNumero(&opcion,"\n\n Dar de baja?"
					"\n    [1] Dar de baja."
					"\n    [2] Cancelar."
					"\n    Ingrese opcion: ",
					"     Error ",1,2,3);

			switch (opcion)
			{

			case 1:
				ll_remove(pArrayListJugador, index);
				jug_delete(auxJugador);
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
				printf("\nOrdenando Lista..\n");
				ll_sort(pArrayListJugador, jug_ordenarPorNombre, 1);
				controller_listarJugadores(pArrayListJugador);
				retorno = 1;
				break;

			case 2: /* EDAD */
				printf("\nOrdenando Lista..\n");
				ll_sort(pArrayListJugador, jug_ordenarPorEdad, 1);
				controller_listarJugadores(pArrayListJugador);
				retorno = 1;
				break;

			case 3: /* NACIONALIDAD */
				printf("\nOrdenando Lista..\n");
				ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, 1);
				controller_listarJugadores(pArrayListJugador);
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

	if(pFile !=NULL && controller_cargarJugadoresDesdeTexto(path,pArrayListJugador))
	{
		retorno = 1;
	}

	fclose(pFile);
	ll_clear(pArrayListJugador);

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
	FILE* pFile;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL && path != NULL)
	{
		pFile = fopen(path,"wb");

		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			fwrite(auxJugador, sizeof(Jugador), 1, pFile);
		}

		fclose(pFile);
		ll_clear(pArrayListJugador);
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
			puts("LISTA DE SELECCIONES CARGADA CORRECTAMENTE");
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
		printf("Selecciones entre [1-%d]\n",(id-1));
		obtenerNumero(&id, "Ingrese el ID a modificar: ","ID incorrecto, por favor reingrese.\n", 0, (id-1), 5);

		index = ll_indexOf(pArrayListSeleccion, &id);

		if (index == -1)
		{
			printf("\nEl ID: %d no existe.\n", id);

		} else {
			auxSeleccion = ll_get(pArrayListSeleccion, index);
			mostrarUnaSeleccion(auxSeleccion);

			do {

				obtenerNumero(&opcion, "Que dato desea modificar?"
						"\n1.ID"
						"\n2.Pais"
						"\n3.Confederacion"
						"\n4.Cancelar", "¡Dato Incorrecto!", 1, 4, 0);

				switch (opcion)
				{
				case 1: /*ID*/
					mostrarUnaSeleccion(auxSeleccion);
					if(obtenerNumero(&id,"\nIngrese nuevo id: ","ID incorrecto, reingrese.\n", 0, id, 5))
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
						puts("Nombre actualizado correctamente!\n");
						retorno = 1;
					}
					break;

				case 3: /*CONFEDERACION*/
					mostrarUnaSeleccion(auxSeleccion);
					if(obtenerCadena(confederacion, sizeof(confederacion),"\nIngrese nueva Confederacion: ","\nPais Incorrecto", 3) ==1)
					{
						mayusculaInicial(confederacion);
						selec_getConfederacion(auxSeleccion, confederacion);
						puts("Confederacion actualizada correctamente!\n");
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

	if (pArrayListSeleccion != NULL)
	{
		retorno = 1;

		for (int i = 0; i < ll_len(pArrayListSeleccion); i++)
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

	ll_sort(pArrayListSeleccion, ordenarSelecciones, 1);

	controller_listarSelecciones(pArrayListSeleccion);

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

	if(pFile != NULL && controller_cargarSeleccionesDesdeTexto(path,pArrayListSeleccion))
	{
		retorno = 1;
	}

	fclose(pFile);
	ll_clear(pArrayListSeleccion);

    return retorno;
}


