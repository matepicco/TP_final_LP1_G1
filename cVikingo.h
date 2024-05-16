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
	cVikingo(string nombrev, string apellidov, string posicionv, unsigned int dragoneliminado);
	string get_nombreV();
	string get_apellido();
	string get_posicionV();
	unsigned int get_DragonesEliminados();
	void set_posicionV(string pos);
	void set_DragonesEliminados(unsigned int dragoneseliminados);
	void trabajar();
	void atacarDragones(cDragon* objD);
	unsigned int TerminarDragon();

	~cVikingo();
};