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
		cout << RED << "Debe digitar una targeta con mas de 9 digitos" << RESET << endl;
	}
}

void factura::setTarjeta(int tarjeta_)
{
	if (tarjeta_ > 99999999) {
		tarjeta = tarjeta_;
	}
	else {
		cout << RED << "Debe digitar una targeta con mas de 9 digitos" << RESET << endl;
	}
}

int factura::getCedula()
{
	return cedula;
}

int factura::getTarjeta()
{
	return tarjeta;
}

void factura::voucher(horarios vectorhorarios[],pelicula vectorPeliculas[],sala vectorSalas[], int salaSeleccionada, int codigoGenerado)
{
	int codigo;
	if (vectorSalas[salaSeleccionada].getPrecio() <= 0) {
		cout <<RED<< "Realize primero una compra " << endl<<RESET;
	}
	else {
		cout <<BLUE<< "\t\t\t\t\tDigite el codigo dado en su compra "<<RESET; cin >> codigo;
		if (codigo == codigoGenerado) {
			cout <<YELLOW<< "\t\t\t\tFactura por la compra de sus entradas en " << GREEN<<endl << "\t\t\t\t\t\tCINEMAX WEB" << RESET << endl;
			cout <<YELLOW<< "\t\t\t\t\tCedula --> " <<GREEN<< getCedula() << endl;
			cout << YELLOW << "\t\t\t\t\tPelicula --> " << GREEN << vectorPeliculas[salaSeleccionada].getNombre() << endl;
			cout << YELLOW << "\t\t\t\t\tSala --> " << GREEN << vectorSalas[salaSeleccionada].getNumero() << endl;
			cout << YELLOW << "\t\t\t\t\tHorario --> " << GREEN << vectorhorarios[salaSeleccionada].getFirtsHorario() << endl;
			cout <<YELLOW<< "\t\t\t\tEl precio a pagar por la entrada es de: " <<GREEN<< vectorSalas[salaSeleccionada].getPrecio() << endl<<RESET;
		}
		else {
			cout <<RED<<"El codigo es incorrecto" <<RESET<<endl;
		}
	}
}

