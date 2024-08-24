#pragma once
#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"
#include"usuario.h"

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