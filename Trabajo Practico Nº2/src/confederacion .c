/*
 * confederacion .c
 *
 *  Created on: 20 nov 2022
 *      Author: DIEGO
 */

#include "confederacion.h"


void menuConfederacion()
{

	puts("\nIngrese ID de confederacion"
			"\n100.CONMEBOL"
			"\n101.UEFA"
			"\n102.AFC"
			"\n103.CAF"
			"\n104.CONCAF"
			"\n105.OFC");

}


void mostrarUnaConf(sConfederacion confederacion)
{
   printf("\n    %d |  %10s   |   %15s   |     %10d   | ", confederacion.id, confederacion.nombre, confederacion.region,confederacion.anioCreacion);
   puts("\n----------------------------------------------------------------------------------------------------------");
}

int mostrarTodasConf(sConfederacion* array, int size)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
	   puts("\nLISTADO CONFEDERACIONES:");
	   puts("===========================================================================================================\n");
	   puts("|  ID  |       NOMBRE       |      REGION      | 	 AÑO DE CREACION	|\n");
	   puts("===========================================================================================================");

	   for (int i = 0; i < size; i++)
	   {
		   mostrarUnaConf(array[i]);
	   }

	   retorno = 1;
	}

	return retorno;
}


int ordenarConfPorId(sConfederacion array[], int size)
{
	int retorno = -1;
	sConfederacion aux;
	int actualSize;
    int bandera;

    if(array != NULL && size >= 0)
    {
    	actualSize = size - 1;

    	do{

    		bandera = 0;

			for(int i = 0; i < actualSize; i++)
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

    	}while(bandera);

    	retorno = 1;
    }

    return retorno;
}


static int conf_ObtenerID(void);
static int conf_ObtenerID(void) {
	static int idIncremental = 0;
	return idIncremental++;
}

int conf_BuscarPorID(sConfederacion array[], int size, int ID)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{

			if (array[i].id == ID )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int conf_ObtenerIndexLibre(sConfederacion array[], int size)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

sConfederacion conf_CargarDatos(void)
{
	sConfederacion auxiliar;

	obtenerCadena(auxiliar.nombre, SIZE_CADENA, "\nIngrese  nombre: ", "¡DATO INVALIDO!", 5);

	obtenerCadena(auxiliar.nombre, SIZE_CADENA, "\nIngrese region: ", "¡DATO INVALIDO!", 5);

	obtenerNumero(&auxiliar.anioCreacion, "\nIngrese año de creacion: ", "¡DATO INVALIDO!", 1900, 1945, 5);

	return auxiliar;
}

int conf_Alta(sConfederacion array[], int size)
{
	int retorno = 0;
	sConfederacion aux;

	int index = conf_ObtenerIndexLibre(array, size);

	if (index != -1)
	{

		aux = conf_CargarDatos();
		aux.id = conf_ObtenerID();
		array[index] = aux;

		retorno = 1;
	}

	return retorno;
}

int conf_Baja(sConfederacion array[], int size)
{

	int retorno = 0;
	int id;
	int index;
	int banera = 0;

	if (mostrarTodasConf(array, size))
	{
		banera = 1;
	}

	if (banera)
	{
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &id);

		while (conf_BuscarPorID(array, size, id) == -1)
		{
			puts("NO EXISTE ID.");

			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &id);
		}

		index = conf_BuscarPorID(array, size, id);

		array[index].isEmpty = -1;

		retorno = 1;
	}

	return retorno;
}

sConfederacion conf_ModificarUno(sConfederacion conf)
{
	sConfederacion auxiliar = conf;

	obtenerCadena(auxiliar.nombre, SIZE_CADENA, "\nIngrese nuevo nombre: ", "¡DATO INVALIDO!", 5);

	obtenerCadena(auxiliar.nombre, SIZE_CADENA, "\nIngrese nueva region: ", "¡DATO INVALIDO!", 5);

	obtenerNumero(&auxiliar.anioCreacion, "\nIngrese nuevo año de creacion: ", "¡DATO INVALIDO!", 1900, 1945, 5);

	return auxiliar;
}

int conf_Modificacion(sConfederacion array[], int size)
{
	int retorno = 0;
	int id;
	int index;
	int bandera = 0;
	sConfederacion auxiliar;

	if (mostrarTodasConf(array, size))
	{
		bandera = 1;
	}

	if (bandera)
	{
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &id);

		while (conf_BuscarPorID(array, size, id) == -1)
		{
			puts("NO EXISTE ID.");

			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &id);
		}


		index = conf_BuscarPorID(array, size, id);

		auxiliar = conf_ModificarUno(array[index]);

		array[index] = auxiliar;

		retorno = 1;
	}

	return retorno;
}
