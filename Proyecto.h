#pragma once
#include<iostream>
using namespace std;

const int LIMIT_MATRIZ = 6;
const int NUMERO_HORARIOS = 3;
const int NUMERO_SALAS = 4;
const int NUMERO_PELICULAS = 4;
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
	int matriz[NUMERO_SALAS][LIMIT_MATRIZ][LIMIT_MATRIZ][NUMERO_HORARIOS];
	
public:
	pelicula movie[4];
	cinema();
	~cinema();
	void toString(int peliculaSeleccionada, int horario);
	void setUbicacion(int a, int b, int c, int d);
	void factura();
	void menu(pelicula coso[], horarios vec[], sala vector[]);
	
};