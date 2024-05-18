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
	eTamanio tamanioD;
	eColor colorD;
	bool estadoD;
	bool domadoD;

	list <cFormaAtaque*> listaFA;//posible defensa, diferentes tipos.

public:
	cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord);
	~cDragon();

	void altaNombre();
	void bajaDragon();
	eHabilidad get_caracteristica();
	string get_nombre();
	eTamanio get_tamanio();
	eColor get_color();
	bool get_estado();
	void set_estado(bool estado);
	bool get_domado();
	void set_domado(bool domado);
	cFormaAtaque* get_FormaAtaque();
	friend void cGuerrero::TerminarDragon(cDragon* objD, cGuerrero *objG);

	void atacarDragon(cDragon* objD);
	void entrenarDragon();
	~cDragon();
};

