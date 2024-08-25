#include "usuario.h"
#include <stdlib.h>
#include"Cinema.h"
#include<iostream>

using namespace std;
usuario::usuario()
{
	cedula = 0;
	tarjeta = 0;
	codigo = 0;
}

usuario::~usuario()
{
}

int usuario::generarCodigo() {
	if (codigo == 0) { 
		codigo = rand() % 100 + 1; 
	}
	return codigo;
}

void usuario::setCedula(int id)
{
	if (id >= 9) {
		cedula = id;
	}
	else {
		cout << RED << "Debe digitar una cedula valida (9 numeros)" << RESET << endl;
	}
}

int usuario::getCedula()
{
	return cedula;
}

void usuario::setTarjeta(int tarjeta_)
{
	tarjeta = tarjeta_; 	
}

int usuario::getTargeta()
{
	return tarjeta;
}
