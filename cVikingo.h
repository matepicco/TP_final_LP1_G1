#pragma once
#include "Headers.h"

class cDragon;

class cVikingo
{
private:
	string nombreV;
	string apellidoV;
	string posicionV;
	unsigned int DragonesEliminados;//Bool: positivo negativo: true or false

public:
	cVikingo();
	cVikingo(string nombrev, string apellidov, string posicionv);
	string get_nombreV();
	string get_apellido();

	unsigned int  get_DragonesEliminados();
	void set_DragonesEliminados(unsigned int cant);
	string get_posicionV();
	void set_posicionV(string pos);//no se haria esto en trabajar?

	void trabajar(); //pasará determinarse por parametro en el constructor
	void atacarDragones(); //manda el mensaje. stoico ejecuta?

	~cVikingo();
};