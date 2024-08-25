#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"factura.h"

using namespace std;


factura::factura()
{

	cedula = 0;
	tarjeta = 0;
}

factura::~factura()
{
}

void factura::setCedula(int cedula_)
{
	if (cedula_ > 99999999) {
		cedula = cedula_;
	}
	else {
		cout << RED << "Debe digitar una cedula valida (9 digitos minimo)" << RESET << endl;
	}
}

void factura::setTarjeta(int tarjeta_)
{
	tarjeta = tarjeta_;
}

int factura::getCedula()
{
	return cedula;
}

int factura::getTarjeta()
{
	return tarjeta;
}

void factura::voucher(sala vectorSalas[], int salaSeleccionada, int codigoGenerado)
{
	int total = 0, codigo;
	total += vectorSalas[salaSeleccionada].getPrecio();
	if (total < 0) {
		cout << "Realize primero una compra " << endl;
	}
	else {
		cout << "Digite el codigo dado en su compra "; cin >> codigo;
		if (codigo == codigoGenerado) {
			cout << "Factura por la compra de sus entradas en " << GREEN << "CINEMAX WEB" << RESET << endl;
			cout << "Cedula --> " << getCedula() << endl;
			cout << "El precio a pagar por todas las entradas es de: " << total << endl;
		}
		else {
			cout << "El codigo es incorrecto" << endl;
		}
	}
}

