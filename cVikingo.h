#pragma once
#include "Headers.h"

class cDragon;

class cVikingo
{
protected:
	const string vikiID;
	const string nombreV;
	const string apellidoV;
	ePos posicion;
	eCaract caractFisicasV;
	unsigned int DragonesEliminados;

public:
	cVikingo(string nombrev, string apellidov,eCaract caracteristicasfisicas);
	virtual ~cVikingo();

	const string getVikiID();
	const string get_nombreV();
	const string get_apellido();

	unsigned int  get_DragonesEliminados();
	void set_DragonesEliminados(unsigned int cant);
	ePos get_posicionV();
	void set_posicionV(ePos pos);

	 string enumPtostring();
	 string enumCtostring();

	void trabajarEnBerk();

	virtual bool RelacionarseConDragon(cDragon* drg) = 0;
};