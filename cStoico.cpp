#include "cStoico.h"

cStoico::cStoico()
{
	this->listaVikingos = list<cVikingo*>(); //auspicia mati larrosa
}

void cStoico::agregarVikingo(cVikingo& objV)
{
	this->listaVikingos.push_back(&objV);
}

void cStoico::eliminarVikingo(cVikingo* objV)
{
	this->listaVikingos.pop_back(); //?
}

int cStoico::getcantVikCreados()
{
	return cantVikCreados;
}

cStoico::~cStoico()
{
}

