#pragma once
#include "Headers.h"
#include "cAtaque.h"
#include "cDefensa.h"
#include "cGuerrero.h"
#include "cFormaCombate.h"
class cFormaCombate;

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

	int vidaD;

	list <cFormaCombate*> listaFA;
public:

	cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord);
	~cDragon();

	cFormaCombate* get_FormaCombateXIndice(int i);
	const int getDragonID();
	string get_nombre();
	eHabilidad get_caracteristica();
	eTamanio get_tamanio();
	eColor get_color();
	bool get_estado();
	bool get_domado();
	int getVidaD();
	void set_nombre(string nombre);
	void setVidaD(unsigned int vidaAct);
	void set_estado(bool estado);
	void set_domado(bool domado);
	void FAfuerteAdelante();
		
	list<cFormaCombate*> getListFA();
	void ordenarFAsalvajes(cDragon* objD);
	void bajaDragon();
	void agregarFA(cFormaCombate* objD);

	friend bool cGuerrero::PelearDragon(cDragon* objD);
	friend bool cGuerrero::RelacionarseConDragon(cDragon* drgNuevo);
	void atacarDragon(cDragon* objD);
	string toStringD();
	string enumAtostring();
	string enumDtostring();
	string enumColorTostring();
	bool operator==(cDragon &drg);
	void operator+(cFormaCombate* FC);
};