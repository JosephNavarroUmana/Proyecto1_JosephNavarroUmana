#pragma once
#include<iostream>
using namespace std;

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
	void toString();
	~horarios();
};