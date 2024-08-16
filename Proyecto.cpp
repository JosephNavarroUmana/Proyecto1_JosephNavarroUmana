#include"Proyecto.h"

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
cinema::cinema() {
	for (int i = 0; i < NUMERO_SALAS; i++) {
		for (int j = 0; j < NUMERO_HORARIOS; j++) {
			for (int k = 0; k < LIMIT_MATRIZ; k++) {
				for (int l = 0; l < LIMIT_MATRIZ; l++) {
					matriz[i][k][l][j] = 0;  // Ajuste correcto de las dimensiones
				}
			}
		}
	}
}


cinema::~cinema()
{
}

void cinema::toString(int peliculaSeleccionada, int horario) {
	cout << "Sala " << peliculaSeleccionada + 1 << ":\n";
	cout << "  +";
	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout << "---+";
	}
	cout << endl;

	for (int i = 0; i < LIMIT_MATRIZ; ++i) {
		cout << i + 1 << " |";

		for (int j = 0; j < LIMIT_MATRIZ; ++j) {
			if (matriz[peliculaSeleccionada][i][j][horario] == 1) {
				cout << "\033[41m 1 \033[0m|"; // Fondo rojo para butaca ocupada
			}
			else {
				cout << "\033[42m 0 \033[0m|"; // Fondo verde para butaca libre
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