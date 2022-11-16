/*
 * funcionesAuxiliares_Seleccion.c
 *
 *  Created on: 13 nov 2022
 *      Author: DIEGO
 */

#include "funcionesAuxiliares_Seleccion.h"

int selec_obtenerDatos(Seleccion* this,int* id,char* pais,char* confederacion,int* convocados)
{
	int retorno = -1;

	if(this != NULL)
	{
		selec_getId(this, id);
		selec_getPais(this, pais);
		selec_getConfederacion(this, confederacion);
		selec_getConvocados(this, convocados);
		retorno = 1;
	}
	return retorno;
}

int mostrarUnaSeleccion(Seleccion *seleccion)
{
	int retorno = 0;
	int id;
	char pais[SIZE_CADENA];
	char confederacion[SIZE_CADENA];
	int convocados;

	if (seleccion != NULL)
	{
		selec_getId(seleccion, &id);
		selec_getPais(seleccion, pais);
		selec_getConfederacion(seleccion, confederacion);
		selec_getConvocados(seleccion, &convocados);

		printf("    ------------------------------------------------------------------------\n"
			   "    |  ID   |      Pais     |  Confederacion | Convocados	\n");
		printf("    |  %3d  |      %4s  |        %s      |    %3d\n", id, pais, confederacion, convocados);
		printf("    -----------------------------------------------------------------------\n");

		retorno = 1;
	}

	return retorno;
}

int ordenarSelecciones(void* unaSeleccion,	void* otraSeleccion)
{
	int retorno = -1;

	char seleccion_uno[SIZE_CADENA];
	char seleccion_dos[SIZE_CADENA];

	if(unaSeleccion != NULL && otraSeleccion != NULL)
	{
		selec_getConfederacion(unaSeleccion, seleccion_uno);
		selec_getConfederacion(otraSeleccion, seleccion_dos);

		fflush(stdin);
		if (strcmp(seleccion_uno, seleccion_dos) > 0)
		{
			retorno = 1;
		}
	}

	return retorno;

}
int selec_buscarPorID(LinkedList* pArrayList, int id)
{
  int retorno = -1;
  int idAux;
  Seleccion* auxSeleccion;

  for(int indice = 0; indice < ll_len(pArrayList); indice++)
  {
	 auxSeleccion = ll_get(pArrayList, indice);
	  if(selec_getId(auxSeleccion, &idAux) == 1 && idAux == id)
	  {
		  retorno = indice;
	  }
  }

  return retorno;
}


