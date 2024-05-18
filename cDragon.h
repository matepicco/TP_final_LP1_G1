#pragma once
#include "Headers.h"
#include "cFormaAtaque.h"
#include "cGuerrero.h"

class cGuerrero; 

//posible herencia: dragones se comportan distinto
class cDragon
{
private:
	string nombreD;
	eHabilidad caracteristicaD;
	string tamanioD;
	string colorD;
	bool estadoD;
	bool domadoD;

	list <cFormaAtaque*> listaFA;//posible defensa, diferentes tipos.

public:
	cDragon(string nombred, eHabilidad caracteristicad, string tamaniod, string colord);
	~cDragon();

	void altaNombre();
	void bajaDragon();
	eHabilidad get_caracteristica();
	string get_nombre();
	string get_tamanio();
	string get_color();
	bool get_estado();
	void set_estado(bool estado);
	bool get_domado();
	void set_domado(bool domado);

	friend void cGuerrero::TerminarDragon(cDragon* objD, cGuerrero *objG);

	void atacarDragon(cDragon* objD);
	void entrenarDragon();
	~cDragon();
};

