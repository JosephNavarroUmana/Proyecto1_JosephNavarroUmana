#pragma once
#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"factura.h"

using namespace std;

const int LIMIT_MATRIX = 6;
const int NUMBER_TIME = 3;
const int NUMBER_ROOMS = 4;
const int NUMBER_MOVIE = 4;

#define PINK "\033[35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m"    
#define YELLOW  "\033[33m"     
#define BLUE    "\033[34m"      

class Cinema
{
private:
	int matrix[NUMBER_ROOMS][LIMIT_MATRIX][LIMIT_MATRIX][NUMBER_TIME];
	int code;
	int movieSelected;
	int timeSelected;
	
public:
	Cinema();
	~Cinema();
	void toString();
	bool setLocation(int room, int row, int column);
	int identifyLetter(char columna);
	void decorate();
	void file(int &menu);
	void maintenance(int menu, Movie vectorMovies[], Schedules vectorSchedule[], Rooms vectorRooms[]);
	void reservation(Movie vectorMovies[], Schedules vectorSchedule[], Rooms vectorRooms[], Invoice &firstVoucher);
	int generateCode();
	void sale(bool validate, Invoice firstVoucher, Rooms vectorRooms[], Movie vectorMovies[], Schedules vectorSchedule[]);
	void saveState(int estado);
	void changeState(int movieSelected, int row, char column, int scheduleSelected);

};
