#pragma once
#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"factura.h"

using namespace std;

const int LIMIT_MATRIZ = 6;
const int NUMERO_HORARIOS = 3;
const int NUMERO_SALAS = 4;
const int NUMERO_PELICULAS = 4;

#define PINK "\033[35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m"    
#define YELLOW  "\033[33m"     
#define BLUE    "\033[34m"      

class cinema
{
private:
	int matriz[NUMERO_SALAS][LIMIT_MATRIZ][LIMIT_MATRIZ][NUMERO_HORARIOS];
	int codigo;
	
public:
	cinema();
	~cinema();
	int getCodigo();
	void toString(int peliculaSeleccionada, int horario);
	void setUbicacion(int a, int b, int c, int d);
	void menu(pelicula coso[], horarios vec[], sala vector[], factura factura1);
	int generarCodigo();
};
