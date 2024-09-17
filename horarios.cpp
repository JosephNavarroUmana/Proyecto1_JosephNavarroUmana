#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include <ctime>
#include <sstream>

Schedules::Schedules()
{
	date = " ";
	firstTime = " ";
	secondTime = " ";
}
Schedules::Schedules(string date_, string firstTime_, string secondTime_) {
	date = date_;
	firstTime = firstTime_;
	secondTime = secondTime_;
}
string Schedules::getFirstTime()
{
	return firstTime;
}
void Schedules::toString()
{
	cout <<YELLOW<< "Fecha --> " <<GREEN<< date << endl;
	cout <<YELLOW<< "Horario de inicio " <<GREEN<< firstTime << YELLOW<<" finaliza a las " <<GREEN<<secondTime << endl<<RESET;
}
Schedules::~Schedules()
{
}

bool Schedules::isLessThan30MinutesRemaining() {
    time_t tiempoActual = time(0);
    tm horaLocal; 

    localtime_s(&horaLocal, &tiempoActual); 

    int hora, minutos;
    stringstream ss(firstTime); 
    char separador;
    ss >> hora >> separador >> minutos; 

    tm horaIngresada = horaLocal;
    horaIngresada.tm_hour = hora;
    horaIngresada.tm_min = minutos;
    horaIngresada.tm_sec = 0;

    time_t tiempoIngresado = mktime(&horaIngresada);

    double diferenciaSegundos = difftime(tiempoIngresado, tiempoActual);

    if (diferenciaSegundos <= 1800 && diferenciaSegundos > 0) {
        return false; 
    }

    return true; 
}
