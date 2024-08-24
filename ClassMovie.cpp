#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

pelicula::pelicula()
{
	nombre = " ";
	year = 0;
	duration = 0;
	country = " ";
	review = " ";
}

pelicula::pelicula(string nombre_, int year_, int duration_, string country_, string review_)
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

string pelicula::getNombre() {
	return nombre;
}

void pelicula::toString()
{
	cout <<YELLOW<< "Pelicula: " <<GREEN<< nombre <<RESET<< endl;
	cout <<YELLOW<< "Emision: " <<GREEN<< year <<RESET<< endl;
	cout <<YELLOW<< "Duracion: " <<GREEN<< duration <<RESET<< endl;
	cout <<YELLOW<< "Pais de origen: " <<GREEN<< country <<RESET<< endl;
	cout <<YELLOW<< "Review: " <<GREEN<< review << endl<<RESET;
	cout << "==========+==========+==========+==========+==========\n";

}
