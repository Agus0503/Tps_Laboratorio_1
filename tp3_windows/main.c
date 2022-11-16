#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"

int main()
{
	setbuf(stdout,NULL);

    int option;
    int elegirOrden;
    char confederacion_uno[SIZE_CADENA];

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    puts("funciona OK");

    do{
    	obtenerNumero(&option, "1.Cargar archivos"
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
							   "\nIngrese su opcion: ", "\n¡OPCION INCORRECTA!\n\n", 1, 11, 0);

    	switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
                break;

            case 2:
            	if(controller_agregarJugador(listaJugadores))
            	{
            		puts("----------------"
            			 "\nALTA EXITOSA"
            			 "\n--------------");
            	}
            	break;

            case 3:
            	if(controller_editarJugador(listaJugadores) == 1)
            	{
            		puts("---------------------"
            			 "\nMODIFICACION EXITOSA"
            			 "\n---------------------");
            	}
            	break;

            case 4:
            	if(controller_removerJugador(listaJugadores))
            	{
            		puts("---------------"
            			 "\nBAJA EXITOSA"
            			 "\n--------------");
            	}
				break;

            case 5:
            	puts("-----------TODOS-----------");
            	controller_listarJugadores(listaJugadores);
            	puts("-----------SELECCIONES---------");
            	controller_listarSelecciones(listaSelecciones);
            	puts("-----------CONVOCADOS---------");
        		controller_listarJugadoresConvocados(listaJugadores);
            	break;

            case 6:
            	/*CONVOVAR JUGADORES*/
            	do{
            	obtenerNumero(&option, "\nQUE DESEA REALIZAR?"
            						   "\n1.CONVOCAR"
            						   "\n2.DESCONVOCAR"
            						   "\n3.CANCELAR"
            						   "\nIngrese opcion: ", "DATO INVALIDO", 1, 3, 5);
            		switch(option)
            		{
            			case 1:
                        	convocarJugador(listaJugadores, listaSelecciones);
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

            case 7:
            	/*ORDEN Y LISTAS*/

            	do{
            	obtenerNumero(&elegirOrden, "\nQue desea ordenar?"
            			"\n1.Jugadores"
            			"\n2.Selecciones"
            			"\n3.Cancelar"
            			"\nOpcion: ", "La opcion ingresada es incorrecta", 1, 3, 4);

            	switch(elegirOrden)
            	{

					case 1:
						controller_ordenarJugadores(listaJugadores);
						break;

					case 2:
						controller_ordenarSelecciones(listaSelecciones);
						break;

					case 3:
						puts("saliendo..");
						break;
            	}

            	}while(elegirOrden != 3);
            	break;

            case 8:
            	do{
            		obtenerNumero(&option, "\nQue desea listar?"
											"\n1.UEFA"
											"\n2.CONMEBOL"
											"\n3.AFC"
											"\n4.CAF"
											"\n5.CONCACAF"
											"\n6.SALIR"
											"\nOpcion: ", "La opcion ingresada es incorrecta", 1, 6, 4);

            		switch(option)
            		{
						case 1:
							strcpy(confederacion_uno,"UEFA");
							break;

						case 2:
							strcpy(confederacion_uno,"CONMEBOL");
							break;

						case 3:
							strcpy(confederacion_uno,"AFC");
							break;

						case 4:
							strcpy(confederacion_uno,"CAF");
							break;

						case 5:
							strcpy(confederacion_uno,"CONCAF");
							break;

						case 6:
							puts("NOS RE VIMOS EN NARNIA");
							break;
            		}

					if(cargarConvocados(confederacion_uno, listaJugadores, listaSelecciones)==1)
					{
						puts("---------------------------------"
							 "\nARCHIVO CARGADO CORRECTAMENTE"
							 "\n-------------------------------");
					}

            	}while(option != 6);

            	break;

            case 9:
            	imprimirDatosCargadosEnBinario("dataPrint.bin");
            	break;

            case 10:
            	guardarArchivoCsv("jugadores.csv", listaJugadores);
            	break;

            case 11:
            	puts("Adios..");
            	break;
        }

    }while(option != 11);


    return 0;

  }

