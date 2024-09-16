#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include <cstdlib>  
#include <ctime>  

using namespace std;

cinema::cinema() {
	for (int i = 0; i < NUMERO_SALAS; i++) {
		for (int j = 0; j < NUMERO_HORARIOS; j++) {
			for (int k = 0; k < LIMIT_MATRIZ; k++) {
				for (int l = 0; l < LIMIT_MATRIZ; l++) {
					matriz[i][k][l][j] = rand()% 2;
				}
			}
		}
	}
	codigo = 0;
	peliculaSeleccionada = 0;
	horarioSeleccionnado = 0;
}

cinema::~cinema()
{
}

int cinema::generarCodigo() {
	srand(time(0)); 
	codigo = rand() % 1000000 + 100000; 
	return codigo;
}

void cinema::toString(int peliculaSeleccionada, int horario) {
	cout << "\t\t\t\t\t" << " +";
	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout <<"\t\t\t\t\t" << i + 1 << "|";

		for (int j = 0; j < LIMIT_MATRIZ; ++j) {
			if (matriz[peliculaSeleccionada][i][j][horario] == 1) {
				cout << "\033[41m   \033[0m|"; 
			}
			else {
				cout << "\033[42m   \033[0m|"; 
			}
		}
		cout << endl;

		cout <<"\t\t\t\t\t" << " +";
		for (int k = 0; k < LIMIT_MATRIZ; ++k) {
			cout << "---+";
		}
		cout << endl;
	}

	cout << "\t\t\t\t\t" << "   ";
	for (char c = 'A'; c < 'A' + LIMIT_MATRIZ; ++c) {
		cout << " " << c << "  ";
	}
	cout << endl;
}

bool cinema::setUbicacion(int sala, int fila, int columna, int horario) {
	if (sala < 0 || sala >= NUMERO_SALAS || columna < 0 || columna >= LIMIT_MATRIZ || fila < 0 || fila >= LIMIT_MATRIZ || horario < 0 || horario >= 4) {
		cout << RED << "\t\t\t\tEsta fuera de los limites " << RESET << endl;
		return false;
	}
	else if (matriz[sala][fila][columna][horario] == 1) {
		cout << RED << "\t\t\t\tEse espacio ya esta ocupado elija otro " << RESET << endl;
		return false;
	}
	else {
		matriz[sala][fila][columna][horario] = 1;
		return true;
	}
}

int cinema::identificar(char columna) {
	switch (columna)
	{
	case 'a':case'A':case '1':
		return 0;
	case 'b':case 'B':case '2':
		return 1;
	case 'c':case 'C':case '3':
		return 2;
	case 'd':case 'D':case '4':
		return 3;
	case 'e':case 'E':case '5':
		return 4;
	case 'f':case 'F':case '6':
		return 5;
	default:
		break;
	}

}

void cinema::decoracion() {
	cout <<RESET<<"\t\t\t\t==========+==========+==========+==========+==========\n";
}

void cinema::archivo(int &menu) {
	//archivo
	decoracion();
	cout << YELLOW << "\t\t\t\t\t\t   Acerca de " << endl;
	cout << "\t\t\t\t\t\t     Salir" << RESET << endl;
	decoracion();
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << GREEN << "\t\t\t\t\t   Desarrollador:" << PINK << " Joseph Navarro Umana\n";
		cout << GREEN << "\t\t\t\t\t\tPAGINA:" << BLUE << "CINEMAX" << endl;
		decoracion();
		cout << YELLOW << "\t\t\t\t\t\t   /\\_/\\  " << endl;
		cout << "\t\t\t\t\t\t  ( o.o ) " << endl;
		cout << "\t\t\t\t\t\t   > ^ <  " << endl;
		cout << "\t\t\t\t\t\t  /|_|_|\\ " << endl;
		cout << "\t\t\t\t\t\t ( |___| )" << endl;
		cout << "\t\t\t\t\t\t  /     \\ " << endl;
		cout << "\t\t\t\t\t\t (       )" << endl;
		cout << "\t\t\t\t\t\t  \\__|__/" << endl << RESET;
		decoracion();
		cout << GREEN << "\t\t\t\t\tUn agradecimiento especial a:" << RED << " Alejandro Flores" << RESET << endl;
		cout << GREEN << "\t\t\t\t\tPresione cualquier tecla para volver al menu" << RESET << endl;
		decoracion();
		break;
	case 2:
		menu = 5;
	default:
		break;
	}
	
}

void cinema::mantenimiento(int menu, pelicula vectorPelis[], horarios vectorHorarios[], sala VectorSalas[]) {
	//mantenimiento
	decoracion();
	cout << YELLOW << "\t\t\t\t\t\t    1-Peliculas" << endl;
	cout << "\t\t\t\t\t\t    2-Salas" << endl;
	cout << "\t\t\t\t\t\t    3-Horarios" << endl << RESET;
	decoracion();

	cin >> menu;

	switch (menu)
	{
	case 1:
		decoracion();
		for (int i = 0; i < NUMERO_PELICULAS; i++) {
			vectorPelis[i].toString();
		}
		decoracion();
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
}

void cinema::reserva(pelicula vectorPelis[], horarios vectorHorarios[], sala VectorSalas[], factura &factura1, int salida, int fila, char columna, int tarjeta) {
	//reservar
	int cedula;
	decoracion();
	for (int i = 0; i < NUMERO_PELICULAS; i++) {
		cout << YELLOW << "\t\t\t\t\t" << i + 1 << " - " << BLUE << vectorPelis[i].getNombre() << endl;
	}
	decoracion();
	cin >> peliculaSeleccionada;
	cout << YELLOW << "\t\t\t\tLa " << GREEN << "sala" << YELLOW << " para la pelicula es la numero : " << GREEN << VectorSalas[peliculaSeleccionada - 1].getNumero() << endl;
	decoracion();
	system("pause");
	system("cls");
	decoracion();
	while (salida == 0) {
		
		system("cls");
		decoracion();
		cout << YELLOW << "\t\t\t\tSeleccione un horario: " << RESET << endl;
		decoracion();
		for (int i = 0; i < NUMERO_HORARIOS; i++) {
			cout << GREEN << "\t\t\t\t" << i + 1 << " - " << vectorHorarios[i].getFirtsHorario() << RESET << endl;
		}
		decoracion();
		cin >> horarioSeleccionnado;
		if (vectorHorarios[horarioSeleccionnado - 1].faltan30Minutos() == false) {
			cout << RED << "\t\t\t\tNo puede reservar 30 minutos antes de una funcion " << RESET << endl;
			salida = 0;
		}
		else {
			cout << YELLOW << "\t\t\t\tEl " << GREEN << "horario " << YELLOW << "seleccionado para la funcion es : " << GREEN << vectorHorarios[horarioSeleccionnado - 1].getFirtsHorario() << endl;
			decoracion();
			salida = 1;
		}
		system("pause");
	}
	salida = 0;
	system("cls");
	decoracion();
	cout << YELLOW << "\t\t\t\tSeleccione la butaca " << endl << RESET;
	decoracion();
	toString(peliculaSeleccionada - 1, horarioSeleccionnado - 1);
	decoracion();
	cout << YELLOW << "\t\t\t\tEscriba la fila " << GREEN << "(1,6): ";
	cin >> fila;
	cout << YELLOW << "\t\t\t\tEscriba la columna " << GREEN << "(a,f): "; cin >> columna;

	while (setUbicacion(peliculaSeleccionada - 1, fila - 1, identificar(columna), horarioSeleccionnado - 1) == false) {
		cout << YELLOW << "\t\t\t\tEscriba de nuevo la fila " << GREEN << "(1,6): ";
		cin >> fila;
		cout << YELLOW << "\t\t\t\tEscriba de nuevo la columna " << GREEN << "(a,f): "; cin >> columna;

	}
	system("cls");
	decoracion();
	cout << GREEN << "\t\t\t\tEl asiento fue reservado" << RESET << endl;
	toString(peliculaSeleccionada - 1, horarioSeleccionnado - 1);
	decoracion();
	system("pause");
	system("cls");
	decoracion();
	cout << BLUE << "\t\t\t\tNumero de sala --> " << GREEN << VectorSalas[peliculaSeleccionada - 1].getNumero() << endl;
	cout << BLUE << "\t\t\t\tPelicula seleccionada --> " << GREEN << vectorPelis[peliculaSeleccionada - 1].getNombre() << endl;
	cout << BLUE << "\t\t\t\tHora de la funcion --> " << GREEN << vectorHorarios[horarioSeleccionnado - 1].getFirtsHorario() << endl;
	decoracion();
	do
	{
		cout << YELLOW << "\t\t\t\tDigite su cedula: " << RESET; cin >> cedula;
		if (cedula > 99999999) {
			factura1.setCedula(cedula);
		}
		else {
			cout << RED << "\t\t\t\tDebe digitar una cedula con mas de 9 digitos" << RESET << endl;
		}
	} while (cedula <= 9999999);
	do
	{
		cout << YELLOW << "\t\t\t\tDigite el numero de su tarjeta: " << RESET; cin >> tarjeta; 
		if (tarjeta > 99999999) {
			factura1.setTarjeta(tarjeta);
		}
		else {
			cout << RED << "\t\t\t\tDebe digitar una targeta con mas de 9 digitos" << RESET << endl;
		}
	} while (tarjeta <= 9999999);
	codigo = generarCodigo();
	cout << GREEN << "\t\t\t\tEl codigo de su factura es " << BLUE <<codigo << endl << RESET;
	VectorSalas[peliculaSeleccionada - 1].reducirButacas();
	decoracion();
	toString(peliculaSeleccionada - 1, horarioSeleccionnado - 1);
	decoracion();
}

void cinema::venta(bool validar, factura primeraFactura, sala vectorSalas[], pelicula vectorPeliculas[], horarios vectorHorarios[]) {

	if (validar != true) {
		decoracion();
		primeraFactura.voucher(vectorHorarios, vectorPeliculas, vectorSalas, peliculaSeleccionada - 1, horarioSeleccionnado-1, codigo);
		decoracion();
	}
	else {
		decoracion();
		cout <<RED<< "\t\t\t\t\tRealize una compra primero" <<RESET<<endl;
		decoracion();
	}
}