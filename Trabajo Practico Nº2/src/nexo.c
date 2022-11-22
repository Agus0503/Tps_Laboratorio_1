/*
 * nexo.c
 *
 *  Created on: 20 nov 2022
 *      Author: DIEGO
 */

#include "nexo.h"


void mostrar(sJugador jugador,sConfederacion conf[],int size)
{
	char nombreConf[SIZE_CADENA];

	for(int i = 0; i < size; i++)
	{
		if(conf[i].id == jugador.idConfederacion)
		{
			strcpy(nombreConf,conf[i].nombre);
			break;
		}
	}

	printf("\n    %d |  %10s   |   %10s   |  %2hd   |  %.2f   |   %5s   |   %hd   |", jugador.id, jugador.nombre, jugador.posicion,jugador.numeroCamiseta,jugador.salario,nombreConf,jugador.aniosContrato);
	puts("\n----------------------------------------------------------------------------------------------------------\n");

}

int mostrarTodo(sJugador jugador[],int sizeJug ,sConfederacion conf[])
{
	int retorno = -1;

	if(jugador != NULL && conf != NULL && sizeJug > 0)
	{
		   puts("\nLISTADO JUGADORES:");
		   puts("===========================================================================================================\n");
		   puts("|  ID  |       NOMBRE       |      POSICION      | CAMISETA |   SUELDO   | CONFEDERACION | AÑOS DE CONTRATO|\n");
		   puts("===========================================================================================================");

		for(int i = 0; i < sizeJug; i++)
		{
			if(jugador[i].isEmpty == OCUPADO)
			{
				ordenarPorNombre(jugador, sizeJug);
				mostrar(jugador[i], conf,sizeJug);

			}
		}

		retorno = 1;
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void mostrarConfConJugadores(sJugador jugador,sConfederacion arrayConf[],int size)
{

	char nombreConf[SIZE_CADENA];

	for(int i = 0; i < size; i++)
	{
		if(arrayConf[i].id == jugador.idConfederacion)
		{
			strcpy(nombreConf,arrayConf[i].nombre);
			break;
		}
	}

	printf("\n    %d |  %10s   |   %10s   |  %hd   |  %.2f   |   %d   |   %hd   |", jugador.id, jugador.nombre, jugador.posicion,jugador.numeroCamiseta,jugador.salario,jugador.idConfederacion,jugador.aniosContrato);
	puts("\n----------------------------------------------------------------------------------------------------------\n");


}

int mostrarJugadoresConmebol(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE CONMEBOL -----"
		"\n=======================================");

		for(int i = 0; i <= size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 100)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

int mostrarJugadoresUefa(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE UEFA -----"
		"\n=======================================");

		for(int i = 0; i < size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 101)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

int mostrarJugadoresAfc(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE AFC -----"
		"\n=======================================");

		for(int i = 0; i < size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 102)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

int mostrarJugadoresCaf(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE CAF -----"
		"\n=======================================");

		for(int i = 0; i < size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 103)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

int mostrarJugadoresConcacaf(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE CONCACAF -----"
		"\n=======================================");

		for(int i = 0; i < size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 104)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

int mostrarJugadoresOfc(sJugador arrayJug[],sConfederacion arrayConf[],int size)
{
	int retorno = -1;

	if(arrayJug != NULL && arrayConf != NULL && size > 0)
	{
	puts("========================================"
		"\n ------ JUGADORES DE OFC -----"
		"\n=======================================");

		for(int i = 0; i < size; i++)
		{
			if(arrayJug[i].isEmpty == OCUPADO)
			{
				if(arrayJug[i].idConfederacion == 105)
				{
					mostrarConfConJugadores(arrayJug[i], arrayConf, size);
				}
			}

		}

		retorno = 1;
	}else{
		puts("\n----  -------  ------  -----  ------  "
			"\n  ¡ NO HAY JUGADORES PARA LISTAR !"
			 "\n----   ------  ------  ------  -----");
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int confMasAniosDeContrato(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf)
{
	int retorno = -1;
	char guardarNombreConf[SIZE_CADENA];
	int aniosContrato = 0;
	int maxAniosContrato;

	if(arrayJug != NULL && arrayConf != NULL && sizeJug > 0 && sizeConf > 0)
	{
		for(int i = 0; i < sizeConf; i++)
		{
			for(int j = i; j < sizeJug; j++)
			{
				if(arrayJug[i].isEmpty == OCUPADO)
				{
					if(arrayConf[i].id == arrayJug[j].idConfederacion)
					{
						aniosContrato = aniosContrato + arrayJug[j].aniosContrato;
					}
				}
			}

			if(aniosContrato > maxAniosContrato || i == 0)
			{
				maxAniosContrato = aniosContrato;
				strcpy(guardarNombreConf,arrayConf[i].nombre);
			}

			aniosContrato = 0;

		}

		retorno = 1;
	}

	printf("\nLa confederacion con mas años de contrato es: %s, cuenta con un total de %d años de contrato", guardarNombreConf,maxAniosContrato);

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int PorcentajeJugadores_por_Confederacion(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf)
{
	int retorno = -1;
	int cantJugadores = 0;
	float promedio;

	if(arrayJug != NULL && arrayConf != NULL && sizeJug > 0 && sizeConf > 0)
	{
		for(int i = 0; i < sizeConf; i++)
			{
				for(int j = i; j < sizeJug; j++)
				{
					if(arrayJug[i].isEmpty == OCUPADO)
					{
						if(arrayConf[i].id == arrayJug[j].idConfederacion)
						{
							cantJugadores++;
						}
					}
				}

				promedio = (float) (cantJugadores * 100) / sizeJug;
				puts("------------------------------------------------");
				printf("|El procentaje de jugadores de %s es: %.2f|",arrayConf[i].nombre,promedio);
				puts("\n------------------------------------------------");
				cantJugadores = 0;
			}

		system("PAUSE");
		retorno = 1;
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

int regionConMasJugadores(sJugador arrayJug[],int sizeJug,sConfederacion arrayConf[],int sizeConf)
{
	int retorno = -1;
	int cantJugadores = 0;
	int maxCantJugadores;
	char guardarNombre[SIZE_CADENA];

	if(arrayJug != NULL && arrayConf != NULL && sizeJug > 0 && sizeConf > 0)
	{
		for(int i = 0; i < sizeConf; i++)
		{
			for(int j = i; j < sizeJug; j++)
			{
				if(arrayJug[i].isEmpty == OCUPADO)
				{
					if(arrayConf[i].id == arrayJug[j].idConfederacion)
					{
						cantJugadores++;
					}
				}

			}

			if(cantJugadores > maxCantJugadores || i == 0)
			{
				maxCantJugadores = cantJugadores;
				strcpy(guardarNombre,arrayConf[i].region);
			}

			cantJugadores = 0;
		}

		retorno = 1;
	}

	puts("\n--------------------------------------------------------------------");
	printf("|La region con mas jugadores es: %s, contando con %d jugadores ",guardarNombre,maxCantJugadores);
	puts("\n--------------------------------------------------------------------");

	return retorno;

}
