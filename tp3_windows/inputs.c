/*
 * inputs.c
 *
 *  Created on: 1 nov 2022
 *      Author: DIEGO
 */

#include "inputs.h"

//OBTENER NUMERO ENTERO ========================================================================================

int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 )
	{

		do{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*resultado = bufferInt;
				retorno = 1;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

//OBTENER NUMERO FLOTANTE ====================================================================================================
int obtenerNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){

	float bufferFloat;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{

			printf("%s", mensaje);
			scanf("%f", &bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*resultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

//OBTENER DATO TIPO SHORT ============================================================================================
int obtener_Tipo_Short(short* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	short bufferInt;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{

			printf("%s", mensaje);
			scanf("%hi", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*resultado = bufferInt;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

//PEDIRCHAR - PEDIRCADENA ============================================================================
char pedirChar(char cadena)
{
	char caracter;
	printf("Ingresar caracter (1 solo caracter)...");
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}

	/*---------------------------------------------- VALIDAR CADENAS ----------------------------------------------*/

int obtenerString(char cadena[], int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0)
	{
		fflush(stdin); //Windows
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int validarNombre(char *cadena, int longitud)
{
	int retorno = 1;

	if (cadena != NULL && longitud > 0)
	{
		for (int i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if ((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

static int aux_ObtenerCadena(char* pResultado, int longitud){

	int retorno=-1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(obtenerString(buffer,sizeof(buffer))==0 && validarNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @brief	Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * @param	pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param	longitud Es la longitud del array resultado
 * @param	mensaje Es el mensaje a ser mostrado
 * @param	mensajeError Es el mensaje de Error a ser mostrado
 * @param	reintentos Cantidad de reintentos
 * @return	Retorna 1 si se obtuvo el array y -1 si no
 *
 */
int obtenerCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = 0;
	char bufferString[4096];

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(aux_ObtenerCadena(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}

		printf("%s",mensajeError);
	}

	return retorno;
}


// ================================================================== VALIDACIONES ==================================================================
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
 int esCadenaValida(char* cadena,int longitud)
{
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		for(int i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] != ' ') && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

 /**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return 1 = Ok, -1 = Error
 */
int isNumerica(char* cadena, int limite)
{
	int retorno = -1;

 	if (cadena != NULL && strlen (cadena) > 0 && limite > 0)
 	{
 		for(int i=0;i<limite && cadena[i] != '\0';i++)
 		{
 			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
 			{
 				continue;
 			}
 			if(cadena[i] < '0'||cadena[i] > '9')
 			{
 				retorno = 1;
 				break;
 			}
 			//CONTINUE
 		}
 		//BREAK
 	}
 	return retorno;
 }

  /*---------------------------------------------------------------------------------------------------------------------*/

int obtenerEnteroRemastered(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno = -1;
	int numero;
	char buffer[4096];

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do{

			printf("%s",mensaje);
			scanf("%s",buffer);

			if(isNumerica(buffer, maximo))
			{
				numero = atoi(buffer);

				if(numero >= minimo && numero <= maximo)
				{
					*resultado = numero;
					retorno = 1;
				}else{
					printf("%s", mensajeError);
				}

			}else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}

/*---------------------------------------------------------------------------------------------------------------------*/

void minuscula(char cadena[])
{

	int i = 0;

	while(cadena[i] != '\0')
	{
		cadena[i] = tolower(cadena[i]);
		  i++;
	  }
}

void mayusculaInicial(char cadena[])
{
	int cantidad;
	minuscula(cadena);
	cadena[0] = toupper(cadena[0]);
	cantidad = strlen(cadena);

	for (int i=0;i<cantidad;i++)
	{
		if (cadena[i]==' ')
		{
			cadena[i+1] = toupper(cadena[i+1]);
		}
	}
}
