#pragma once
#include<iostream>

using namespace std;

class Rooms
{
private:
	int number;
	int seats;
	int price;
public:
	Rooms();
	Rooms(int number_, int seats_, int price_);
	int getNumber();
	void toString();
	int getPrice();
	void setSeats(int seats_);
	void reduceSeats();
	~Rooms();
};
