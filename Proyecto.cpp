#include"Proyecto.h"

void menu() {

	int menu;
	cout << "\t\tMenu" << endl;
	cout << "Archivo" << endl;
	cout << "Mantenimiento" << endl;
	cout << "Reserva" << endl;
	cout << "Venta" << endl;
	cin >> menu;

	switch (menu)
	{
	case 1:
		//archivo
		cout << "Acerca de " << endl;
		cout << "Salir" << endl;
		cin >> menu;
		/*switch (menu)
		{
		case 1:
			cout << "Hola";
			break;
		case 2:
			cout << "Adios";
		default:
			break;
		}*/
		break;
	case 2:
		//mantenimiento
		break;
	case 3:
		//reservar
		break;
	case 4:
		//venta
		break;
	default:
		break;
	}
}

pelicula::pelicula()
{

}

pelicula::~pelicula()
{
}

sala::sala()
{
}

sala::~sala()
{
}

horarios::horarios()
{
}

horarios::~horarios()
{
}