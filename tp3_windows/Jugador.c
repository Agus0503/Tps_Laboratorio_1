#include "inputs.h"
#include "Jugador.h"


Jugador* jug_new(){

	Jugador* jugadorAux = NULL;

	jugadorAux = (Jugador*) malloc(sizeof(Jugador));

	return jugadorAux;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){

	Jugador* jugadorAux = NULL;

	jugadorAux = jug_new();

	if(jugadorAux != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL &&
			nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		jug_setId(jugadorAux, atoi(idStr));
		jug_setNombreCompleto(jugadorAux, nombreCompletoStr);
		jug_setEdad(jugadorAux, atoi(edadStr));
		jug_setPosicion(jugadorAux, posicionStr);
		jug_setNacionalidad(jugadorAux, nacionalidadStr);
		jug_setIdSeleccion(jugadorAux, atoi(idSelccionStr));

	}

	return jugadorAux;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int jug_setId(Jugador* this,int id)
{

	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}


int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}



int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{

		if(esCadenaValida(nombreCompleto, 100))
		{
			strcpy(this->nombreCompleto,nombreCompleto);
			retorno = 1;
		}

	}

	return retorno;
}


int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 1;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		if(esCadenaValida(posicion, SIZE_CADENA))
		{
			strcpy(this->posicion,posicion);
			retorno = 1;
		}
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		if(esCadenaValida(nacionalidad, SIZE_CADENA))
		{
			strcpy(this->nacionalidad,nacionalidad);
			retorno = 1;
		}
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{

		strcpy(nacionalidad,this->nacionalidad);
		retorno = 1;

	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}


int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		*edad = this->edad;
		retorno = 1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}

	return retorno;
}

