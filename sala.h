#pragma once
#include<iostream>

using namespace std;

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
	void toString();
	int getPrecio();
	~sala();
};
