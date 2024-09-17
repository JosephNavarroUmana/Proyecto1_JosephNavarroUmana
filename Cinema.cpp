#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include <cstdlib>  
#include <ctime>  

using namespace std;

Cinema::Cinema() {
	for (int i = 0; i < NUMBER_ROOMS; i++) {
		for (int j = 0; j < NUMBER_TIME; j++) {
			for (int k = 0; k < LIMIT_MATRIX; k++) {
				for (int l = 0; l < LIMIT_MATRIX; l++) {
					matrix[i][k][l][j] = rand()% 2;
				}
			}
		}
	}
	code = 0;
	movieSelected = 0;
	timeSelected = 0;
}

Cinema::~Cinema()
{
}

int Cinema::generateCode() {
	srand(time(0)); 
	code = rand() % 1000000 + 100000; 
	return code;
}

void Cinema::toString(int movieSelected, int scheduleSelected) {
	cout << "\t\t\t\t\t" << " +";
	for (int i = 0; i < LIMIT_MATRIX; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < LIMIT_MATRIX; ++i) {
		cout <<"\t\t\t\t\t" << i + 1 << "|";

		for (int j = 0; j < LIMIT_MATRIX; ++j) {
			if (matrix[movieSelected][i][j][scheduleSelected] == 1) {
				cout << "\033[41m   \033[0m|"; 
			}
			else {
				cout << "\033[42m   \033[0m|"; 
			}
		}
		cout << endl;

		cout <<"\t\t\t\t\t" << " +";
		for (int k = 0; k < LIMIT_MATRIX; ++k) {
			cout << "---+";
		}
		cout << endl;
	}

	cout << "\t\t\t\t\t" << "  ";
	for (char c = 'A'; c < 'A' + LIMIT_MATRIX; ++c) {
		cout << " " << c << "  ";
	}
	cout << endl;
}

bool Cinema::setLocation(int movieSelected, int row, int column, int scheduleSelected) {
	if (movieSelected < 0 || movieSelected >= NUMBER_ROOMS || column < 0 || column >= LIMIT_MATRIX || row < 0 || row >= LIMIT_MATRIX || scheduleSelected < 0 || scheduleSelected >= 4) {
		cout << RED << "\t\t\t\tEsta fuera de los limites " << RESET << endl;
		return false;
	}
	else if (matrix[movieSelected][row][column][scheduleSelected] == 1) {
		cout << RED << "\t\t\t\tEse espacio ya esta ocupado elija otro " << RESET << endl;
		return false;
	}
	else {
		matrix[movieSelected][row][column][scheduleSelected] = 1;
		return true;
	}
}

int Cinema::identifyLetter(char column) {
	switch (column)
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

void Cinema::decorate() {
	cout <<RESET<<"\t\t\t\t==========+==========+==========+==========+==========\n";
}

void Cinema::file(int &menu) {
	//archivo
	decorate();
	cout << YELLOW << "\t\t\t\t\t\t   Acerca de " << endl;
	cout << "\t\t\t\t\t\t     Salir" << RESET << endl;
	decorate();
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << GREEN << "\t\t\t\t\t   Desarrollador:" << PINK << " Joseph Navarro Umana\n";
		cout << GREEN << "\t\t\t\t\t\tPAGINA:" << BLUE << "CINEMAX" << endl;
		decorate();
		cout << YELLOW << "\t\t\t\t\t\t   /\\_/\\  " << endl;
		cout << "\t\t\t\t\t\t  ( o.o ) " << endl;
		cout << "\t\t\t\t\t\t   > ^ <  " << endl;
		cout << "\t\t\t\t\t\t  /|_|_|\\ " << endl;
		cout << "\t\t\t\t\t\t ( |___| )" << endl;
		cout << "\t\t\t\t\t\t  /     \\ " << endl;
		cout << "\t\t\t\t\t\t (       )" << endl;
		cout << "\t\t\t\t\t\t  \\__|__/" << endl << RESET;
		decorate();
		cout << GREEN << "\t\t\t\t\tUn agradecimiento especial a:" << RED << " Alejandro Flores" << RESET << endl;
		cout << GREEN << "\t\t\t\t\tPresione cualquier tecla para volver al menu" << RESET << endl;
		decorate();
		break;
	case 2:
		menu = 5;
	default:
		break;
	}
	
}

void Cinema::maintenance(int menu, Movie vectorMovie[], Schedules vectorSchedule[], Rooms vectorRooms[]) {
	//mantenimiento
	decorate();
	cout << YELLOW << "\t\t\t\t\t\t    1-Peliculas" << endl;
	cout << "\t\t\t\t\t\t    2-Salas" << endl;
	cout << "\t\t\t\t\t\t    3-Horarios" << endl << RESET;
	decorate();

	cin >> menu;

	switch (menu)
	{
	case 1:
		decorate();
		for (int i = 0; i < NUMBER_MOVIE; i++) {
			vectorMovie[i].toString();
		}
		decorate();
		break;
	case 2:
		for (int i = 0; i < NUMBER_ROOMS; i++) {
			vectorRooms[i].toString();
		}
		break;
	case 3:
		for (int i = 0; i < NUMBER_TIME; i++) {
			vectorSchedule[i].toString();
		}
		break;
	default:
		break;
	}
}

void Cinema::reservation(Movie vectorMovie[], Schedules vectorSchedule[], Rooms vectorRooms[], Invoice& firstVoucher) {
	int cedula, tarjeta, fila;
	char columna;
	bool isValid = false;
	int movieSelected, timeSelected;

	decorate();
	for (int i = 0; i < NUMBER_MOVIE; i++) {
		cout << YELLOW << "\t\t\t\t\t" << i + 1 << " - " << BLUE << vectorMovie[i].getName() << endl;
	}
	decorate();

	cin >> movieSelected;
	cout << YELLOW << "\t\t\t\tLa " << GREEN << "sala" << YELLOW << " para la pelicula es la numero: " << GREEN << vectorRooms[movieSelected - 1].getNumber() << endl;
	decorate();
	system("pause");
	system("cls");
	decorate();

	while (!isValid) {
		system("cls");
		decorate();
		cout << YELLOW << "\t\t\t\tSeleccione un horario: " << RESET << endl;
		decorate();
		for (int i = 0; i < NUMBER_TIME; i++) {
			cout << GREEN << "\t\t\t\t" << i + 1 << " - " << vectorSchedule[i].getFirstTime() << RESET << endl;
		}
		decorate();
		cin >> timeSelected;
		if (vectorSchedule[timeSelected - 1].isLessThan30MinutesRemaining()) {
			cout << YELLOW << "\t\t\t\tEl " << GREEN << "horario " << YELLOW << "seleccionado para la funcion es: " << GREEN << vectorSchedule[timeSelected - 1].getFirstTime() << endl;
			decorate();
			isValid = true;
		}
		else {
			cout << RED << "\t\t\t\tNo puede reservar 30 minutos antes de una funcion" << RESET << endl;
		}
		system("pause");
	}

	isValid = false;
	system("cls");
	decorate();
	cout << YELLOW << "\t\t\t\tSeleccione la butaca" << endl << RESET;
	decorate();
	toString(movieSelected - 1, timeSelected - 1);
	decorate();

	while (!isValid) {
		cout << YELLOW << "\t\t\t\tEscriba la fila " << GREEN << "(1,6): ";
		cin >> fila;
		cout << YELLOW << "\t\t\t\tEscriba la columna " << GREEN << "(a,f): ";
		cin >> columna;
		if (setLocation(movieSelected - 1, fila - 1, identifyLetter(columna), timeSelected - 1)) {
			isValid = true;
		}
		else {
			cout << RED << "\t\t\t\tUbicacion no valida, intente de nuevo." << RESET << endl;
		}
	}

	system("cls");
	decorate();
	cout << GREEN << "\t\t\t\tEl asiento fue reservado" << RESET << endl;
	toString(movieSelected - 1, timeSelected - 1);
	decorate();
	system("pause");
	system("cls");
	decorate();
	cout << BLUE << "\t\t\t\tNumero de sala --> " << GREEN << vectorRooms[movieSelected - 1].getNumber() << endl;
	cout << BLUE << "\t\t\t\tPelicula seleccionada --> " << GREEN << vectorMovie[movieSelected - 1].getName() << endl;
	cout << BLUE << "\t\t\t\tHora de la funcion --> " << GREEN << vectorSchedule[timeSelected - 1].getFirstTime() << endl;
	decorate();

	do {
		cout << YELLOW << "\t\t\t\tDigite su cedula: " << RESET;
		cin >> cedula;
		if (cedula > 99999999) {
			firstVoucher.setID(cedula);
		}
		else {
			cout << RED << "\t\t\t\tDebe digitar una cedula con mas de 9 digitos" << RESET << endl;
		}
	} while (cedula <= 99999999);

	do {
		cout << YELLOW << "\t\t\t\tDigite el numero de su tarjeta: " << RESET;
		cin >> tarjeta;
		if (tarjeta > 99999999) {
			firstVoucher.setCard(tarjeta);
		}
		else {
			cout << RED << "\t\t\t\tDebe digitar una tarjeta con mas de 9 digitos" << RESET << endl;
		}
	} while (tarjeta <= 99999999);

	code = generateCode();
	cout << GREEN << "\t\t\t\tEl codigo de su factura es " << BLUE << code << endl << RESET;
	vectorRooms[movieSelected - 1].reduceSeats();
	decorate();
	toString(movieSelected - 1, timeSelected - 1);
	decorate();
}

void Cinema::sale(bool validate, Invoice firstVoucher, Rooms vectorRooms[], Movie vectorMovies[], Schedules vectorSchedule[]) {

	if (validate != true) {
		decorate();
		firstVoucher.voucher(vectorSchedule, vectorMovies, vectorRooms, movieSelected - 1, timeSelected-1, code);
		decorate();
	}
	else {
		decorate();
		cout <<RED<< "\t\t\t\t\tRealize una compra primero" <<RESET<<endl;
		decorate();
	}
}