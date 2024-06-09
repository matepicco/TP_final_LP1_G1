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
	//friend class cJinete;
	cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord);
	~cDragon();

	const int getDragonID();
	string get_nombre();
	eHabilidad get_caracteristica();
	eTamanio get_tamanio();
	eColor get_color();
	bool get_estado();
	bool get_domado();
	unsigned int getVidaD();
	void set_nombre(string nombre);
	void setVidaD(unsigned int vidaAct);
	void set_estado(bool estado);
	void set_domado(bool domado);
	cFormaAtaque* get_FormaAtaque();

	void bajaDragon();
	void agregarFA(cFormaAtaque* objD);

	friend bool cGuerrero::TerminarDragon(cDragon* objD);
	friend bool cGuerrero::RelacionarseConDragon(cDragon* objD);
	void atacarDragon(cDragon* objD);
};