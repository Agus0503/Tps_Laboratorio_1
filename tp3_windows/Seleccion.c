#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"


Seleccion* selec_new()
{
	Seleccion* seleccionAux = NULL;

	seleccionAux = (Seleccion*) malloc(sizeof(Seleccion));

	return seleccionAux;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccionAux = NULL;

	seleccionAux = selec_new();

	if(seleccionAux != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		seleccionAux->id = atoi(idStr);
		strcpy(seleccionAux->pais,paisStr);
		strcpy(seleccionAux->confederacion,confederacionStr);
		seleccionAux->convocados = atoi(convocadosStr);
	}

	return seleccionAux;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this != NULL && pais != NULL)
	{
		strncpy(pais,this->pais,SIZE_CADENA);
		retorno = 1;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
		strncpy(confederacion,this->confederacion,SIZE_CADENA);
		retorno = 1;
	}

	return retorno;
}


int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		*convocados = this->convocados;
		retorno = 1;
	}

	return retorno;
}
