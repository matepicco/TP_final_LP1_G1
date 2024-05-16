#pragma once
#include "cVikingo.h"

class cStoico
{
private:
	static int cantVikCreados;
	list <cVikingo*> listaVikingos;
public:
	cStoico();
	void agregarVikingo(cVikingo& objV);
	void eliminarVikingo(cVikingo* objV);
	static int getcantVikCreados();
	~cStoico();

};

