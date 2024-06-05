#pragma once
#include "cVikingo.h"

#include "cGuerrero.h"
#include "cJinete.h"

class cStoico
{
private:
	static int cantVikCreados;
	static int cantDrgCreados;
	list <cVikingo*> listaVikingos;
	list <cDragon*> listaDrgS;
public:
	cStoico();

	void agregarVikingo(cVikingo* objV);
	void agregarDragon(cDragon* objD);
	void eliminarVikingo(cVikingo* objV);
	void eliminarDragon(cVikingo* objD);

	cVikingo* get_vikingoxNom(string nombre);
	cVikingo* get_vikingoxPos(ePos pos);

	void mandarAentrenar();

	void mandarAatacar();
	static int getcantVikCreados();

	//m�todos objetivo de Stoico. funci�n: listar
	void DragonesDomados();
	void JinetesxDragon();
	~cStoico();

};