#pragma once
#include "Headers.h"
#include "cFormaAtaque.h"
#include "cGuerrero.h"

class cGuerrero; 
class cJinete;
class cDragon
{
private:
	static int dragonesCreados;
	const int dragonID;
	string nombreD;
	eHabilidad caracteristicaD;
	eTamanio tamanioD;
	eColor colorD;
	bool estadoD;
	bool domadoD;

	unsigned int vidaD;

	list <cFormaAtaque*> listaFA;//posible defensa, diferentes tipos.

public:
	friend class cJinete;
	cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord);
	~cDragon();
	void bajaDragon();
	void set_nombre(string nombre);
	const int getDragonID();
	string get_nombre();
	eHabilidad get_caracteristica();
	eTamanio get_tamanio();
	eColor get_color();
	bool get_estado();
	bool get_domado();
	unsigned int getVidaD();
	void setVidaD(unsigned int vidaAct);
	void set_estado(bool estado);
	void set_domado(bool domado);
	cFormaAtaque* get_FormaAtaque();
	void agregarFA(cFormaAtaque* objD);

	friend void TerminarDragon(cDragon* objD);
	friend void RelacionarseConDragon(cVikingo* objV, cDragon* objD);
	void atacarDragon(cDragon* objD);

};