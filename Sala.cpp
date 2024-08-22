#include"sala.h"

#include<iostream>

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

void sala::toString()
{
	cout << "Numero de sala --> " << numero << endl;
	cout << "Numero de butacas --> " << butaca << endl;
	cout << "Precio de la sala --> " << precio << endl;
	cout << endl;
}

int sala::getPrecio()
{
	return precio;
}

sala::~sala()
{
}
