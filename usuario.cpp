#include "usuario.h"
#include <stdlib.h>

usuario::usuario()
{
	cedula = 0;
	tarjeta = 0;
	codigo = 0;
}

usuario::~usuario()
{
}

int usuario::generarCodigo()
{
	return (codigo = rand() % 100 + 1);
}

void usuario::setCedula(int id)
{
	cedula = id;
}

int usuario::getCedula()
{
	return cedula;
}

void usuario::setTarjeta(int tarjeta_)
{
	tarjeta = tarjeta_;
}

int usuario::getTargeta()
{
	return tarjeta;
}
