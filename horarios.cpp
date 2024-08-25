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
	cout <<YELLOW<< "Fecha --> " <<GREEN<< fecha << endl;
	cout <<YELLOW<< "Horario de inicio " <<GREEN<< firtsHorario << YELLOW<<" finaliza a las " <<GREEN<<segundoHorario << endl<<RESET;
}
horarios::~horarios()
{
}
