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
	float review;
public:
	pelicula();
	~pelicula();
};

class sala
{
private:
	int numero;
	string butacas;
	int precio;
public:
	sala();
	~sala();
};

class horarios
{
private:
	string fecha;
	int firtsHorario;
	int segundoHorario;
public:
	horarios();
	~horarios();
};



