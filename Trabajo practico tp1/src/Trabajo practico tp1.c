/*
 ============================================================================
 Name        : Diego Agustin Ostua Larramendia
 DIV 		 : C
 Description : Debemos conformar un equipo para competir en el próximo mundial.
	La formación del equipo titular será 1-4-4-2 (arquero, defensores, mediocampistas y
	delanteros).
	Hay que tener presente que no podemos superar la cantidad máxima de 22 jugadores y
	no más de dos por posición, es decir, en total deberíamos tener 2 arqueros, 8 defensores,
	8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).
	Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
	Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.
	Nota: de estos 3 valores surge el gasto de mantenimiento.
	Los jugadores pueden desarrollar sus actividades en cualquiera de las 6 confederaciones:
	AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
	UEFA en Europa; OFC en Oceanía
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "obtener.h"
#include "utn_get.h"

int subMenuConfederaciones(int auxCantidadCaf,int auxCantidadUefa,int auxCantidadConcaf,int auxCantidadOfc,int auxCantidadConmebol,int auxCantidadAfc, int auxCantidadTotal);

int main(void) {

	setbuf(stdout,NULL);

//VARIABLES MENU PRINCIPAL
	int opcion;

//VARIABLES PARA MUESTREO DE DATOS
	float auxCostoHospedaje;
	float auxCostoComida;
	float auxCostoTransporte;
	float costoMantenimiento;
	float costoMantenimientoAumento;
	float costoMantenimientoConAumento;

	int cantidadArqueros;
	int cantidadDefensores;
	int cantidadMediocampistas;
	int cantidadDelanteros;

	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;

	int cantidadAfc;
	int cantidadCaf;
	int cantidadConcaf;
	int cantidadConmebol;
	int cantidadUefa;
	int cantidadOfc;
	int cantidadTotal;

//BANDERAS DE VALIDACION DE ENTRADA

	int banderaOpcionTresA;
	int banderaOpcionTresB;
	int banderaOpcionCuatroEntrada;


//INICIALIZACION DE VARIABLES PARA MUESTREO DE DATOS
	auxCostoHospedaje = 0;
	auxCostoComida = 0;
	auxCostoTransporte = 0;

	cantidadArqueros = 0;
	cantidadDefensores = 0;
	cantidadMediocampistas = 0;
	cantidadDelanteros = 0;

	cantidadOfc = 0;
	cantidadAfc = 0;
	cantidadCaf = 0;
	cantidadConcaf = 0;
	cantidadConmebol = 0;
	cantidadUefa = 0;
	cantidadTotal = 0;

	banderaOpcionTresA = 0;
	banderaOpcionTresB = 0;
	banderaOpcionCuatroEntrada = 0;


		do{
			puts("\n--------------------------------------");
			printf("==========MENU PRINCIPAL==========");
			puts("\n--------------------------------------\n");
			printf("1- Ingresar costos de mantenimiento\n");
			printf(" -Costo de hospedaje -> $%.2f\n", auxCostoHospedaje);
			printf(" -Costo de comida -> $%.2f\n", auxCostoComida);
			printf(" -Costo de transporte -> $%.2f\n", auxCostoTransporte);

			printf("2- Ingresar Jugadores\n");
			printf(" -ARQUEROS  -> %d\n", cantidadArqueros);
			printf(" -DEFENSORES -> %d\n", cantidadDefensores);
			printf(" -MEDIOCAMPISTAS -> %d\n", cantidadMediocampistas);
			printf(" -DELANTEROS -> %d\n", cantidadDelanteros);

			printf("3- Realizar calculos\n");
			printf("4- Informar resultados\n");
			printf("5- SALIR\n");
			printf("Seleccione una opcion: ");
			scanf("%d", &opcion);

			switch(opcion){

				case 1:
					subMenuGastos(&auxCostoHospedaje, &auxCostoComida, &auxCostoTransporte);
					if(auxCostoHospedaje && auxCostoComida && auxCostoTransporte > 0){
						banderaOpcionTresA = 1;
					}
				break;

				case 2:
					if(subMenuJugadores(&cantidadArqueros, &cantidadDefensores, &cantidadMediocampistas, &cantidadDelanteros, &banderaOpcionTresB) == 1){
						subMenuConfederaciones(cantidadCaf, cantidadUefa, cantidadConcaf, cantidadOfc, cantidadConmebol, cantidadCaf, cantidadTotal);
						if(cantidadArqueros || cantidadDefensores || cantidadMediocampistas || cantidadDelanteros || banderaOpcionTresB > 0){
							banderaOpcionTresB = 1;
						}
					}
				break;

				case 3:
					if(banderaOpcionTresA == 1 && banderaOpcionTresB == 1){
						costoMantenimiento = auxCostoHospedaje + auxCostoComida + auxCostoTransporte;
						promedioAfc = (float)calcularPromedioAfc(&cantidadAfc);
						promedioCaf= (float)calcularPromedioCaf(&cantidadCaf);
						promedioOfc = (float)calcularPromedioOfc(&cantidadOfc);
						promedioConcacaf= (float)calcularPromedioConcaf(&cantidadConcaf);
						promedioConmebol = (float)calcularPromedioConmebol(&cantidadConmebol);
						promedioUefa = (float)calcularPromedioUefa(&cantidadUefa);
						if(cantidadUefa > cantidadAfc && cantidadUefa > cantidadCaf && cantidadUefa > cantidadConcaf && cantidadUefa > cantidadConmebol && cantidadUefa > cantidadOfc){
							costoMantenimientoAumento = costoMantenimiento * 0.35;
							costoMantenimientoConAumento += costoMantenimiento * 0.35;
						}
						puts("--------------------------------------");
						printf("Los calculos se realizaron correctamente\n");
						puts("--------------------------------------");
						banderaOpcionCuatroEntrada = 1;
					}else{
						puts("\n------------------------------------------------");
						printf("ALERTA! Primero debe ingresar los costos de mantenimiento y al menos 1 jugador\n");
						puts("------------------------------------------------");

					}
				break;

				case 4:
					if(banderaOpcionCuatroEntrada == 1){
						puts("--------------------------------------");
						printf("Promedio de jugadores de Afc %.2f \n", promedioAfc);
						printf("Promedio de jugadores de Caf %.2f \n", promedioCaf);
						printf("Promedio de jugadores de Concacaf %.2f \n",promedioConcacaf);
						printf("Promedio de jugadores de Conmebol %.2f \n",promedioConmebol);
						printf("Promedio de jugadores de Uefa %.2f \n",promedioUefa);
						printf("Promedio de jugadores de Ofc %.2f \n",promedioOfc);
						if(cantidadUefa > cantidadAfc && cantidadUefa > cantidadCaf && cantidadUefa > cantidadConcaf && cantidadUefa > cantidadConmebol && cantidadUefa > cantidadOfc){
							printf("El costo de mantenimiento era de %.2f ",costoMantenimiento);
							printf("\nRecibio un aumento de $ %.2f",costoMantenimientoAumento);
							printf("su nuevo valor es de: $ %.2f",costoMantenimientoConAumento);
						}else{
							printf("El costo de mantenimiento es de %.2f ",costoMantenimiento);
						}
						puts("\n--------------------------------------");
					}else{
					printf("ERROR, primero debe realizar los calculos para mostrar resultados o faltan datos por ingresar");
				}
				system("pause");
				fflush(stdin);
				break;

				case 5:
					printf("Gracias por utilizar este servicio");
				break;

				default:
					printf("Error, elija las opciones disponbles: ");
					scanf("%d", &opcion);
				break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}



// ===================== SUBMENU CONFEDERACIONES =====================
/// @brief
/// @param auxCantidadCaf
/// @param auxCantidadUefa
/// @param auxCantidadConcaf
/// @param auxCantidadOfc
/// @param auxCantidadConmebol
/// @param auxCantidadAfc
/// @param auxCantidadTotal
/// @return Devuele valor 1 si se cumplen las condiciones
int subMenuConfederaciones(int auxCantidadCaf,int auxCantidadUefa,int auxCantidadConcaf,int auxCantidadOfc,int auxCantidadConmebol,int auxCantidadAfc, int auxCantidadTotal){

	int retorno;
	int opcionLiga;

	auxCantidadAfc = 0;

	retorno = -1;

	printf("\n--------------------------------");
	printf("\n-----SELECCIONE LIGA----- \n");
	printf("--------------------------------");
	printf("\n 1- AFC");
	printf("\n 2- CAF");
	printf("\n 3- CONCAF");
	printf("\n 4- CONMEBOL");
	printf("\n 5- UEFA");
	printf("\n 6- OFC");
	printf("\nSeleccione Liga: ");
	scanf("%d", &opcionLiga);

			switch(opcionLiga){

				case 1:
					auxCantidadAfc++;
					calcularPromedioAfc(&auxCantidadAfc);
					retorno = 1;
				break;

				case 2:
					auxCantidadCaf++;
					calcularPromedioCaf(&auxCantidadCaf);
					retorno = 1;
				break;

				case 3:
					auxCantidadConcaf++;
					calcularPromedioCaf(&auxCantidadConcaf);
					retorno = 1;
				break;

				case 4:
					auxCantidadConmebol++;
					calcularPromedioCaf(&auxCantidadConmebol);
					retorno = 1;
				break;

				case 5:
					auxCantidadUefa++;
					calcularPromedioCaf(&auxCantidadUefa);
					retorno = 1;
				break;

				case 6:
					auxCantidadOfc++;
					calcularPromedioCaf(&auxCantidadOfc);
					retorno = 1;
				break;

				case 7:
				break;
			}

		return retorno;
}
