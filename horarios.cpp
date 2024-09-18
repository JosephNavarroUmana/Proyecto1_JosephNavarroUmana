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
    time_t ActualTime = time(0);
    tm localTime; 

    localtime_s(&localTime, &ActualTime); 

    int hours, minutes;
    stringstream ss(firstTime); 
    ss >> hours >>  minutes; 

    tm horaIngresada = localTime;
    horaIngresada.tm_hour = hours;
    horaIngresada.tm_min = minutes;
    horaIngresada.tm_sec = 0;

    time_t tiempoIngresado = mktime(&horaIngresada);

    double diferenciaSegundos = difftime(tiempoIngresado, ActualTime);

    if (diferenciaSegundos <= 1800 && diferenciaSegundos > 0) {
        return false; 
    }

    return true; 
}
