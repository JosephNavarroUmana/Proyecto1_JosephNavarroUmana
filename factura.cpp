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

void factura::voucher(horarios vectorhorarios[], pelicula vectorPeliculas[], sala vectorSalas[], int salaSeleccionada,int horarioSeleccionado, int codigoGenerado)
{
    int codigo;
        cout << BLUE << "\t\t\t\t\tDigite el codigo dado en su compra: " << RESET;
        cin >> codigo;
        
        if (codigo == codigoGenerado) {
            system("cls");
            cout << YELLOW << "\n\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|           " << GREEN << "CINEMAX WEB - FACTURA" << RESET << YELLOW << "           |" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;

            cout << YELLOW << "\t\t\t\t| Numero de Factura: " << GREEN << codigo << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Fecha: " << GREEN << "18/09/2024" << YELLOW << "                         |" << endl;
            cout << "\t\t\t\t| Cedula: " << GREEN << cedula << YELLOW << "            \t\t    |" << endl;
            cout << "\t\t\t\t| Pelicula: " << GREEN << vectorPeliculas[salaSeleccionada].getNombre() << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Sala: " << GREEN << vectorSalas[salaSeleccionada].getNumero() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Horario: " << GREEN << vectorhorarios[horarioSeleccionado].getFirtsHorario() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Precio por Entrada: " << GREEN << "$" << vectorSalas[salaSeleccionada].getPrecio() << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|" << GREEN << "Gracias por su compra! Disfrute la pelicula" << RESET << YELLOW << "|" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;
        }
        else {
            cout << RED << "\t\t\t\tEl codigo es incorrecto." << RESET << endl;
        }
    
}
