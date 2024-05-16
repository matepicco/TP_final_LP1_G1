#pragma once
#include "Headers.h"
#include "cFormaAtaque.h"

class cDragon
{
private:
	string nombreD;
	string caracteristicaD;
	string tamanioD;
	string colorD;
	bool estadoD;
	bool domadoD;
	cFormaAtaque* formaataque;

	list <cFormaAtaque*> listaformaataque;

public:
	cDragon(string nombred, string caracteristicad, string tamaniod, string colord, bool estadod, bool domadod);
	~cDragon();
	void altaNombre(string nom);
	void entrenarDragon();
	void bajaDragon();
	string get_caracteristica();
	string get_nombre();
	string get_tamanio();
	string get_color();
	bool get_estado();
	void set_estado(bool estado);
	bool get_domado();
	void set_domado(bool domado);

	~cDragon();
};

