#include <iostream>

using namespace std;

int main()
{
	int menu=0;
	
	while (menu != 4) {

		system("cls");
		cout << "\n==========+==========+==========+==========+==========\n";
		cout << "            MENU DE OPCIONES\n";
		cout << "==========+==========+==========+==========+==========\n";
		cout << "Archivo" << endl;
		cout << "Mantenimiento" << endl;
		cout << "Reserva" << endl;
		cout << "Venta" << endl;
		cout << "==========+==========+==========+==========+==========\n";
		cout << "Seleccione una opcion: ";
		cin >> menu;

		system("cls");
		cout << "\n==========+==========+==========+==========+==========\n";

		switch (menu) {
		case 1:
			//archivo
			cout << "Acerca de " << endl;
			cout << "Salir" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << "Desarrollador: Joseph Navarro Umana\n";
				cout << "Creador de GTA 7\n";
				cout << "Fan de los easter egg\n";
				break;
			case 2:
				menu=4;
			default:
				break;
			}
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
			cout << "Error.\n";
			break;
		}
		if (menu != 4) {
			system("pause");
		}
	}

}

