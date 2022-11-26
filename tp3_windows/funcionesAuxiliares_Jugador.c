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
 	int retorno = -1;
	id++;
 	int proximoID = id;
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

int decrementarID(int id)
 {
	id = id - 1;
 	int proximoID = id;
 	int retorno = -1;
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

     if(pArrayList != NULL && id > 0)
     {
		 for(int indice = 0; indice < ll_len(pArrayList); indice++)
		 {
			 auxJugador = (Jugador*)ll_get(pArrayList, indice);
			 if(jug_getId(auxJugador, &idAux) == 1 && idAux == id)
			 {
				 retorno = indice;
			 }
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

  		printf("    ------------------------------------------------------------------------------------------------------\n"
  			   "    |  ID   |   	Nombre            |  Edad   |	  Posicion    |	 Nacionalidad | IdSeleccion	\n");
  		printf("    | %3d   |  %-18s 	  |  %d     |  	%-10s    | %10s    | %d\n", id, nombreCompleto, jugador->edad, jugador->posicion, jugador->nacionalidad, jugador->idSeleccion);
  		printf("    -----------------------------------------------------------------------------------------------------\n");

  		retorno = 1;
  	}

  	return retorno;
  }

 /*---------------------------------------------------------------------------------------------------------------------*/

 void mostrarJugadorConSeleccion(Jugador* this, LinkedList* pArrayListSeleccion)
 {

 	int id;
 	char nombreCompleto[SIZE_CADENA];
 	int edad;
 	char posicion[SIZE_CADENA];
 	char nacionalidad[SIZE_CADENA];
 	int idSeleccion;
 	int sizeListSeleccion;
 	char seleccionStr[SIZE_CADENA] = "No convocado";
 	int idSeleccionJug;
 	Seleccion* auxSeleccion;

 	if(this != NULL && pArrayListSeleccion != NULL)
 	{
		jug_getId(this, &id);
		jug_getNombreCompleto(this, nombreCompleto);
		jug_getEdad(this, &edad);
		jug_getPosicion(this, posicion);
		jug_getNacionalidad(this, nacionalidad);
		jug_getSIdSeleccion(this, &idSeleccionJug);

		sizeListSeleccion = ll_len(pArrayListSeleccion);
		for(int i = 0; i < sizeListSeleccion; i++)
		{
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getId(auxSeleccion, &idSeleccion);
			if(idSeleccionJug == idSeleccion)
			{
				selec_getPais(auxSeleccion, seleccionStr);
			}
		}
 	}
 	 printf("\t| %5d | %25s | %5d | %21s | %21s | %20s |\n", id, nombreCompleto, edad, posicion, nacionalidad, seleccionStr);
 }


 int listarJugadoresConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
 {
 	int retorno = -1;
 	int size;
 	Jugador* auxJugador;

 	if(ll_isEmpty(pArrayListJugador) == 0)
 	{
 		size = ll_len(pArrayListJugador);
 		puts("\t===================================================================================================================");
 		for(int i = 0; i < size; i++)
 		{
 			auxJugador = ll_get(pArrayListJugador, i);
 			mostrarJugadorConSeleccion(auxJugador, pArrayListSeleccion);
 		}
 		puts("\t===================================================================================================================");
 		retorno = 1;
 	}

     return retorno;
 }

 /*---------------------------------------------------------------------------------------------------------------------*/

int jug_ordenarPorNombreAsc(void *unNombre, void *otroNombre)
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

int jug_ordenarPorNombreDesc(void *unNombre, void *otroNombre)
{
 	int retorno = -1;
 	char nombre_uno[SIZE_CADENA];
 	char nombre_dos[SIZE_CADENA];

 	jug_getNombreCompleto(unNombre, nombre_uno);
 	jug_getNombreCompleto(otroNombre, nombre_dos);

	if (strcmp(nombre_uno, nombre_dos) < 0)
	{
		retorno = 1;
	}

 	return retorno;
 }

int jug_ordenarPorNacionalidadAsc(void *unaNacionalidad, void *otraNacionalidad)
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

int jug_ordenarPorNacionalidadDesc(void *unaNacionalidad, void *otraNacionalidad)
{
 	int retorno = -1;
 	char nacionalidad_uno[SIZE_CADENA];
 	char nacionalidad_dos[SIZE_CADENA];

 	jug_getPosicion(unaNacionalidad, nacionalidad_uno);
 	jug_getPosicion(otraNacionalidad, nacionalidad_dos);

 	if (strcmp(nacionalidad_uno, nacionalidad_dos) < 0)
 	{
 		retorno = 1;
 	}

 	return retorno;
 }

int jug_ordenarPorEdadAsc(void *unaEdad, void *otraEdad)
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

int jug_ordenarPorEdadDesc(void *unaEdad, void *otraEdad)
{
	int retorno = 0;
	int edad_uno;
	int edad_dos;

	jug_getEdad(unaEdad, &edad_uno);
	jug_getEdad(otraEdad, &edad_dos);

	if (edad_uno < edad_dos)
	{
		retorno = 1;
	} else if (edad_uno < edad_dos)
	{
		retorno = -1;
	}
	return retorno;
}

	/*---------------------------------------------------------------------------------------------------------------------*/


int validarPosicion(Jugador* auxJugador,char* cadena)
{
	int retorno = -1;
	int posicion;

	fflush(stdin);

	if(auxJugador != NULL && cadena != NULL)
	{
		obtenerNumero(&posicion, "\nIngrese posicion: "
				"\n1.Portero"
				"\n2.Defensa Central"
				"\n3.Lateral Izquierdo"
				"\n4.Lateral Derecho"
				"\n5.Pivote"
				"\n6.Medio Centro"
				"\n7.Extremo Izquierdo"
				"\n8.Extremo Derecho"
				"\n9.Media Punta"
				"\n10.Delantero Central"
				"\nPosicion: ", "¡DATO INVALIDO!", 1, 10, 50);

		switch(posicion)
		{
			case 1:
				cadena = "Portero";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 2:
				cadena = "Defensa Central";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 3:
				cadena = "Lateral Izquierdo";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 4:
				cadena = "Lateral Derecho";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 5:
				cadena = "Pivote";
				strcpy(auxJugador->posicion,cadena);
				break;


			case 6:
				cadena = "Medio Centro";
				strcpy(auxJugador->posicion,cadena);
				break;


			case 7:
				cadena = "Extremo Izquierdo";
				strcpy(auxJugador->posicion,cadena);
				break;


			case 8:
				cadena = "Extremo Derecho";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 9:
				cadena = "Media Punta";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 10:
				cadena = "Delantero Central";
				strcpy(auxJugador->posicion,cadena);
				break;

		}

		retorno = 1;
	}

	return retorno;
}

int validarNacionalidad(Jugador* auxJugador,char* cadena)
{
	int retorno = -1;
	int nacionalidad;

	fflush(stdin);

	if(auxJugador != NULL && cadena != NULL)
	{
		puts("\nIngrese nacionalidad: "
				"\n1 - Argentino"
				"\n2 - Brasilero"
				"\n3 - Portugués"
				"\n4 - Ingles"
				"\n5 - Alemán"
				"\n6 - Mexicano"
				"\n7 - Estadounidense"
				"\n8 - Cameunes"
				"\n9 - Senegales"
				"\n10 - Australiano"
				"\n11 - Qatarí");

		obtenerNumero(&nacionalidad, "\nNacionalidad: ", "¡DATO INVALIDO!", 1, 11, 50);

		switch(nacionalidad)
		{
			case 1:
				cadena = "Argentino";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 2:
				cadena = "Brasilero";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 3:
				cadena = "Portugués";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 4:
				cadena = "Ingles";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 5:
				cadena = "Alemán";
				strcpy(auxJugador->nacionalidad,cadena);
				break;


			case 6:
				cadena = "Mexicano";
				strcpy(auxJugador->nacionalidad,cadena);
				break;


			case 7:
				cadena = "Estadounidense";
				strcpy(auxJugador->nacionalidad,cadena);
				break;


			case 8:
				cadena = "Cameunes";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 9:
				cadena = "Senegales";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 10:
				cadena = "Australiano";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

			case 11:
				cadena = "Qatarí";
				strcpy(auxJugador->nacionalidad,cadena);
				break;

		}

		retorno = 1;
	}

	return retorno;
}

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
		listarJugadoresConSeleccion(pArrayListJugador, pArrayListSeleccion);
		obtenerNumero(&idAux, "\nIngrese el id del jugador a convocar: ", "Dato invalido", 1, idAux, 5);
		indice_jug = buscarPorID(pArrayListJugador, idAux);
		jug_convocado = (Jugador*) ll_get(pArrayListJugador, indice_jug);

		if(indice_jug != -1)
		{
			controller_listarSelecciones(pArrayListSeleccion);
			obtenerNumero(&id_seleccion, "\nIngrese el id de seleccion a convocar: ", "Dato invalido", 1, ll_len(pArrayListSeleccion), 5);

			indice_selec = selec_buscarPorID(pArrayListSeleccion, id_seleccion);

			if(indice_selec != -1)
			{
				seleccion_convocado = (Seleccion*)ll_get(pArrayListSeleccion, indice_selec);

				jug_setIdSeleccion(jug_convocado, id_seleccion);
				selec_getId(seleccion_convocado, &id_seleccion);

				selec_getConvocados(seleccion_convocado, &cantidadConvocados);

				if(cantidadConvocados < 22)
				{
					selec_getConvocados(seleccion_convocado, &cantidadConvocados);
					cantidadConvocados++;
					selec_setConvocados(seleccion_convocado, cantidadConvocados);
					puts("\n El jugador que usted convoco es: ");
					mostrarUnJugador(jug_convocado);
					retorno = 1;
				}else{
				puts("\n------------------------------------------"
					 "\n ----- ESTA SELECCION ESTA COMPLETA -----"
					 "\n------------------------------------------");

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

			puts("\n¡El Jugador fue desonvocado correctamente!"
				 "\nEl jugador que usted desconvoco es: ");
			mostrarUnJugador(jug_convocado);
			retorno = 1;
		}

	}

	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	Jugador *auxJugador;
	int idSeleccion;
	int retorno = -1;
	int size;

	if(pArrayListJugador != NULL)
	{
		size = ll_len(pArrayListJugador);

		for (int i = 0; i < size; i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(auxJugador, &idSeleccion);

			if(idSeleccion > 0)
			{
				mostrarUnJugador(auxJugador);
				retorno = 1;
			}
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
	int size;

	pFile = fopen("data.bin","wb");

	size = ll_len(pArrayListJugadores);
	for(int i = 0; i < size;i++)
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


int jug_obtenerDatos(Jugador* this,int* id,char* nombreCompleto,int* edad,char* posicion,char* nacionalidad,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL)
	{
		jug_getId(this, id);
		jug_getNombreCompleto(this, nombreCompleto);
		jug_getEdad(this, edad);
		jug_getPosicion(this, posicion);
		jug_getNacionalidad(this, nacionalidad);
		jug_getSIdSeleccion(this, idSeleccion);
		retorno = 1;
	}

	return retorno;
}



int jug_guardarModoTextoCsv(FILE* pFile, LinkedList* pArrayList)
{
    Jugador* auxJugador;

    int retorno = -1;
    int ID;
    char nombreCompleto[SIZE_CADENA];
	int edad;
	char posicion[SIZE_CADENA];
	char nacionalidad[SIZE_CADENA];
	int idSeleccion;
    int size;
    int bandera = 1;

    if(pFile != NULL && pArrayList != NULL)
    {
        size = ll_len(pArrayList);

        for(int i=0; i<size; i++)
        {
            auxJugador = ll_get(pArrayList,i);
            jug_obtenerDatos(auxJugador, &ID, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion);
            if(bandera)
            {
            	fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");
            	bandera = 0;
            }
            fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",ID,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
            retorno = 1;
        }
    }

    return retorno;
}
