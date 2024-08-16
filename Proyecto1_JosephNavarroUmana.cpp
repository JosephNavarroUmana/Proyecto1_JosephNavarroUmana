#include <iostream>
#include"Proyecto.h"

using namespace std;

int main()
{
	int menu=0;

	pelicula beeMovie("BeeMovie", 2007, 90, "USA", 8.5);
	pelicula adastra("Adastra", 2016, 95,"USA", 7.1);
	pelicula bonderlands("Bonderlands",2024, 102, "USA",7.5);
	pelicula skibiriToilet("Skibiri Toilet: mas toilet que nunca", 2025, 135, "India", 10);

	pelicula coso[4] = { beeMovie, adastra, bonderlands, skibiriToilet };

	sala primerSalaA1(1, " ", 3200);
	sala primerSalaA2(2, " ", 3200);
	sala primerSalaB1(3, " ", 3200);
	sala primerSalaB2(4, " ", 3200);

	sala vector[4] = {primerSalaA1, primerSalaA2, primerSalaB1, primerSalaB2};

	horarios primerHorario("6 de agosto", "2:00", "19:00");
	horarios segundoHorario("6 de agosto", "5:00", " ");
	horarios tercerHorario("6 de agosto", "7:00", " ");

	horarios vec[3] = { primerHorario, segundoHorario, tercerHorario };

	cinema salaDeCine;

	while (menu != 4) {

		system("cls");
		cout << "\n==========+==========+==========+==========+==========\n";
		cout << "            MENU DE OPCIONES\n";
		cout << "==========+==========+==========+==========+==========\n";
		cout << "Archivo" << endl;
		cout << "Mantenimiento" << endl;
		cout << "Reserva" << endl;
		cout << "Venta" << endl;
		cout << "==========+==========+==========+==========+==========\n";
		cout << "Seleccione una opcion: ";
		cin >> menu;

		system("cls");
		cout << "\n==========+==========+==========+==========+==========\n";

		switch (menu) {
		case 1:
			//archivo
			cout << "Acerca de " << endl;
			cout << "Salir" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << "Desarrollador: Joseph Navarro Umana\n";
				cout << "Creador de GTA 7\n";
				cout << "Fan de los easter egg\n";
				break;
			case 2:
				menu=4;
			default:
				break;
			}
			break;
		case 2:
			//mantenimiento
			cout << "Peliculas" << endl;
			cout << "Horas de funciones" << endl;
			cout << "Salas" << endl;
			cin >> menu;

			switch (menu)
			{
			case 1:

				beeMovie.toString();
				adastra.toString();
				bonderlands.toString();
				skibiriToilet.toString();
				break;
			case 2:
				cout << "2:00 pm " << endl;
				cout << "5:00 pm " << endl;
				cout << "7:00 pm " << endl;
				break;
			case 3:
				menu = 4;
				break;
			default:
				break;
			}
			break;
			// resolucion de ambito

		case 3:
			//reservar
			int peliculaSeleccionada,fila,columna,horario;
			cout << "Elija la pelicula: " << endl;
			cout<<beeMovie.getNombre()<<endl;
			cout<<adastra.getNombre()<<endl;
			cout<<bonderlands.getNombre()<<endl;
			cout << skibiriToilet.getNombre() << endl;
			cin >> peliculaSeleccionada;
			
			cout << "La sala para la pelicula es: " << coso[peliculaSeleccionada-1].getNombre() << endl;

			cout << "Seleccione la hora: " << endl;
			cout << "2:00 pm " << endl;
			cout << "5:00 pm " << endl;
			cout << "7:00 pm " << endl;
			cin >> horario;
			cout << "El horario es el numero " << vec[horario-1].getFirtsHorario() << endl;
			
			cout << "Seleccione la butaca " << endl;
			salaDeCine.toString(peliculaSeleccionada-1, horario-1);
			cout << "Escriba la fila: ";
			cin >> fila;
			cout << "Escriba la columna: ";
			cin >> columna;
			salaDeCine.setUbicacion(peliculaSeleccionada-1, fila-1, columna-1, horario-1);
			salaDeCine.toString(peliculaSeleccionada - 1, horario - 1);			

			break;
		case 4:
			//venta
			break;
		default:
			cout << "Error.\n";
			break;
		}
		if (menu != 4) {
			system("pause");
		}
	}

}

