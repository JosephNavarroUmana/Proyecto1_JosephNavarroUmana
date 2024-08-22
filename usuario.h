#pragma once
#include<stdlib.h>

class usuario
{
private:
	int cedula;
	int codigo;
	int tarjeta;
public:
	usuario();
	~usuario();
	int generarCodigo();
	void setCedula(int id);
	int getCedula();
	void setTarjeta(int tarjeta_);
	int getTargeta();

};

