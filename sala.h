#pragma once
#include<iostream>

using namespace std;

class sala
{
private:
	int numero;
	int butacas;
	int precio;
public:
	sala();
	sala(int numero_, int butacas_, int precio_);
	int getNumero();
	void toString();
	int getPrecio();
	void setButacas(int butacas_);
	void reducirButacas();
	~sala();
};
