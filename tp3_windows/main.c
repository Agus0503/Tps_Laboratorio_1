#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"

int main()
{
	inicio:
	setbuf(stdout,NULL);

    int option;
    int elegirOrden;
    char confederacion[SIZE_CADENA];

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    //puts("funciona OK");

    do{
    	puts("\n =================== MENU PRINCIPAL =================== \n");


    	obtenerEnteroRemastered(&option, "\nQue desea realizar?"
									   "\n1.Cargar archivos"
									   "\n2.ALTA"
									   "\n3.MODIFICACION"
									   "\n4.BAJA"
									   "\n5.Listados"
									   "\n6.Convocar jugadores"
									   "\n7.Ordenar y listar"
									   "\n8.Generar archivo Binario"
									   "\n9.Cargar archivo Binario"
									   "\n10.Guardar archivo .CSV"
									   "\n11.SALIR"
									   "\nIngrese su opcion: ", "\n¡OPCION INCORRECTA!\n\n", 1, 11);

    	switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
				controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);

                break;

            case 2:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
            	{
            		puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
            		break;
            	}
					if(controller_agregarJugador(listaJugadores) == 1)
					{
						puts("\n-----------------------------------------"
							 "\n ---------- ALTA EXITOSA ---------- "
							 "\n-----------------------------------------");
					}

            	break;

            case 3:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

				if(controller_editarJugador(listaJugadores) == 1)
				{
					puts("\n-----------------------------------------"
						 "\n ----- MODIFICACION EXITOSA -----"
						 "\n-----------------------------------------");
				}

            	break;

            case 4:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	if(controller_removerJugador(listaJugadores) == 1)
				{
					puts("\n-----------------------------------------"
						 "\n ---------- BAJA EXITOSA ---------- "
						 "\n-----------------------------------------");
				}

				break;

            case 5:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	do{

            		obtenerNumero(&option, "\nQue lista desea ver?"
            				"\n1.TODOS LOS JUGADORES"
            				"\n2.SELECCIONES"
            				"\n3.CONVOCADOS"
            				"\n4.VOLVER AL INICIO"
            				"\nIngrese opcion: ", "La opcion ingresada es incorrecta", 1, 4, 5);

            		switch(option)
            		{

						case 1:
							controller_listarJugadores(listaJugadores);
							break;

						case 2:
							controller_listarSelecciones(listaSelecciones);
							break;


						case 3:
							if(controller_listarJugadoresConvocados(listaJugadores) == -1)
							{
								puts("\n NO HAY JUGADORES CONVOCADOS PARA LISTAR");
							}
							break;
            		}


            	}while(option != 4);
            	break;

            case 6:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	do{
            	obtenerNumero(&option, "\nQUE DESEA REALIZAR?"
            						   "\n1.CONVOCAR"
            						   "\n2.DESCONVOCAR"
            						   "\n3.VOLVER AL INICIO"
            						   "\nIngrese opcion: ", "DATO INVALIDO", 1, 3, 5);
            		switch(option)
            		{
            			case 1:
                        	if(convocarJugador(listaJugadores, listaSelecciones) == 1)
							{
                        		puts("\n ¡El jugador fue convocado correctamente!");

							}
            				break;

            			case 2:
            			    desconvocarJugador(listaJugadores, listaSelecciones);
            			    break;

            			case 3:
            			      puts("SALIENDO..");
            			    break;
            		}
            	}while(option != 3);

            	break;

            case 7:/*ORDEN Y LISTAS*/

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	do{
            	obtenerNumero(&elegirOrden, "\nQue desea ordenar?"
											"\n1.Jugadores"
											"\n2.Selecciones"
											"\n3.Volver al inicio"
											"\nOpcion: ", "La opcion ingresada es incorrecta", 1, 3, 4);

            	switch(elegirOrden)
            	{

					case 1:
						if(controller_ordenarJugadores(listaJugadores) == 1)
						{
							puts("\n---------- La lista fue ordenada correctamente! ----------");
						}

						break;

					case 2:
						if(controller_ordenarSelecciones(listaSelecciones) == 1)
						{
							puts("\n---------- La lista fue ordenada correctamente! ----------");
						}
						break;

					case 3:
						puts("saliendo..");
						break;
            	}

            	}while(elegirOrden != 3);
            	break;

            case 8: /*GENERAR ARCHIVO BINARIO*/

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	do{
            		obtenerEnteroRemastered(&option, "\nQue confederacion desea guardar?"
											"\n1.UEFA"
											"\n2.CONMEBOL"
											"\n3.AFC"
											"\n4.CAF"
											"\n5.CONCACAF"
											"\n6.SALIR"
											"\nOpcion: ", "La opcion ingresada es incorrecta", 1, 6);

            		switch(option)
            		{
						case 1:
							strcpy(confederacion,"UEFA");
							break;

						case 2:
							strcpy(confederacion,"CONMEBOL");
							break;

						case 3:
							strcpy(confederacion,"AFC");
							break;

						case 4:
							strcpy(confederacion,"CAF");
							break;

						case 5:
							strcpy(confederacion,"CONCAF");
							break;

						case 6:
							puts("\nRegresando..");
							break;
            		}

					if(cargarConvocados(confederacion, listaJugadores, listaSelecciones) == 1)
					{
						puts("---------------------------------"
							 "\nARCHIVO CARGADO CORRECTAMENTE"
							 "\n-------------------------------");
					}else{
						puts("\n ----- NO HAY JUGADORES DE ESTA CONFEDERACION PARA CARGAR -----");
					}

            	}while(option != 6);

            	break;

            case 9:

            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	imprimirDatosCargadosEnBinario("dataPrint.bin");
            	break;

            case 10:
            	if(ll_isEmpty(listaJugadores) == 1 && ll_isEmpty(listaSelecciones) == 1)
				{
					puts("\nERROR, La lista esta vacia!, Asegurese de cargar los archivos primero");
					break;
				}

            	if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 1 && controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones) == 1)
            	{
            		puts("\n****Datos guardados correctamente****");
            	}

            	break;

            case 11:

				puts("\n ----- ALERTA! ----- "
					"\nEs posible que no se hayan registrado cambios, Desea salir de todas formas?");

				obtenerEnteroRemastered(&option, "\n1.Si"
									   "\n2.No"
									   "\nIngrese una opcion: ", "\nLa opcion ingresada es incorrecta", 1, 2);

				if(option == 1)
				{
					option = 11;
				}
					puts("Adios..");

            	break;


            default:
            	goto inicio;
				break;

        }

    }while(option != 11);


    return 0;

  }

