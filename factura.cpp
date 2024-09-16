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

void factura::voucher(horarios vectorhorarios[], pelicula vectorPeliculas[], sala vectorSalas[], int salaSeleccionada, int codigoGenerado)
{
    int codigo;
    if (vectorSalas[salaSeleccionada].getPrecio() <= 0) {
        cout << RED << "\t\t\t\tRealice primero una compra." << endl << RESET;
    }
    else {
        cout << BLUE << "\t\t\t\t\tDigite el codigo dado en su compra: " << RESET;
        cin >> codigo;

        if (codigo == codigoGenerado) {
            cout << YELLOW << "\n\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|           " << GREEN << "CINEMAX WEB - FACTURA" << RESET << YELLOW << "           |" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;

            cout << YELLOW << "\t\t\t\t| Numero de Factura: " << GREEN << rand() % 10000 << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Fecha: " << GREEN << "18/09/2024" << YELLOW << "                         |" << endl;
            cout << "\t\t\t\t| Cedula: " << GREEN << getCedula() << YELLOW << "            \t\t    |" << endl;
            cout << "\t\t\t\t| Pelicula: " << GREEN << vectorPeliculas[salaSeleccionada].getNombre() << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Sala: " << GREEN << vectorSalas[salaSeleccionada].getNumero() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Horario: " << GREEN << vectorhorarios[salaSeleccionada].getFirtsHorario() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Precio por Entrada: " << GREEN << "$" << vectorSalas[salaSeleccionada].getPrecio() << YELLOW << "\t\t    |" << endl;

            // Pie de la factura
            cout << "\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|" << GREEN << "Gracias por su compra! Disfrute la pelicula" << RESET << YELLOW << "|" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;
        }
        else {
            cout << RED << "\t\t\t\tEl codigo es incorrecto." << RESET << endl;
        }
    }
}
