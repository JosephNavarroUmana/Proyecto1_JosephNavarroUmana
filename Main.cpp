#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

using namespace std;

int main()
{
	Movie lifeIsBeautiful("La vida es bella", 1997, 116, "Italia", "Un hombre utiliza su imaginacion para proteger a su hijo de los horrores de un campo de concentración durante la Segunda Guerra Mundial.");
	Movie YourName("Your name", 2016, 106,"Japon", "Dos adolescentes, un chico y una chica, descubren que estan misteriosamente conectados al intercambiar cuerpos y buscan encontrarse.");
	Movie enigmaCode("Codigo enigma",2014, 113, "USA","La historia de Alan Turing, el matematico britanico que descifro el codigo Enigma durante la Segunda Guerra Mundial, cambiando el curso de la guerra.");
	Movie EEAO("Everything Everywhere All at Once", 2022, 139, "China", "Una mujer comun se ve envuelta en una batalla multiversal donde debe usar versiones alternativas de si misma para salvar la realidad.");

	Movie vectorMovies[4] = { lifeIsBeautiful, YourName, enigmaCode, EEAO };

	Rooms firstRoom(10, 36, 3200);
	Rooms secondRoom(25, 36, 1500);
	Rooms thirdRoom(36, 36, 2000);
	Rooms fourthRoom(42, 36, 5000);

	Rooms vectorRoom[4] = {firstRoom, secondRoom, thirdRoom, fourthRoom};

	Schedules firstSchedule("15 de septiembre", "2:30", "3:30");
	Schedules secondSchedule("15 de septiembre", "4:30", "5:30");
	Schedules thirdSchedule("15 de septiembre", "7:00", "8:00");

	Schedules vectorSchedule[3] = { firstSchedule, secondSchedule, thirdSchedule };

	Cinema movieTheater;

	Invoice firstVoucher;

	int menu = 0;
	bool validate = true;

	cout << RED << "\t\tPara una mejor experiencia en la pagina le recomendamos agrandar la ventana " << RESET << endl;
	system("pause");

	while (menu != 5) {
		system("cls");
		movieTheater.decorate();
		cout << RED << "\t\t\t\t\t\tMENU DE OPCIONES\n" << RESET;
		movieTheater.decorate();
		cout << YELLOW << "\t\t\t\t\t\t  1-Archivo" << endl;
		cout << "\t\t\t\t\t\t2-Mantenimiento" << endl;
		cout << "\t\t\t\t\t\t  3-Reservar" << endl;
		cout << "\t\t\t\t\t\t   4-Venta" << RESET << endl;
		movieTheater.decorate();
		cout << "\t\t\t\tSeleccione una opcion: ";
		cin >> menu;
		system("cls");

		switch (menu) {
		case 1:
			movieTheater.file(menu);
			break;
		case 2:
			movieTheater.maintenance(menu, vectorMovies, vectorSchedule, vectorRoom);
			break;

		case 3:
			movieTheater.reservation(vectorMovies, vectorSchedule, vectorRoom, firstVoucher);
			validate= false;
			break;
		case 4:
			movieTheater.sale(validate, firstVoucher, vectorRoom, vectorMovies, vectorSchedule);
			break;
		default:
			cout << "Error.\n";
			break;
		}
		if (menu != 5) {
			system("pause");
		}
	}

}

