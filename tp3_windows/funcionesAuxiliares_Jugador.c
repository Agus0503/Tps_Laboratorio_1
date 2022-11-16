/*
 * funcionesAuxiliares_Jugador.c
 *
 *  Created on: 12 nov 2022
 *      Author: DIEGO
 */

#include "funcionesAuxiliares_Jugador.h"


int obtenerID(int* id)
{
	int retorno = 0;
	int nuevoID;
	*id = 371;
	FILE* pFile;

	pFile = fopen("ultimoID.txt","r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%d\n", &nuevoID);
		fread(&nuevoID,sizeof(int),1,pFile);
		*id = nuevoID;
		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}


int incrementarID(int id)
 {
 	int proximoID = id++;
 	int retorno = 0;
 	FILE* pFile;
 	pFile = fopen("ultimoID.txt","w");

 	if(pFile!=NULL)
 	{
 		fprintf(pFile,"%d\n",proximoID);
 		fwrite(&proximoID,sizeof(int),1,pFile);
 		fclose(pFile);
 		retorno = 1;
 	}
 	return retorno;
 }

int obtenerMayorId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
	  jug_getId(this, id);
	  retorno = 0;
	}

	return retorno;
}

int guardarMaximoID_ModoTexto(FILE* pFile, LinkedList* pArrayList,int* maxID)
{
  Jugador* auxJugador;

  int ID;
  int size;
  int retorno = 0;
  int mayorID;
  int bandera = 0;

  if(pFile != NULL && pArrayList != NULL)
  {
	  size = ll_len(pArrayList);

	  for(int i = 0; i < size; i++)
	  {
		  auxJugador = ll_get(pArrayList,i);
		  obtenerMayorId(auxJugador,&ID);

		  if(bandera==0 || ID>mayorID)
		  {
			  mayorID = ID;
			  bandera=1;
		  }

		  retorno = 1;
	  }
  }

  *maxID = mayorID;

  return retorno;
}

 int controller_guardarMaximoID_ModoTexto(FILE* pFile,char* path, LinkedList* pArrayList)
 {
      int retorno = 0;
      int maxID;

      if(pFile !=NULL && guardarMaximoID_ModoTexto(pFile,pArrayList,&maxID))
      {
          retorno = 1;
          fprintf(pFile,"%d\n",maxID + 1);
      }
      return retorno;
 }


 int buscarPorID(LinkedList* pArrayList, int id)
 {
     int retorno = -1;
     int idAux;
     Jugador* auxJugador;

     for(int indice = 0; indice < ll_len(pArrayList); indice++)
     {
    	 auxJugador = ll_get(pArrayList, indice);
         if(jug_getId(auxJugador, &idAux) == 1 && idAux == id)
         {
             retorno = indice;
         }
     }

     return retorno;
 }



 /*---------------------------------------------------------------------------------------------------------------------*/

 int mostrarUnJugador(Jugador *jugador)
  {
  	int retorno = 0;
  	int id;
 	char nombreCompleto[SIZE_CADENA];
 	int edad;
 	char posicion[SIZE_CADENA];
 	char nacionalidad[SIZE_CADENA];
 	int idSeleccion;

  	if (jugador != NULL)
  	{
  		jug_getId(jugador, &id);
  		jug_getNombreCompleto(jugador, nombreCompleto);
  		jug_getEdad(jugador, &edad);
  		jug_getPosicion(jugador, posicion);
  		jug_getNacionalidad(jugador, nacionalidad);
  		jug_getSIdSeleccion(jugador, &idSeleccion);

  		printf("    ------------------------------------------------------------------------\n"
  			   "    |  ID   |   Nombre  |  Edad	| Posicion | Nacionalidad | IdSeleccion	\n");
  		printf("    | [%4d] |   [%10s]  |  [%3d] |  [%10s]  |   [%10s]     | [%d]\n", id, nombreCompleto, jugador->edad, jugador->posicion, jugador->nacionalidad, jugador->idSeleccion);
  		printf("    -----------------------------------------------------------------------\n");

  		retorno = 1;
  	}

  	return retorno;
  }
 /*---------------------------------------------------------------------------------------------------------------------*/

int jug_ordenarPorNombre(void *unNombre, void *otroNombre)
{
 	int retorno = -1;
 	char nombre_uno[SIZE_CADENA];
 	char nombre_dos[SIZE_CADENA];

 	jug_getNombreCompleto(unNombre, nombre_uno);
 	jug_getNombreCompleto(otroNombre, nombre_dos);

	if (strcmp(nombre_uno, nombre_dos) > 0)
	{
		retorno = 1;
	}

 	return retorno;
 }

int jug_ordenarPorNacionalidad(void *unaNacionalidad, void *otraNacionalidad)
{
 	int retorno = -1;
 	char nacionalidad_uno[SIZE_CADENA];
 	char nacionalidad_dos[SIZE_CADENA];

 	jug_getPosicion(unaNacionalidad, nacionalidad_uno);
 	jug_getPosicion(otraNacionalidad, nacionalidad_dos);

 	if (strcmp(nacionalidad_uno, nacionalidad_dos) > 0)
 	{
 		retorno = 1;
 	}

 	return retorno;
 }

int jug_ordenarPorEdad(void *unaEdad, void *otraEdad)
{
	int retorno = 0;
	int edad_uno;
	int edad_dos;

	jug_getEdad(unaEdad, &edad_uno);
	jug_getEdad(otraEdad, &edad_dos);

	if (edad_uno > edad_dos) {
		retorno = 1;
	} else if (edad_uno < edad_dos) {
		retorno = -1;
	}
	return retorno;
}

	/*---------------------------------------------------------------------------------------------------------------------*/

int convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* jug_convocado;
	Seleccion* seleccion_convocado;
	int cantidadConvocados;
	int id_seleccion;
	int idAux;
	int indice_jug;
	int indice_selec;

	obtenerID(&idAux);

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		obtenerNumero(&idAux, "\nIngrese el id del jugador a convocar: ", "Dato invalido", 1, idAux, 5);
		indice_jug = buscarPorID(pArrayListJugador, idAux);
		jug_convocado = (Jugador*) ll_get(pArrayListJugador, indice_jug);

		if(indice_jug != -1)
		{
			obtenerNumero(&id_seleccion, "\nIngrese el id de seleccion a convocar: ", "Dato invalido", 1, ll_len(pArrayListSeleccion), 5);

			indice_selec = selec_buscarPorID(pArrayListSeleccion, id_seleccion);

			if(indice_selec != -1)
			{
				seleccion_convocado = (Seleccion*)ll_get(pArrayListSeleccion, indice_selec);

				jug_setIdSeleccion(jug_convocado, id_seleccion);
				selec_getId(seleccion_convocado, &id_seleccion);

				if(cantidadConvocados < 22)
				{
					selec_getConvocados(seleccion_convocado, &cantidadConvocados);
					cantidadConvocados++;
					selec_setConvocados(seleccion_convocado, cantidadConvocados);
				}else{
					puts("----------------"
						 "\nLISTA LLENA"
						 "\n..-----------");
				}
			}
		}
	}

	return retorno;
}

int desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* jug_convocado;
	Seleccion* seleccion_convocado;
	int cantidadConvocados;
	int id_seleccion;
	int idAux;
	int indice_jug;
	int indice_selec;

	obtenerID(&idAux);

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadoresConvocados(pArrayListJugador);
		obtenerNumero(&idAux, "\nIngrese el id del jugador a desconvocar: ", "Dato invalido", 1, idAux, 5);
		indice_jug = buscarPorID(pArrayListJugador, idAux);
		jug_convocado = (Jugador*) ll_get(pArrayListJugador, indice_jug);

		if(indice_jug != -1)
		{
			jug_getSIdSeleccion(jug_convocado, &id_seleccion);
			indice_selec = selec_buscarPorID(pArrayListSeleccion, id_seleccion);
			seleccion_convocado = (Seleccion*)ll_get(pArrayListSeleccion, indice_selec);
			selec_getConvocados(seleccion_convocado, &cantidadConvocados);
			cantidadConvocados--;
			selec_setConvocados(seleccion_convocado, cantidadConvocados);
			jug_setIdSeleccion(jug_convocado, 0);
		}
	}

	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	Jugador *auxJugador;
	int idSeleccion;
	int retorno = -1;

	if(pArrayListJugador != NULL)
	{
		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(auxJugador, &idSeleccion);

			if(idSeleccion > 0)
			{
				mostrarUnJugador(auxJugador);
			}

			retorno = 1;
		}
	}

    return retorno;
}

int cargarConvocados(char cadena[],LinkedList* pArrayListJugadores,LinkedList* pArrayListSelecciones)
{
	int retorno = -1;
	FILE* pFile;
	Jugador* auxJugador;
	Seleccion* auxSeleccion;
	int idSeleccion;
	int indice;

	pFile = fopen("data.bin","wb");

	for(int i = 0; i < ll_len(pArrayListJugadores);i++)
	{
		auxJugador = ll_get(pArrayListJugadores, i);
		jug_getSIdSeleccion(auxJugador, &idSeleccion);

		if(idSeleccion != 0)
		{
			indice = selec_buscarPorID(pArrayListSelecciones, idSeleccion);
			auxSeleccion = ll_get(pArrayListSelecciones, indice);

			if(strcmp(auxSeleccion->confederacion,cadena) == 0)
			{
				if(parser_jugadorABinario(pFile,auxJugador) == 1)
				{
					retorno = 1;
				}
			}

		}
	}

	fclose(pFile);

	return retorno;
}

int parser_jugadorABinario(FILE* pFile,Jugador* auxJugador)
{
	int retorno = -1;

	if(pFile != NULL)
	{
		fwrite(auxJugador,sizeof(Jugador),1,pFile);
		retorno = 1;
	}

	fclose(pFile);

	return retorno;
}

int imprimirDatosCargadosEnBinario(char* path)
{
	int retorno = -1;
	Jugador auxJugador;
	FILE* pFile;

	pFile = fopen("data.bin","rb");

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			fread(&auxJugador,sizeof(Jugador),1,pFile);

			if(feof(pFile))
			{
				break;
			}
			mostrarUnJugador(&auxJugador);
			retorno = 1;
		}
	}

	fclose(pFile);

	return retorno;
}

int guardarArchivoCsv(char* path, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;
	Jugador* auxJugador = NULL;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{

			for(int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(auxJugador != 0)
				{
					mostrarUnJugador(auxJugador);
				}

			}
		}
	}

	fclose(pFile);

	return retorno;
}
