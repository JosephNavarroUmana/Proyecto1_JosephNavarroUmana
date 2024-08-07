#include"Proyecto.h"

void menu() {

	int menu;
	cout << "\t\tMenu" << endl;
	cout << "Archivo" << endl;
	cout << "Mantenimiento" << endl;
	cout << "Reserva" << endl;
	cout << "Venta" << endl;
	cin >> menu;

	switch (menu)
	{
	case 1:
		//archivo
		cout << "Acerca de " << endl;
		cout << "Salir" << endl;
		cin >> menu;
		/*switch (menu)
		{
		case 1:
			cout << "Hola";
			break;
		case 2:
			cout << "Adios";
		default:
			break;
		}*/
		break;
	case 2:
		//mantenimiento
		break;
	case 3:
		//reservar
		break;
	case 4:
		//venta
		break;
	default:
		break;
	}
}

pelicula::pelicula()
{
	nombre = " ";
	year = 0;
	duration = 0;
	country = " ";
	review = 0;
}

pelicula::pelicula(string nombre_, int year_, int duration_, string country_, float review_)
{
	nombre = nombre_;
	year = year_;
	duration = duration_;
	country = country_;
	review = review_;
}

void pelicula::setNombre(string nombre_) {
	nombre = nombre_;
}

pelicula::~pelicula()
{
}

string pelicula::getNombre(){
	return nombre;
}

void pelicula::toString()
{
	cout << "Pelicula: " << nombre << endl;
	cout << "Emision: " << year << endl;
	cout << "Duracion: " << duration << endl;
	cout << "Pais de origen: " << country << endl;
	cout << "Review: " << review << endl;
}

sala::sala()
{
	numero = 0;
	butaca = " ";
	precio = 0;
}

sala::sala(int numero_, string butacas_, int precio_)
{
	numero = numero_;
	butaca = butacas_;
	precio = precio_;
}

int sala::getNumero()
{
	return numero;
}

sala::~sala()
{
}


horarios::horarios()
{
	fecha = " ";
	firtsHorario = " ";
	segundoHorario = " ";
}

horarios::horarios(string fecha_, string firtsHorario_, string segundoHorario_) {
	fecha = fecha_;
	firtsHorario = firtsHorario_;
	segundoHorario = segundoHorario_;
}
string horarios::getFirtsHorario()
{
	return firtsHorario;
}
;

horarios::~horarios()
{
}
///
cinema::cinema()
{
	string peli[4] = { "bts","be","s","g" };

	for (int i = 0; i < 4; i++){
		movie[i].setNombre(peli[i]);
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = 0;
		}
	}
}

cinema::~cinema()
{
}

void cinema::toString()
{
	cout << "  +";
	for (int i = 0; i < 3; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << " |";

		for (int j = 0; j < 3; ++j) {
			if ((i + j) % 2 == 0) {
				cout << "\033[47m"; // Fondo blanco
			}
			else {
				cout << "\033[40m"; // Fondo negro
			}

			if ((i + j) % 2 == 0) {
				cout << "\033[30m"; // Texto negro
			}
			else {
				cout << "\033[37m"; // Texto blanco
			}

			cout << " " << matriz[i][j] << " ";

			cout << "\033[0m" << "|";
		}
		cout << endl;

		cout << "  +";
		for (int k = 0; k < 3; ++k) {
			cout << "---+";
		}
		cout << endl;
	}

	cout << "   ";
	for (char c = 'A'; c < 'A' + 3; ++c) {
		cout << " \t" << c << "  ";
	}
	cout << endl;

}

void cinema::setUbicacion(int a, int b) {
	if (matriz[a][b] == 1) {
		cout << "Ese espacio ya esta ocupado elija otro "<<endl;
	}
	else {
		matriz[a][b] = 1;
	}
}