#include"sala.h"
#include"Cinema.h"
#include<iostream>

sala::sala()
{
	numero = 0;
	butacas = 36;
	precio = 0;
}

sala::sala(int numero_, int butacas_, int precio_)
{
	numero = numero_;
	butacas = butacas_;
	precio = precio_;
}

int sala::getNumero()
{
	return numero;
}

void sala::toString()
{
	cout <<YELLOW<< "Numero de sala --> " <<RED<<numero << endl;
	cout <<YELLOW<< "Numero de butacas --> " <<RED<<butacas << endl;
	cout <<YELLOW<< "Precio de la sala --> " <<RED<< precio <<RESET<<endl;
	cout << endl;
}

int sala::getPrecio()
{
	return precio;
}

void sala::setButacas(int butacas_)
{
	butacas = butacas_;
}

void sala::reducirButacas()
{
	butacas--;
}

sala::~sala()
{
}
