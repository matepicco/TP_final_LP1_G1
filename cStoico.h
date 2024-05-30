#pragma once
#include "cVikingo.h"

class cStoico
{
private:
	static int cantVikCreados;
	list <cVikingo*> listaVikingos;
public:
	cStoico();
	void agregarVikingo(cVikingo* objV);
	void eliminarVikingo(cVikingo* objV);
	cVikingo* get_vikingoxNom(string nombre);
	cVikingo* get_vikingoxPos(ePos pos);
	void mandarAentrenar();
	void mandarAatacar();
	static int getcantVikCreados();
	~cStoico();

};