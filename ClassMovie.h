#pragma once
#include<iostream>
using namespace std;

class pelicula
{
private:
	string nombre;
	int year;
	int duration;
	string country;
	string review;
public:
	pelicula();
	pelicula(string nombre_, int year_, int duration_, string country_, string review_);
	~pelicula();
	string getNombre();
	void setNombre(string nombre_);
	void toString();

};