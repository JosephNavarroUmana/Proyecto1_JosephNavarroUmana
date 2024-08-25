#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"usuario.h"
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
	cedula = cedula_;
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

void factura::voucher(sala vectorSalas[], int salaSeleccionada, usuario persona1)
{
	srand(time(NULL));
	int total = 0, codigo;
	total += vectorSalas[salaSeleccionada].getPrecio();
	if (total < 0) {
		cout << "Realize primero una compra " << endl;
	}
	else {
		cout << "Digite el codigo dado en su compra "; cin >> codigo;
		if (codigo == persona1.generarCodigo()) {
			cout << "Factura por la compra de sus entradas en " << GREEN << "CINEMAX WEB" << RESET << endl;
			cout << "Cedula --> " << persona1.getCedula() << endl;
			cout << "El precio a pagar por todas las entradas es de: " << total << endl;
		}
		else {
			cout << "El codigo es incorrecto" << endl;
		}
	}
}

