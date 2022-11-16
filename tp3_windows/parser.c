#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	char id[10];
	char nombreCompleto[100];
	char edad[10];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[10];
	Jugador* unJugador;

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

			unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

			ll_add(pArrayListJugador, unJugador);

		}

		retorno = 1;
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* jugadorAux;
	int retorno = -1;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			jugadorAux = jug_new();
			if(fread(jugadorAux,sizeof(Jugador),1,pFile)==1)
				{
					ll_add(pArrayListJugador, jugadorAux);
				}
		}
		retorno = 1;
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	char id[SIZE_CADENA];
	char pais[SIZE_CADENA];
	char confederacion[SIZE_CADENA];
	char convocados[SIZE_CADENA];

	Seleccion* seleccionAux;

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

			seleccionAux = selec_newParametros(id, pais, confederacion, convocados);

			ll_add(pArrayListSeleccion, seleccionAux);
		}
			retorno = 1;
	}

	    return retorno;
}

