#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

using namespace std;

int main()
{
	pelicula LaVidaEsBella("La vida es bella", 1997, 116, "Italia", "Un hombre utiliza su imaginación para proteger a su hijo de los horrores de un campo de concentración durante la Segunda Guerra Mundial.");
	pelicula YourName("Your name", 2016, 106,"Japon", "Dos adolescentes, un chico y una chica, descubren que están misteriosamente conectados al intercambiar cuerpos y buscan encontrarse.");
	pelicula codigoEnigma("Codigo enigma",2014, 113, "USA","La historia de Alan Turing, el matemático británico que descifró el código Enigma durante la Segunda Guerra Mundial, cambiando el curso de la guerra.");
	pelicula TTPMT("Everything Everywhere All at Once", 2022, 139, "China", "Una mujer común se ve envuelta en una batalla multiversal donde debe usar versiones alternativas de sí misma para salvar la realidad.");

	pelicula vectorPeliculas[4] = { LaVidaEsBella, YourName, codigoEnigma, TTPMT };

	sala primerSalaA1(10, 36, 3200);
	sala primerSalaA2(25, 36, 1500);
	sala primerSalaB1(36, 36, 2000);
	sala primerSalaB2(42, 36, 5000);

	sala vectorSalas[4] = {primerSalaA1, primerSalaA2, primerSalaB1, primerSalaB2};

	horarios primerHorario("6 de agosto", "11:30", "3:00");
	horarios segundoHorario("6 de agosto", "4:00", "6:00");
	horarios tercerHorario("6 de agosto", "7:00", "8:00");

	horarios vectorHorarios[3] = { primerHorario, segundoHorario, tercerHorario };

	cinema salaDeCine;

	factura primeraFactura;

	salaDeCine.menu(vectorPeliculas, vectorHorarios, vectorSalas, primeraFactura);


}

