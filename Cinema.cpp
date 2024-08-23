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
		cout << "Ese espacio ya esta ocupado elija otro "<<endl;
	}
	else {
		matriz[sala][fila][columna][horario] = 1;
	}
}

factura::factura()
{

	cedula = 0;
	tarjeta = 0;
}

factura::~factura()
{
}

void factura::setCedula(int cedula_)
{
	cedula = cedula_;
}

void factura::setTarjeta(int tarjeta_)
{
	tarjeta = tarjeta_;
}

int factura::getCedula()
{
	return cedula;
}

int factura::getTarjeta()
{
	return tarjeta;
}

void factura::voucher(sala vectorSalas[], int salaSeleccionada, usuario persona1)
{
	int total = 0, codigo;
	total+=vectorSalas[salaSeleccionada].getPrecio();
	if (total < 0) {
		cout << "Realize primero una compra " << endl;
	}
	else {
		cout << "Digite el codigo dado en su compra "; cin >> codigo;
		if(codigo == persona1.generarCodigo()){
		cout << "Cedula --> " << persona1.getCedula() << endl;
		cout << "El precio a pagar por todas las entradas es de: " << total << endl;
		}
		else {
			cout << "El codigo es incorrecto" << endl;
		}
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
	int peliculaSeleccionada=0, menu = 0, cedula = 0, tarjeta=0,codigo=0;

	while (menu != 5) {

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
				menu = 5;
			default:
				break;
			}
			break;
		case 2:
			//mantenimiento
			cout << "1-Peliculas" << endl;
			cout << "2-Salas" << endl;
			cout << "3-Horarios" << endl;
			cin >> menu;

			switch (menu)
			{
			case 1:

				for (int i = 0; i < NUMERO_PELICULAS; i++){
					vectorPelis[i].toString();
					cout << endl;
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
					cout << endl;
				}
				break;
			default:
				break;
			}
			break;

		case 3:
			//reservar
			int fila, columna, horario;
			for (int i = 0; i < NUMERO_PELICULAS; i++) {
				cout << vectorPelis[i].getNombre() << endl;
			}
			cin >> peliculaSeleccionada;

			cout << "La sala para la pelicula es la numero: " << VectorSalas[peliculaSeleccionada - 1].getNumero() << endl;
			cout << "\n==========+==========+==========+==========+==========\n";
			cout << "Seleccione la hora: " << endl;
			cout << "2:00 pm " << endl;
			cout << "5:00 pm " << endl;
			cout << "7:00 pm " << endl;
			cin >> horario;
			cout << "El horario seleccionado para la funcion es: " << vectorHorarios[horario - 1].getFirtsHorario() << endl;
			cout << "Seleccione la butaca " << endl;
			toString(peliculaSeleccionada - 1, horario - 1);
			cout << "Escriba la fila: ";
			cin >> fila;
			cout << "Escriba la columna: ";cin >> columna;
			
			setUbicacion(peliculaSeleccionada - 1, fila - 1, columna - 1, horario - 1);
			system("cls");
			cout << "Numero de sala --> " << peliculaSeleccionada << endl;
			cout << "Pelicula seleccionada --> " << vectorPelis[peliculaSeleccionada - 1].getNombre() << endl;
			cout << "Hora de la funcion --> " << vectorHorarios[horario-1].getFirtsHorario() << endl;
			cout << "Digite su cedula: "; cin >> cedula; cliente.setCedula(cedula);
			cout << "Digite el numero de su tarjeta: "; cin >> cedula; cliente.setTarjeta(tarjeta);
			cout << "El codigo de su factura es " << cliente.generarCodigo() << endl;

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