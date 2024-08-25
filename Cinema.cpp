#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"usuario.h"

using namespace std;

cinema::cinema() {
	for (int i = 0; i < NUMERO_SALAS; i++) {
		for (int j = 0; j < NUMERO_HORARIOS; j++) {
			for (int k = 0; k < LIMIT_MATRIZ; k++) {
				for (int l = 0; l < LIMIT_MATRIZ; l++) {
					matriz[i][k][l][j] = 0;
				}
			}
		}
	}
}

cinema::~cinema()
{
}

void cinema::toString(int peliculaSeleccionada, int horario) {
	cout << "  +";
	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout << i + 1 << " |";

		for (int j = 0; j < LIMIT_MATRIZ; ++j) {
			if (matriz[peliculaSeleccionada][i][j][horario] == 1) {
				cout << "\033[41m   \033[0m|"; // Fondo rojo para butaca ocupada
			}
			else {
				cout << "\033[42m   \033[0m|"; // Fondo verde para butaca libre
			}
		}
		cout << endl;

		cout << "  +";
		for (int k = 0; k < LIMIT_MATRIZ; ++k) {
			cout << "---+";
		}
		cout << endl;
	}

	cout << "   ";
	for (char c = 'A'; c < 'A' + LIMIT_MATRIZ; ++c) {
		cout << " " << c << "  ";
	}
	cout << endl;
}

void cinema::setUbicacion(int sala, int fila, int columna, int horario) {
	if (matriz[sala][fila][columna][horario] == 1) {
		cout <<RED<< "Ese espacio ya esta ocupado elija otro "<<RESET<<endl;
	}
	else if (sala > NUMERO_SALAS ||  columna> LIMIT_MATRIZ || fila >LIMIT_MATRIZ || horario > 3) {
		cout <<RED<< "Esta fuera de los limites " <<RESET<< endl;
	}
	else {
		cout <<GREEN<< "El asiento fue reservado" <<RESET<<endl;
		matriz[sala][fila][columna][horario] = 1;
	}
}

int identificar(char columna) {
	switch (columna)
	{
	case 'a':case'A':
		return 1;
	case 'b':case 'B':
		return 2;
	case 'c':case 'C':
		return 3;
	case 'd':case 'D':
		return 4;
	case 'e':case 'E':
		return 5;
	case 'f':case 'F':
		return 6;
	default:
		break;
	}

}

void cinema::menu(pelicula vectorPelis[], horarios vectorHorarios[], sala VectorSalas[], factura factura1, usuario cliente)
{
	int peliculaSeleccionada=0, menu = 0, cedula = 0, tarjeta=0,codigo=0,fila=0, columna=0, horario=0;

	cout <<RED<< "\t\tPara una mejor experiencia en la pagina le recomendamos agrandar la ventana " <<RESET<< endl;
	system("pause");
	while (menu != 5) {

		system("cls");
		cout << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
		cout <<RED<< "\t\t\t\t\t\tMENU DE OPCIONES\n"<<RESET;
		cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
		cout <<YELLOW<< "\t\t\t\t\t\t  Archivo" << endl;
		cout << "\t\t\t\t\t\tMantenimiento" << endl;
		cout << "\t\t\t\t\t\t  Reserva" << endl;
		cout << "\t\t\t\t\t\t   Venta" <<RESET<<endl;
		cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
		cout << "\t\t\t\tSeleccione una opcion: ";
		cin >> menu;

		system("cls");

		switch (menu) {
		case 1:
			//archivo
			cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
			cout <<YELLOW<< "\t\t\t\t\t\t   Acerca de " << endl;
			cout << "\t\t\t\t\t\t     Salir" <<RESET<< endl;
			cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout <<GREEN<< "\t\t\t\t\t   Desarrollador:"<<PINK<<" Joseph Navarro Umana\n";
				cout <<GREEN<< "\t\t\t\t\t\tPAGINA:"<<BLUE<<"CINEMAX" << endl;
				cout <<YELLOW<< "\t\t\t\t\t\t   /\\_/\\  " << endl;
				cout << "\t\t\t\t\t\t  ( o.o ) " << endl;
				cout << "\t\t\t\t\t\t   > ^ <  " << endl;
				cout << "\t\t\t\t\t\t  /|_|_|\\ " << endl;
				cout << "\t\t\t\t\t\t ( |___| )" << endl;
				cout << "\t\t\t\t\t\t  /     \\ " << endl;
				cout << "\t\t\t\t\t\t (       )" << endl;
				cout << "\t\t\t\t\t\t  \\__|__/" << endl<<RESET;
				cout <<GREEN<< "\t\t\t\t\tUn agradecimiento especial a:"<<RED<<" Alejandro Flores" <<RESET<< endl;
				break;
			case 2:
				menu = 5;
			default:
				break;
			}
			break;
		case 2:
			//mantenimiento
			cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
			cout <<YELLOW<< "\t\t\t\t\t\t    1-Peliculas" << endl;
			cout << "\t\t\t\t\t\t    2-Salas" << endl;
			cout << "\t\t\t\t\t\t    3-Horarios" << endl<<RESET;
			cout << "\t\t\t\t==========+==========+==========+==========+==========\n";

			cin >> menu;

			switch (menu)
			{
			case 1:

				for (int i = 0; i < NUMERO_PELICULAS; i++){
					vectorPelis[i].toString();
				}
				break;
			case 2:
				for (int i = 0; i < NUMERO_SALAS; i++) {
					VectorSalas[i].toString();
				}
				break;
			case 3:
				for (int i = 0; i < NUMERO_HORARIOS; i++) {
					vectorHorarios[i].toString();
				}
				break;
			default:
				break;
			}
			break;

		case 3:
			//reservar
			for (int i = 0; i < NUMERO_PELICULAS; i++) {
				cout <<YELLOW<<"\t1 - " <<vectorPelis[i].getNombre() << endl;
			}
			cin >> peliculaSeleccionada;
			cout << "La "<<GREEN<<"sala" <<YELLOW<< " para la pelicula es la numero : " << GREEN << VectorSalas[peliculaSeleccionada - 1].getNumero() << endl;
			cout <<RESET<< "\n==========+==========+==========+==========+==========\n";
			system("pause");
			system("cls");
			cout <<YELLOW<<"Seleccione la hora: " << endl;
			cout << "1 - 2:00 pm " << endl;
			cout << "2 - 5:00 pm " << endl;
			cout << "3 - 7:00 pm " << endl<<RESET;
			cin >> horario;
			cout <<YELLOW<< "El "<<GREEN<<"horario "<<YELLOW<<"seleccionado para la funcion es : " <<GREEN<< vectorHorarios[horario - 1].getFirtsHorario() << endl;
			system("pause");
			system("cls");
			cout <<YELLOW<<"Seleccione la butaca " << endl<<RESET;
			toString(peliculaSeleccionada - 1, horario - 1);
			cout << YELLOW<<"Escriba la fila "<<GREEN<<"(1,6): ";
			cin >> fila;
			cout <<YELLOW<<"Escriba la columna "<<GREEN<<"(a,f): ";cin >> columna;
			setUbicacion(peliculaSeleccionada - 1, fila - 1, columna - 1, horario - 1);
			system("cls");
			cout <<BLUE<< "Numero de sala --> " <<GREEN<< peliculaSeleccionada << endl;
			cout <<BLUE<< "Pelicula seleccionada --> " <<GREEN<< vectorPelis[peliculaSeleccionada - 1].getNombre() << endl;
			cout <<BLUE<< "Hora de la funcion --> " <<GREEN<< vectorHorarios[horario-1].getFirtsHorario() << endl;
			cout << "Digite su cedula: "; cin >> cedula; cliente.setCedula(cedula);
			cout << "Digite el numero de su tarjeta: "; cin >> cedula; cliente.setTarjeta(tarjeta);
			cout << "El codigo de su factura es " <<BLUE<< cliente.generarCodigo() << endl<<RESET;
			VectorSalas[peliculaSeleccionada-1].reducirButacas();
			toString(peliculaSeleccionada - 1, horario - 1);

			break;
		case 4:
			//venta
			factura1.voucher(VectorSalas, peliculaSeleccionada-1, cliente);
			break;
		default:
			cout << "Error.\n";
			break;
		}
		if (menu != 5) {
			system("pause");
		}
	}
}