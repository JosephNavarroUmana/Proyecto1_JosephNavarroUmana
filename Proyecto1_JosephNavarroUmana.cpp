#include <iostream>
#include"Proyecto.h"

using namespace std;

int main()
{

	pelicula beeMovie("BeeMovie", 2007, 90, "USA", 8.5);
	pelicula adastra("Adastra", 2016, 95,"USA", 7.1);
	pelicula bonderlands("Bonderlands",2024, 102, "USA",7.5);
	pelicula skibiriToilet("Skibiri Toilet: mas toilet que nunca", 2025, 135, "India", 10);

	pelicula vectorPeliculas[4] = { beeMovie, adastra, bonderlands, skibiriToilet };

	sala primerSalaA1(1, "36", 3200);
	sala primerSalaA2(2, "36", 1500);
	sala primerSalaB1(3, "36", 2000);
	sala primerSalaB2(4, "36", 5000);

	sala vectorSalas[4] = {primerSalaA1, primerSalaA2, primerSalaB1, primerSalaB2};

	horarios primerHorario("6 de agosto", "2:00", "3:00");
	horarios segundoHorario("6 de agosto", "5:00", "6:00");
	horarios tercerHorario("6 de agosto", "7:00", "8:00");

	horarios vectorHorarios[3] = { primerHorario, segundoHorario, tercerHorario };

	cinema salaDeCine;

	salaDeCine.menu(vectorPeliculas, vectorHorarios, vectorSalas);

}

