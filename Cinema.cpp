#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include <cstdlib>  
#include <ctime>  

using namespace std;

Cinema::Cinema() {
	srand(time(NULL));
	for (int i = 0; i < NUMBER_ROOMS; i++) {
		for (int j = 0; j < NUMBER_TIME; j++) {
			for (int k = 0; k < LIMIT_MATRIX; k++) {
				for (int l = 0; l < LIMIT_MATRIX; l++) {
					matrix[i][k][l][j] = rand()% 3;
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
	
	code = rand() % 1000000 + 100000; 
	return code;
}

bool Cinema::setLocation(int state, int row, int column) {
	if (movieSelected < 0 || movieSelected >= NUMBER_ROOMS || column < 0 || column >= LIMIT_MATRIX || row < 0 || row >= LIMIT_MATRIX || timeSelected < 0 || timeSelected >= 4) {
		cout << RED << "\t\t\t\tEsta fuera de los limites " << RESET << endl;
		return false;
	}
	else if (matrix[movieSelected][row][column][timeSelected] == 1) {
		cout << RED << "\t\t\t\tEse espacio ya esta ocupado elija otro " << RESET << endl;
		return false;
	}
	else if(state == 1){
		matrix[movieSelected][row][column][timeSelected] = 1;
		return true;
	}
	else {
		matrix[movieSelected][row][column][timeSelected] = 2;
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
///
void Cinema::saveState(int estado) {
	int entradas;
	decorate();
	cout <<BLUE<<"\t\t\t\tCantidad de entradas: "<<RESET<<endl;
	decorate();
	cin >> entradas;
	for (int i = 0; i < entradas; i++) {
		system("cls");
		toString();

		int auxF;
		char auxC;
		bool seatSelected = false; 

		while (!seatSelected) {
			cout << YELLOW << "\t\t\t\tEscriba la fila " << GREEN << "(1,6): ";
			cin >> auxF;
			cout << YELLOW << "\t\t\t\tEscriba la columna " << GREEN << "(a,f): ";
			cin >> auxC;

			int row = auxF - 1; 
			int column = identifyLetter(auxC);

			if (setLocation(estado, row, column)) {
				seatSelected = true; 
				cout << GREEN << "\t\t\t\tEl asiento numero " << i + 1 << " fue reservado con exito" << RESET << endl;
			}
			else {
				cout << RED << "\t\t\t\tPor favor seleccione otro asiento." << RESET << endl;
			}
		}

		toString();
		system("pause");
		decorate();
	}
}

//
void Cinema::changeState(int movieSelected, int row, char column, int scheduleSelected) {
	int columnaIndex = identifyLetter(column);
	matrix[movieSelected][row][columnaIndex][scheduleSelected] = 1;

}

void Cinema::reservation(Movie vectorMovies[], Schedules vectorSchedule[], Rooms vectorRooms[], Invoice& firstVoucher) {
	int movieSelected, timeSelected, fila, columna;
	int estado, cedula, tarjeta;
	bool isValid = false;

	code = generateCode();
	decorate();
	cout << BLUE << "\t\t\t\tSeleccione una pelicula: " <<RESET<<endl;
	decorate(); 
	for (int i = 0; i < NUMBER_MOVIE; i++) {
		cout << YELLOW << "\t\t\t\t\t" << i + 1 << " - " << BLUE << vectorMovies[i].getName() << endl;
	}
	decorate();
	cin >> movieSelected;
	if (movieSelected < 1 || movieSelected > NUMBER_MOVIE) {
		cout << RED << "Selección invalida. Por favor elija una pelicula correcta." << RESET << endl;
		return;
	}

	cout << YELLOW << "\t\t\t\tLa sala para la pelicula es la numero: " << GREEN << vectorRooms[movieSelected - 1].getNumber() << endl;
	decorate();
	system("pause");
	system("cls");

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

		if (timeSelected < 1 || timeSelected > NUMBER_TIME) {
			cout << RED << "\t\t\t\tSeleccion invalida. Por favor elija un horario correcto." << RESET << endl;
			continue;
		}

		if (vectorSchedule[timeSelected - 1].isLessThan30MinutesRemaining()) {
			cout << YELLOW << "\t\t\t\tEl horario seleccionado para la funcion es: " << GREEN << vectorSchedule[timeSelected - 1].getFirstTime() << endl;
			decorate();
			isValid = true;
		}
		else {
			cout << RED << "\t\t\t\tNo puede reservar 30 minutos antes de una funcion" << RESET << endl;
		}
		system("pause");
	}

	int action;
	system("cls");
	decorate();
	cout << "\t\t\t\tQue desea hacer? " << endl;
	decorate();
	cout <<YELLOW<<"\t\t\t\t1 - Comprar" << endl;
	cout <<"\t\t\t\t2 - Reservar" <<RESET<<endl;
	decorate();
	cin >> action;

	if (action == 1) {
		decorate();
		cout <<YELLOW<<"\t\t\t\tTiene una reserva previa?" << endl;
		cout << "\t\t\t\t1 - Si" << endl;
		cout << "\t\t\t\t2 - No" <<RESET<<endl;
		decorate();
		cin >> action;
		if (action == 1) {
			int inputCode;
			decorate();
			cout <<BLUE<<"\t\t\t\tDigite el codigo de la factura: " <<RESET;
			cin >> inputCode; cout << endl;
			decorate();
			if (inputCode == code) {
				cout << "\t\t\t\tSe canjeó su asiento" << endl;
				//changeState(movieSelected - 1, fila, columna, timeSelected - 1);
			}
			else {
				cout << RED << "\t\t\t\tCodigo incorrecto" << RESET << endl;
			}
		}
		else {
			estado = 1;
			saveState(estado);
		}
	}
	else if (action == 2) {
		estado = 1;
		saveState(estado);
	}
	else {
		cout << RED << "\t\t\t\tOpcion no valida." << RESET << endl;
		return;
	}

	system("cls");
	decorate();
	cout << BLUE << "\t\t\t\tNúmero de sala --> " << GREEN << vectorRooms[movieSelected - 1].getNumber() << endl;
	cout << BLUE << "\t\t\t\tPelícula seleccionada --> " << GREEN << vectorMovies[movieSelected - 1].getName() << endl;
	cout << BLUE << "\t\t\t\tHora de la función --> " << GREEN << vectorSchedule[timeSelected - 1].getFirstTime() << endl;
	decorate();

	do {
		cout << YELLOW << "\t\t\t\tDigite su cedula: " << RESET;
		cin >> cedula;
		if (cedula <= 99999999) {
			cout << RED << "Debe digitar una cedula con mas de 9 digitos" << RESET << endl;
		}
		else {
			firstVoucher.setID(cedula);
		}
	} while (cedula <= 99999999);

	do {
		cout << YELLOW << "\t\t\t\tDigite el numero de su tarjeta: " << RESET;
		cin >> tarjeta;
		if (tarjeta <= 99999999) {
			cout << RED << "Debe digitar una tarjeta con mas de 9 digitos" << RESET << endl;
		}
		else {
			firstVoucher.setCard(tarjeta);
		}
	} while (tarjeta <= 99999999);

	cout << GREEN << "\t\t\t\tEl codigo de su factura es " << BLUE << code << endl << RESET;
	vectorRooms[movieSelected - 1].reduceSeats();
	decorate();
	toString();
	decorate();
}

void Cinema::sale(bool validate, Invoice firstVoucher, Rooms vectorRooms[], Movie vectorMovies[], Schedules vectorSchedule[]) {

	if (validate != true) {
		decorate();
		firstVoucher.voucher(vectorSchedule, vectorMovies, vectorRooms, movieSelected, timeSelected, code);
		decorate();
	}
	else {
		decorate();
		cout <<RED<< "\t\t\t\t\tRealize una compra primero" <<RESET<<endl;
		decorate();
	}
}

void Cinema::toString() {
	cout << "\t\t\t\t\t" << " +";
	for (int i = 0; i < LIMIT_MATRIX; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < LIMIT_MATRIX; ++i) {
		cout << "\t\t\t\t\t" << i + 1 << "|";
		for (int j = 0; j < LIMIT_MATRIX; ++j) {
			if (matrix[movieSelected][i][j][timeSelected] == 1) {
				cout << "\033[41m   \033[0m|"; // Ocupado
			}
			else if (matrix[movieSelected][i][j][timeSelected] == 2) {
				cout << "\033[43m   \033[0m|"; // Reservado
			}
			else {
				cout << "\033[42m   \033[0m|"; // Libre
			}

		}
		cout << endl;

		cout << "\t\t\t\t\t" << " +";
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
