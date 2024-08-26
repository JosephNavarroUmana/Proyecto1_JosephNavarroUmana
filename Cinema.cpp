#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

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
	codigo = 0;
}

cinema::~cinema()
{
}

int cinema::getCodigo()
{
	return codigo;
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

int cinema::identificar(char columna) {
	switch (columna)
	{
	case 'a':case'A':
		return 0;
	case 'b':case 'B':
		return 1;
	case 'c':case 'C':
		return 2;
	case 'd':case 'D':
		return 3;
	case 'e':case 'E':
		return 4;
	case 'f':case 'F':
		return 5;
	default:
		break;
	}

}

int cinema::generarCodigo() {
	srand(time(NULL));
	if (codigo == 0) {
		codigo = rand() % 100 + 1;
	}
	return codigo;
}

void cinema::menu(pelicula vectorPelis[], horarios vectorHorarios[], sala VectorSalas[], factura factura1)
{
	int peliculaSeleccionada=0, menu = 0, cedula = 0, tarjeta=0,codigo=0,fila=0, horario=0;
	char columna ;
	cout <<RED<< "\t\tPara una mejor experiencia en la pagina le recomendamos agrandar la ventana " <<RESET<< endl;
	system("pause");
	while (menu != 5) {

		system("cls");
		cout << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
		cout <<RED<< "\t\t\t\t\t\tMENU DE OPCIONES\n"<<RESET;
		cout << "\t\t\t\t==========+==========+==========+==========+==========\n";
		cout <<YELLOW<< "\t\t\t\t\t\t  1-Archivo" << endl;
		cout << "\t\t\t\t\t\t2-Mantenimiento" << endl;
		cout << "\t\t\t\t\t\t  3-Reservar" << endl;
		cout << "\t\t\t\t\t\t   4-Venta" <<RESET<<endl;
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
			cout << RESET << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
			for (int i = 0; i < NUMERO_PELICULAS; i++) {
				cout <<YELLOW<<"\t\t\t\t\t" << i + 1 << " - " <<BLUE<<vectorPelis[i].getNombre() << endl;
			}
			cout <<RESET<<"\t\t\t\t==========+==========+==========+==========+==========\n";
			cin >> peliculaSeleccionada;
			cout <<YELLOW<< "\t\t\t\tLa "<<GREEN<<"sala" <<YELLOW<< " para la pelicula es la numero : " << GREEN << VectorSalas[peliculaSeleccionada - 1].getNumero() << endl;
			cout <<RESET<< "\n\t\t\t\t==========+==========+==========+==========+==========\n";
			system("pause");
			system("cls");
			cout << RESET << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
			cout <<YELLOW<<"\t\t\t\tSeleccione la hora: " << endl;
			cout << "\t\t\t\t1 - 2:00 pm " << endl;
			cout << "\t\t\t\t2 - 5:00 pm " << endl;
			cout << "\t\t\t\t3 - 7:00 pm " << endl<<RESET;
			cout << RESET << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
			cin >> horario;
			cout <<YELLOW<< "\t\t\t\tEl "<<GREEN<<"horario "<<YELLOW<<"seleccionado para la funcion es : " <<GREEN<< vectorHorarios[horario - 1].getFirtsHorario() << endl;
			cout << RESET << "\n\t\t\t\t==========+==========+==========+==========+==========\n";
			system("pause");
			system("cls");
			cout <<YELLOW<<"\t\t\t\tSeleccione la butaca " << endl<<RESET;
			toString(peliculaSeleccionada - 1, horario - 1);
			cout << YELLOW<<"\t\t\t\tEscriba la fila "<<GREEN<<"(1,6): ";
			cin >> fila;
			cout <<YELLOW<<"Escriba la columna "<<GREEN<<"(a,f): ";cin >> columna;
			setUbicacion(peliculaSeleccionada - 1, fila - 1, identificar(columna), horario - 1);
			system("cls");
			cout <<BLUE<< "\t\t\t\tNumero de sala --> " <<GREEN<< VectorSalas[peliculaSeleccionada].getNumero() << endl;
			cout <<BLUE<< "\t\t\t\tPelicula seleccionada --> " <<GREEN<< vectorPelis[peliculaSeleccionada - 1].getNombre() << endl;
			cout <<BLUE<< "\t\t\t\tHora de la funcion --> " <<GREEN<< vectorHorarios[horario-1].getFirtsHorario() << endl;		
			do {
				cout <<YELLOW<< "Digite su cedula: "<<RESET; cin >> cedula; factura1.setCedula(cedula);
			} while (cedula <= 99999999);
			do
			{
				cout <<YELLOW<< "Digite el numero de su tarjeta: "<<RESET; cin >> tarjeta; factura1.setTarjeta(tarjeta);
			} while (tarjeta <= 9999999);
			cout <<GREEN<< "El codigo de su factura es " <<BLUE<< generarCodigo() << endl<<RESET;
			VectorSalas[peliculaSeleccionada-1].reducirButacas();
			toString(peliculaSeleccionada - 1, horario - 1);

			break;
		case 4:
			//venta
			factura1.voucher(VectorSalas, peliculaSeleccionada-1, generarCodigo());
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