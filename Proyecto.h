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
	pelicula(string nombre_, int year_, int duration_, string country_, float review_);
	~pelicula();
	string getNombre();
	void setNombre(string nombre_);
	void toString();
	
};

class sala
{
private:
	int numero;
	string butaca;
	int precio;
public:
	sala();
	sala(int numero_, string butacas_, int precio_);
	int getNumero();
	~sala();
};

class horarios
{
private:
	string fecha;
	string firtsHorario;
	string segundoHorario;
public:
	horarios();
	horarios(string fecha_, string firtsHorario, string segundoHorario);
	string getFirtsHorario();
	~horarios();
};

class cinema
{
private:
	int matriz[3][3];
	
public:
	pelicula movie[4];
	cinema();
	~cinema();
	void toString();
	void setUbicacion(int a, int b);
	
};