/*
 * funciones.c
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#include "funciones.h"

static int obtenerID(void);
static int obtenerID(void)
{
	static int jugador_idIncremental = 0;
	return jugador_idIncremental++;
}

int buscarEspacioLibre(sJugador array[], int size)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPorID(sJugador array[], int size, int ID)
{

	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].id == ID && array[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int verificarAlta(sJugador* array,int size)
{
	int retorno = -1;

	if(array != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

void mostrarUno(sJugador jugador)
{
   printf("\n    %d |  %10s   |   %10s   |  %hd   |  %.2f   |   %d   |   %hd   |", jugador.id, jugador.nombre, jugador.posicion,jugador.numeroCamiseta,jugador.salario,jugador.idConfederacion,jugador.aniosContrato);
   puts("\n----------------------------------------------------------------------------------------------------------\n");
}

int mostrarTodos(sJugador* jugador, int size)
{
	int retorno = -1;

	if (jugador != NULL && size > 0)
	{
	   puts("\nLISTADO:");
	   puts("===========================================================================================================\n");
	   puts("|  ID  |       NOMBRE       |      POSICION      | CAMISETA |   SUELDO   | CONFEDERACION | AÑOS DE CONTRATO|\n");
	   puts("===========================================================================================================\n");

	   for (int i = 0; i < size; i++)
	   {
		  if (jugador[i].isEmpty == OCUPADO)
		  {
			  mostrarUno(jugador[i]);
		  }
	   }

	   retorno = 1;
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int validarPosicion(sJugador* auxJugador,char* cadena)
{
	int retorno = -1;
	int posicion;

	fflush(stdin);

	if(auxJugador != NULL && cadena != NULL)
	{
		obtenerNumero(&posicion, "\nIngrese posicion: "
				"\n1.ARQUERO"
				"\n2.DEFENSOR"
				"\n3.MEDIOCAMPISTA"
				"\n4.DELANTERO"
				"\nPosicion: ", "¡DATO INVALIDO!", 1, 4, 5);


		switch(posicion)
		{
			case 1:
				cadena = "ARQUERO";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 2:
				cadena = "DEFENSOR";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 3:
				cadena = "MEDIOCAMPISTA";
				strcpy(auxJugador->posicion,cadena);
				break;

			case 4:
				cadena = "DELANTERO";
				strcpy(auxJugador->posicion,cadena);
				break;

		}

		retorno = 1;
	}

	return retorno;
}

int alta(sJugador* jugadores, int size)
{
	int retorno = -1;
	char auxCadena[SIZE_CADENA];
	sJugador auxJugador;

	if((jugadores != NULL && size >= 0))
	{
		auxJugador.id = obtenerID();
		obtenerCadena(auxJugador.nombre, SIZE_CADENA, "\nIngrese nombre del jugador: ", "¡DATO INVALIDO!", 5);
		validarPosicion(jugadores,auxCadena);
		obtener_Tipo_Short(&auxJugador.numeroCamiseta, "\nIngrese numero de camiseta: ", "¡DATO INVALIDO!", 1, 99, 5);
		menuConfederacion();
		obtenerNumero(&auxJugador.idConfederacion, "Confederacion: ", "¡DATO INVALIDO!", 100, 105, 5);
		obtenerNumeroFlotante(&auxJugador.salario, "\nIngrese salario: ", "¡DATO INVALIDO!", 75000, 1000000, 5);
		obtener_Tipo_Short(&auxJugador.aniosContrato, "\nIngrese años de contrato: ", "¡DATO INVALIDO!", 1, 10, 5);


		if(cargarDatos(jugadores, size, auxJugador.id, auxJugador.nombre,jugadores->posicion,auxJugador.numeroCamiseta,auxJugador.idConfederacion,
				auxJugador.salario,auxJugador.aniosContrato) == 1)
		{
			retorno = 1;
		}else{
			puts("HUBO UN ERROR EN LA CARGA DE DATOS");
		}

	}

	return retorno;
}


int cargarDatos(sJugador* jugadores, int size, int id, char nombre[],char posicion[],short numeroCamiseta,int idConfederacion,float salario,short aniosContrato)
{

	int retorno = -1;
	int index;
	sJugador auxJugador;

	if(jugadores!=NULL && size >= 0)
	{
		index = buscarEspacioLibre(jugadores,size);

		if (index >= 0)
		{
			auxJugador.id = id;
			strcpy(auxJugador.nombre, nombre);
			strcpy(auxJugador.posicion, posicion);
			auxJugador.numeroCamiseta = numeroCamiseta;
			auxJugador.idConfederacion = idConfederacion;
			auxJugador.salario = salario;
			auxJugador.aniosContrato = aniosContrato;
			auxJugador.isEmpty = 1;
			retorno = 1;
			jugadores[index]=auxJugador;
		}

	}

	return retorno;
}


int baja(sJugador* jugador, int size, int id)
{

	int retorno = -1;
	int indice = -1;

	ordenarPorId(jugador, size);
	mostrarTodos(jugador, size);
	obtenerNumero(&id, "\nIngrese ID a dar de baja: ", "¡DATO INVALIDO!", 0, 3000, 5);

	indice = BuscarPorID(jugador, size, id);

	if(indice != -1)
	{
		mostrarUno(jugador[indice]);
		jugador[indice].isEmpty = LIBRE;
		retorno = 1;
	}
	else{
		printf("El ID ingresado no existe");
		system("pause");
	}

	return retorno;
}


int modificacion(sJugador* array, int size,int id)
{
	int retorno = -1;
	int indice;
	sJugador aux;
	int opcion;
	char auxCadena[SIZE_CADENA];

	ordenarPorId(array, size);
	mostrarTodos(array, size);
	obtenerNumero(&id, "\nIngrese ID a modificar: ", "¡DATO INVALIDO!", 0, 3000, 5);

	indice = BuscarPorID(array, size, id);

	if(indice != -1)
	{

		do{

		puts("\nQue dato desea modificar?"
				"\n1.Nombre"
				"\n2.Posicion"
				"\n3.Numero de Camiseta"
				"\n4.ID Confederacion"
				"\n5.Salario"
				"\n6.Años de Contrato"
				"\n7.SALIR");

		obtenerNumero(&opcion, "\nIngrese opcion: ", "OPCION INCORRECTA", 1, 7, 5);

			switch(opcion)
			{

			case 1: /*NOMBRE*/
				if(obtenerCadena(aux.nombre, SIZE_CADENA, "\nIngrese nuevo nombre: ", "¡DATO INVALIDO!", 5) == 1)
				{
					strncpy(array[indice].nombre,aux.nombre,SIZE_CADENA);
					puts("------- NOMBRE ACTUALIZADO CORRECTAMENTE -------");
				}

				break;

			case 2: /*POSICION*/
				if(validarPosicion(&aux, auxCadena) == 1)
				{
					strncpy(array[indice].posicion,aux.posicion,SIZE_CADENA);
					puts("------- POSICION ACTUALIZADA CORRECTAMENTE -------");
				}

				break;

			case 3: /*NUMERO DE CAMISETA*/
				if(obtener_Tipo_Short(&aux.numeroCamiseta, "\nIngrese nuevo numero de camiseta: ",  "¡DATO INVALIDO!", 1, 99, 5) == 1)
				{
					array[indice].numeroCamiseta = aux.numeroCamiseta;
					puts("------- NUMERO DE CAMISETA ACTUALIZADA CORRECTAMENTE -------");
				}
				break;

			case 4: /*ID CONFEDERACION*/
				menuConfederacion();
				if(obtenerNumero(&aux.idConfederacion,"\nIngrese nuevo ID de confederacion: ", "¡DATO INVALIDO!", 100, 105, 5) == 1)
				{
					array[indice].idConfederacion = aux.idConfederacion;
					puts("------- ID DE CONFEDERACION ACTUALIZADO CORRECTAMENTE -------");
				}

				break;

			case 5: /*SALARIO*/
				if(obtenerNumeroFlotante(&aux.salario, "\nIngrese nuevo salario: ",  "¡DATO INVALIDO!", 75000, 1000000, 5) == 1)
				{
					array[indice].salario = aux.salario;
					puts("------- SALARIO ACTUALIZADO CORRECTAMENTE -------");
				}
				break;

			case 6: /*AÑOS DE CONTRATO*/
				if(obtener_Tipo_Short(&aux.aniosContrato, "\nIngrese años de contrato: ",  "¡DATO INVALIDO!", 1, 10, 5) == 1)
				{
					array[indice].aniosContrato = aux.aniosContrato;
					puts("------- AÑOS DE CONTRATO ACTUALIZADOS CORRECTAMENTE -------");
				}
				break;

			default:
				puts("\nERROR, SELECCIONE LAS OPCIONES DISPONIBLES");
				break;
			}

		}while(opcion != 7);

		retorno = 1;
	}

	return retorno;
}


/*-------------------------------------------------------------------------------------------------------------------------------------------*/


int ordenarPorId(sJugador array[], int size)
{
	sJugador aux;
    int retorno = -1;
    int bandera;
    int actualSize;

    if(array != NULL && size >= 0)
    {
    	actualSize = size - 1;

    	do{

    		bandera = 0;

			for(int i = 0; i < actualSize; i++)
			{
				if (array[i].isEmpty == OCUPADO && array[i + 1].isEmpty == OCUPADO)
				{

					if(array[i].id > array[i + 1].id)
					{
						bandera = 1;
						aux = array[i];
						array[i] = array[i + 1];
						array[i + 1] = aux;
					}

					actualSize--;
				}
			}

    	}while(bandera);

    	retorno = 1;
    }

    return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int ordenarPorNombre(sJugador array[], int size)
{
	int retorno = -1;
	int actualSize;
	int bandera;
	sJugador auxJug;

	if (array != NULL && size > 0)
	{
    	actualSize = size - 1;

    	do{

    		bandera = 0;

			for (int i = 0; i < actualSize; i++)
			{
				if (array[i].isEmpty == OCUPADO && array[i + 1].isEmpty == OCUPADO)
				{
					if(strcmp(array[i].nombre,array[ i + 1].nombre)>0)
					{
						bandera = 1;
						auxJug = array[i];
						array[i] = array[i + 1];
						array[i + 1] = auxJug;

					}

				}

			}

    	}while(bandera);
    	retorno = 1;
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int calcularPromedio_y_total(sJugador array[], int size)
{
	int auxSalario = 0;
	int superaPromedio = 0;
	float promedio;

	if(array != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				auxSalario += array[i].salario;
			}
		}
	}

	promedio = (float) auxSalario / size;

	printf("\n---------------"
			"\n|TOTAL: %d|"
			"\n-------------------", auxSalario);
	printf("\n|PROMEDIO: %.2f|\n"
			"-------------------",promedio);

	for(int i = 0; i < size; i++)
	{
		if(array[i].isEmpty == OCUPADO)
		{
			if(array[i].salario > promedio)
			{
				superaPromedio++;
			}
		}

	}

	printf("----------------------------------------------"
		 "\n|La cantidad de jugadores que superan el salario promedio son: %d|\n"
		 "-----------------------------------------------------------------\n",superaPromedio);

	return promedio;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

