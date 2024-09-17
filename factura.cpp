#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"factura.h"

using namespace std;


Invoice::Invoice()
{
	ID = 0;
	card = 0;
}

Invoice::~Invoice()
{
}

void Invoice::setID(int ID_)
{
		ID = ID_;
}

void Invoice::setCard(int Card_)
{
	card = Card_;
}

int Invoice::getID()
{
	return ID;
}

int Invoice::getCard()
{
	return card;
}

void Invoice::voucher(Schedules vectorSchedule[], Movie vectorMovies[], Rooms vectorRooms[], int roomSelected,int scheduleSelected, int code_)
{
    int codeAux;
        cout << BLUE << "\t\t\t\t\tDigite el codigo dado en su compra: " << RESET;
        cin >> codeAux;
        
        if (codeAux == code_) {
            system("cls");
            cout << YELLOW << "\n\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|           " << GREEN << "CINEMAX WEB - FACTURA" << RESET << YELLOW << "           |" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;

            cout << YELLOW << "\t\t\t\t| Numero de Factura: " << GREEN << codeAux << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Fecha: " << GREEN << "18/09/2024" << YELLOW << "                         |" << endl;
            cout << "\t\t\t\t| Cedula: " << GREEN << ID << YELLOW << "            \t\t    |" << endl;
            cout << "\t\t\t\t| Pelicula: " << GREEN << vectorMovies[roomSelected].getName() << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t| Sala: " << GREEN << vectorRooms[roomSelected].getNumber() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Horario: " << GREEN << vectorSchedule[scheduleSelected].getFirstTime() << YELLOW << "\t\t\t\t    |" << endl;
            cout << "\t\t\t\t| Precio por Entrada: " << GREEN << "$" << vectorRooms[roomSelected].getPrice() << YELLOW << "\t\t    |" << endl;
            cout << "\t\t\t\t+===========================================+" << endl;
            cout << "\t\t\t\t|" << GREEN << "Gracias por su compra! Disfrute la pelicula" << RESET << YELLOW << "|" << endl;
            cout << "\t\t\t\t+===========================================+" << RESET << endl;
        }
        else {
            cout << RED << "\t\t\t\tEl codigo es incorrecto." << RESET << endl;
        }
    
}
