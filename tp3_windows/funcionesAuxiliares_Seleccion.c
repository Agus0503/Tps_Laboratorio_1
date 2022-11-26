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

	if(selec_obtenerDatos(seleccion, &id, pais, confederacion, &convocados) == 1)
	{
		puts("=================================================================\n"
				"|  ID |    	PAIS           CONFEDERACION 	     CONVOCADOS\n"
				"=================================================================");
		printf("| %5d | %10s | %25s | %10d |\n", id, pais, confederacion, convocados);
		printf("------------------------------------------------------------------\n");

		retorno = 1;
	}


	return retorno;
}

int ordenarSeleccionesAsc(void* unaSeleccion,	void* otraSeleccion)
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

int ordenarSeleccionesDesc(void* unaSeleccion,	void* otraSeleccion)
{
	int retorno = -1;

	char seleccion_uno[SIZE_CADENA];
	char seleccion_dos[SIZE_CADENA];

	if(unaSeleccion != NULL && otraSeleccion != NULL)
	{
		selec_getConfederacion(unaSeleccion, seleccion_uno);
		selec_getConfederacion(otraSeleccion, seleccion_dos);

		fflush(stdin);
		if (strcmp(seleccion_uno, seleccion_dos) < 0)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int selec_buscarPorID(LinkedList* pArrayList, int id)
{
  int retorno = -1;
  Seleccion* auxSeleccion;

  if(pArrayList != NULL && id > 0)
  {
	  for(int indice = 0; indice < ll_len(pArrayList); indice++)
	  {
		 auxSeleccion = ll_get(pArrayList, indice);
		  if(selec_getId(auxSeleccion, &auxSeleccion->id) == 1 && auxSeleccion->id == id)
		  {
			  retorno = indice;
			  break;
		  }
	  }
  }

  return retorno;
}


int selec_guardarModoTextoCsv(FILE* pFile, LinkedList* pArrayList)
{
    Seleccion* auxSeleccion;

    int retorno = -1;
    int id;
    char pais[SIZE_CADENA];
	char confederacion[SIZE_CADENA];
	int convocados;
    int size;
    int bandera = 1;

    if(pFile != NULL && pArrayList != NULL)
    {
        size = ll_len(pArrayList);

        for(int i = 0; i < size; i++)
        {
            auxSeleccion = ll_get(pArrayList,i);
            selec_obtenerDatos(auxSeleccion, &id, pais, confederacion, &convocados);
            if(bandera)
            {
            	fprintf(pFile,"%s,%s,%s,%s\n","id","pais","confederacion","convocados");
            	bandera = 0;
            }
            fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
            retorno = 1;
        }
    }

    return retorno;
}

