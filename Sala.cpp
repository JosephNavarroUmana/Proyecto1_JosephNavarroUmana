#include"sala.h"
#include"Cinema.h"
#include<iostream>

Rooms::Rooms()
{
	number = 0;
	seats = 36;
	price = 0;
}

Rooms::Rooms(int number_, int seats_, int price_)
{
	number = number_;
	seats = seats_;
	price = price_;
}

int Rooms::getNumber()
{
	return number;
}

void Rooms::toString()
{
	cout <<YELLOW<< "Numero de sala --> " <<RED<<number << endl;
	cout <<YELLOW<< "Numero de butacas --> " <<RED<<seats << endl;
	cout <<YELLOW<< "Precio de la sala --> " <<RED<< price <<RESET<<endl;
	cout << endl;
}

int Rooms::getPrice()
{
	return price;
}

void Rooms::setSeats(int seats_)
{
	seats = seats_;
}

void Rooms::reduceSeats()
{
	seats--;
}

Rooms::~Rooms()
{
}
