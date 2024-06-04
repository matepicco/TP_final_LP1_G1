#pragma once
#include "Headers.h"

class cDragon;

class cVikingo
{
private:
	string nombreV;
	string apellidoV;
	ePos posicion;
	eCaract caractFisicasV;
	unsigned int DragonesEliminados;

public:
	cVikingo(string nombrev, string apellidov,eCaract caracteristicasfisicas);
	string get_nombreV();
	string get_apellido();

	unsigned int  get_DragonesEliminados();
	void set_DragonesEliminados(unsigned int cant);
	ePos get_posicionV();
	void set_posicionV(ePos pos);

	void trabajarEnBerk();
	virtual void RelacionarseConDragon(cVikingo* ptrV);
	~cVikingo();
};