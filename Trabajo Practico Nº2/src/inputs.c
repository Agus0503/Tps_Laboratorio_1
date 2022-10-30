/*
 * inputs.c
 *
 *  Created on: 18 oct 2022
 *      Author: DIEGO
 */

#include "inputs.h"

//OBTENER NUMERO ENTERO ========================================================================================
int obtenerNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int bufferInt;
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){

		do{

			printf("%s", mensaje);
			scanf("%d", &bufferInt);

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
char pedirChar(char cadena){
	char caracter;
	printf("Ingresar caracter (1 solo caracter)...");
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}

int getString(char cadena[], int longitud)
{
   int retorno = -1;
   if (cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
   {
       fflush (stdin);
       if (cadena[ strlen (cadena)-1] == '\n' )
       {
           cadena[ strlen (cadena)-1] = '\0' ;
       }

       retorno = 1;
   }
   return retorno;
}

void obtenerString(char *mensaje,char *palabra)
{
	if(palabra!=NULL && mensaje!=NULL)
	{
		fflush(stdin);
		printf("%s",mensaje);
		gets(palabra);
	}

}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


