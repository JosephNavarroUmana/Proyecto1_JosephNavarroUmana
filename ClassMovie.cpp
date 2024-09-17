#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

Movie::Movie()
{
	name = " ";
	year = 0;
	duration = 0;
	country = " ";
	review = " ";
}

Movie::Movie(string name_, int year_, int duration_, string country_, string review_)
{
	name = name_;
	year = year_;
	duration = duration_;
	country = country_;
	review = review_;
}

void Movie::setName(string name_) {
	name = name_;
}

Movie::~Movie()
{
}

string Movie::getName() {
	return name;
}

void Movie::toString()
{
	cout <<YELLOW<< "Pelicula: " <<GREEN<< name <<RESET<< endl;
	cout <<YELLOW<< "Emision: " <<GREEN<< year <<RESET<< endl;
	cout <<YELLOW<< "Duracion: " <<GREEN<< duration <<RESET<< endl;
	cout <<YELLOW<< "Pais de origen: " <<GREEN<< country <<RESET<< endl;
	cout <<YELLOW<< "Review: " <<GREEN<< review << endl<<RESET;
	cout << "==========+==========+==========+==========+==========\n";

}
