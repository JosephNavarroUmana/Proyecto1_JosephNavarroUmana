#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

using namespace std;

int main()
{
	pelicula LaVidaEsBella("La vida es bella", 1997, 116, "Italia", "Un hombre utiliza su imaginacion para proteger a su hijo de los horrores de un campo de concentración durante la Segunda Guerra Mundial.");
	pelicula YourName("Your name", 2016, 106,"Japon", "Dos adolescentes, un chico y una chica, descubren que estan misteriosamente conectados al intercambiar cuerpos y buscan encontrarse.");
	pelicula codigoEnigma("Codigo enigma",2014, 113, "USA","La historia de Alan Turing, el matematico britanico que descifro el codigo Enigma durante la Segunda Guerra Mundial, cambiando el curso de la guerra.");
	pelicula TTPMT("Everything Everywhere All at Once", 2022, 139, "China", "Una mujer comun se ve envuelta en una batalla multiversal donde debe usar versiones alternativas de si misma para salvar la realidad.");

	pelicula vectorPeliculas[4] = { LaVidaEsBella, YourName, codigoEnigma, TTPMT };

	sala primerSalaA1(10, 36, 3200);
	sala primerSalaA2(25, 36, 1500);
	sala primerSalaB1(36, 36, 2000);
	sala primerSalaB2(42, 36, 5000);

	sala vectorSalas[4] = {primerSalaA1, primerSalaA2, primerSalaB1, primerSalaB2};

	horarios primerHorario("15 de septimebre", "2:30", "3:30");
	horarios segundoHorario("15 de septimebre", "4:30", "5:30");
	horarios tercerHorario("15 de septimebre", "7:00", "8:00");

	horarios vectorHorarios[3] = { primerHorario, segundoHorario, tercerHorario };

	cinema salaDeCine;

	factura primeraFactura;

	int menu = 0, tarjeta = 0, codigo = 0, fila = 0,horario = 0, salida = 0;
	char columna = 'a';
	bool validar = true;

	cout << RED << "\t\tPara una mejor experiencia en la pagina le recomendamos agrandar la ventana " << RESET << endl;
	system("pause");

	while (menu != 5) {
		system("cls");
		salaDeCine.decoracion();
		cout << RED << "\t\t\t\t\t\tMENU DE OPCIONES\n" << RESET;
		salaDeCine.decoracion();
		cout << YELLOW << "\t\t\t\t\t\t  1-Archivo" << endl;
		cout << "\t\t\t\t\t\t2-Mantenimiento" << endl;
		cout << "\t\t\t\t\t\t  3-Reservar" << endl;
		cout << "\t\t\t\t\t\t   4-Venta" << RESET << endl;
		salaDeCine.decoracion();
		cout << "\t\t\t\tSeleccione una opcion: ";
		cin >> menu;
		system("cls");

		switch (menu) {
		case 1:
			salaDeCine.archivo(menu);
			break;
		case 2:
			salaDeCine.mantenimiento(menu, vectorPeliculas, vectorHorarios, vectorSalas);
			break;

		case 3:
			salaDeCine.reserva(vectorPeliculas, vectorHorarios, vectorSalas, primeraFactura, salida, fila, columna, tarjeta);
			validar= false;
			break;
		case 4:
			salaDeCine.venta(validar, primeraFactura, vectorSalas, vectorPeliculas, vectorHorarios);
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

