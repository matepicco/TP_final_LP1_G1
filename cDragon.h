#pragma once
#include "Headers.h"
#include "cFormaAtaque.h"

class cDragon
{
private:
	string nombreD;
	eHabilidad caracteristicaD;
	string tamanioD;
	string colorD;
	bool estadoD;
	bool domadoD;

	list <cFormaAtaque*> listaformaataque;//porque puede haber defensa etc.

public:
	cDragon(string nombred, eHabilidad caracteristicad, string tamaniod, string colord);
	~cDragon();
	void altaNombre();//de acuerdo a las caracteristicas o ataque, se llama de tal manera
	
	void bajaDragon();
	eHabilidad get_caracteristica();
	string get_nombre();
	string get_tamanio();
	string get_color();
	bool get_estado();
	void set_estado(bool estado);
	bool get_domado();
	void set_domado(bool domado);
	friend 	void AtacarDragon(cDragon& objD);//Porque me pide una implementacion si justamente esta hecha en vikingo

	void atacarDragon();
	void entrenarDragon();
	~cDragon();
};

