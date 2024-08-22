#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

horarios::horarios()
{
	fecha = " ";
	firtsHorario = " ";
	segundoHorario = " ";
}

horarios::horarios(string fecha_, string firtsHorario_, string segundoHorario_) {
	fecha = fecha_;
	firtsHorario = firtsHorario_;
	segundoHorario = segundoHorario_;
}
string horarios::getFirtsHorario()
{
	return firtsHorario;
}
void horarios::toString()
{
	cout << "Fecha --> " << fecha << endl;
	cout << "Horario de inicio " << firtsHorario << " finaliza a las " << segundoHorario << endl;
}

horarios::~horarios()
{
}
