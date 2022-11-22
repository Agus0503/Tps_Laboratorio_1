/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Diego Agustin Ostua Larramendia
 Division    : C
 Description : Trabajo Practico Nº2 LABO I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

int main(void){

	setbuf(stdout,NULL);

  //LISTA HARDCODEADA PARA PRUEBAS
	sJugador jugadoresTest[15] = {
	       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,OCUPADO},
	       {2,"Juan Musso","ARQUERO",12,100,80000,2,OCUPADO},
	       {3,"Leo Messi","DELANTERO",10,100,80000,4,OCUPADO},
	       {4,"Almirez Ali","DELANTERO",9,100,55000,1,OCUPADO},
	       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,OCUPADO},
	       {6,"Eric Dier","DEFENSOR",3,101,60000,2,OCUPADO},
	       {7,"Harry Kane","DELANTERO",10,101,3000,2,OCUPADO},
	       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,OCUPADO},
	       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,OCUPADO},
	       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,OCUPADO},
	       {11,"Tecatito","DELANTERO",11,104,100000,3,OCUPADO},
	       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,OCUPADO},
	       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,OCUPADO},
	       {14,"Demba Seck","DELANTERO",11,103,6000,2,OCUPADO},
	       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,OCUPADO}
	   };

	int opcionPrincipal;
	sJugador arrayJugadores[SIZE_JUGADORES];
	sConfederacion arrayConfederaciones[SIZE_CONFEDERACIONES] = {
																{100,"CONMEBOL","SUDAMERICA",1916},
																{101,"UEFA","EUROPA",1954},
																{102,"AFC","ASIA",1954},
																{103,"CAF","AFRICA",1957},
																{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
																{105,"OFC","OCEANIA",1966}
																};

	int cantidadJug = 0;

	do{

		puts("Que desea realizar?\n"
				"1.Alta"
				"\n2.Baja"
				"\n3.Modificacion"
				"\n4.Informes"
				"\n5.SALIR");
		printf("\nINGRESE OPCION: ");
		scanf("%d", &opcionPrincipal);

		switch (opcionPrincipal)
		{

		case 1://ALTA
			if(alta(arrayJugadores, SIZE_JUGADORES) == 1)
			{
				puts("\n------------------------"
					 "\n----- ALTA EXITOSA -----"
					 "\n------------------------");
				cantidadJug++;
			}

			break;


		case 2://BAJA

			if(verificarAlta(arrayJugadores, SIZE_JUGADORES) != -1)
			{
				if(baja(arrayJugadores, SIZE_JUGADORES, arrayJugadores->id) == 1)
				{
					puts("\n------------------------"
						 "\n----- BAJA EXITOSA -----"
						 "\n------------------------");
					cantidadJug--;
				}
			}else{
				puts("\n---------- ¡NO HAY JUGADORES DADOS DE ALTA PARA ELIMINAR! ----------");
			}

			break;


		case 3://MODIFICACION

			if(verificarAlta(arrayJugadores, SIZE_JUGADORES) != -1)
			{
				if(modificacion(arrayJugadores, SIZE_JUGADORES, arrayJugadores->id) == 1)
				{
					puts("\n----------------------------------"
						 "\n----- MODIFICACION EXITOSA -----"
						 "\n----------------------------------");
				}
			}else{
				puts("\n---------- ¡NO HAY JUGADORES DADOS DE ALTA PARA MODIFICAR! ----------");
			}
			break;

		case 4://LISTADOS

			if(verificarAlta(arrayJugadores, SIZE_JUGADORES) != -1)
			{

			do{

				obtenerNumero(&opcionPrincipal, "\n --------------- QUE DESEA LISTAR? ---------------"
												"\n1.Jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador"
												"\n2.Listado de confederaciones con sus jugadores"
												"\n3.Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio"
												"\n4.Informar la confederación con mayor cantidad de años de contratos total"
												"\n5.Informar porcentaje de jugadores por cada confederación"
												"\n6.Informar cual es la región con más jugadores y el listado de los mismos"
												"\n7.REGRESAR AL INICIO"
												"\nIngrese opcion: ", "\n¡LA OPCION INGRESADA ES INCORRECTA!", 1, 7, 5);


				switch(opcionPrincipal)
				{

					case 1:
					//mostrarTodo(arrayJugadores, cantidadJug, arrayConfederaciones);
					mostrarTodo(jugadoresTest, 15, arrayConfederaciones); //[OK]
					ordenarConfPorId(arrayConfederaciones, SIZE_CONFEDERACIONES);
					mostrarTodasConf(arrayConfederaciones, SIZE_CONFEDERACIONES);
						break;

					case 2:

					do{
						obtenerNumero(&opcionPrincipal, "\n ---------- QUE CONFEDERACION DESEA LISTAR? ----------"
														"\n1.CONMEBOL"
														"\n2.UEFA"
														"\n3.AFC"
														"\n4.CAF"
														"\n5.CONCACAF"
														"\n6.OFC"
														"\n7.REGRESAR AL INICIO"
														"\nIngrese opcion: ", "\n¡LA OPCION INGRESADA ES INCORRECTA!", 1, 7, 5);

						switch(opcionPrincipal)
						{
							case 1:
								//mostrarJugadoresConmebol(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresConmebol(jugadoresTest, arrayConfederaciones, 15); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

							case 2:
								//mostrarJugadoresUefa(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresUefa(jugadoresTest, arrayConfederaciones, 15); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

							case 3:
								//mostrarJugadoresAfc(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresAfc(jugadoresTest, arrayConfederaciones, 15); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

							case 4:
								//mostrarJugadoresCaf(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresCaf(jugadoresTest, arrayConfederaciones, 15);//PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

							case 5:
								//mostrarJugadoresConcacaf(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresConcacaf(jugadoresTest, arrayConfederaciones, 15); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

							case 6:
								//mostrarJugadoresOfc(arrayJugadores, arrayConfederaciones, cantidadJug);
								mostrarJugadoresOfc(jugadoresTest, arrayConfederaciones, 15);//PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
								break;

						}

					}while(opcionPrincipal != 7);

						break;

					case 3:
						//calcularPromedio_y_total(arrayJugadores, cantidadJug);
						calcularPromedio_y_total(jugadoresTest, 15); //Calculos para la lista hardcodeada
						break;


					case 4:
						//confMasAñosDeContrato(arrayJugadores, cantidadJug, arrayConfederaciones, 6);
						confMasAniosDeContrato(jugadoresTest, 15, arrayConfederaciones, SIZE_CONFEDERACIONES); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
						break;


					case 5:
						//PorcentajeJugadores_por_Confederacion(arrayJugadores, cantidadJug, arrayConfederaciones, 6);
						PorcentajeJugadores_por_Confederacion(jugadoresTest, 15, arrayConfederaciones, SIZE_CONFEDERACIONES); //PRUEBA DE IMPRIMIR PARA LISTA HARDCODEADA
						break;


					case 6:
						regionConMasJugadores(jugadoresTest, 15, arrayConfederaciones, SIZE_CONFEDERACIONES);
						break;


					case 7:
						puts("\n");
						break;

					default:
						puts("\nERROR, SELECCIONE LAS OPCIONES DISPONIBLES..\n");
						break;
				}


			}while(opcionPrincipal != 7);


			}else{
				puts("\n---------- ¡NO HAY JUGADORES DADOS DE ALTA PARA LISTAR! ----------");
			}

			break;

		case 5:
			obtenerNumero(&opcionPrincipal, "\nDesea salir?"
											"\n1.SI"
											"\n2.NO"
											"\nIngrese opcion: ","\n¡LA OPCION INGRESADA ES INCORRECTA!",  1, 2, 5);

			if(opcionPrincipal == 1)
			{
				puts("Adios..");
				opcionPrincipal = 5;
			}

			break;

		default:
			puts("\nERROR, SELECCIONE LAS OPCIONES DISPONIBLES..\n");
			break;

		}

	}while(opcionPrincipal != 5);

	return EXIT_SUCCESS;
}
