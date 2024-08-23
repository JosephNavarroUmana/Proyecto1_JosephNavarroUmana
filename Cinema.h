#pragma once
#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"usuario.h"

using namespace std;

const int LIMIT_MATRIZ = 6;
const int NUMERO_HORARIOS = 3;
const int NUMERO_SALAS = 4;
const int NUMERO_PELICULAS = 4;

class factura {
private:
	int cedula;
	int tarjeta;
public:
	factura();
	~factura();
	void setCedula(int cedula_);
	void setTarjeta(int tarjeta_);
	int getCedula();
	int getTarjeta();
	void voucher(sala vectorSalas[], int salaSeleccionada, usuario persona1);
};
class cinema
{
private:
	int matriz[NUMERO_SALAS][LIMIT_MATRIZ][LIMIT_MATRIZ][NUMERO_HORARIOS];
	
public:
	cinema();
	~cinema();
	void toString(int peliculaSeleccionada, int horario);
	void setUbicacion(int a, int b, int c, int d);
	void menu(pelicula coso[], horarios vec[], sala vector[], factura factura1, usuario cliente);
	
};
