#pragma once
#include "Headers.h"

class cDragon;

class cVikingo
{
private:
	string nombreV;
	string apellidoV;
	string posicionV;
	unsigned int DragonesEliminados;//Esto enrealidad en el TP aparece como un Enum, tipo positivo negativo

public:
	cVikingo();
	cVikingo(string nombrev, string apellidov, string posicionv);
	string get_nombreV();
	string get_apellido();
	string get_posicionV();
	unsigned int get_DragonesEliminados();
	void set_posicionV(string pos);//no se haria esto en trabajar?
	/////////////////////////////////
	void trabajar();
	void AtacarDragon(cDragon& objD);
	void TerminarDragon();

	~cVikingo();
};