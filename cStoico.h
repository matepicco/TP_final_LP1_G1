#pragma once
#include "cGuerrero.h"
#include "cJinete.h"

class cStoico
{
private:
	static int cantVikCreados;
	static int cantDrgCreados;
	list <cVikingo*> listaVikingos;
	list <cDragon*> listaDrgS;
	list<cDragon*> listaDrgMatcheados;
	static int b;
public:
	cStoico();
	~cStoico();
	friend ostream& operator<<(ostream& out, cStoico stoico);

	void agregarVikingo(cVikingo* objV);
	void agregarDragon(cDragon* objD);
	void agregarDrgXlista(list<cDragon*> lista, cDragon* drg);
	void eliminarDrgXlista(list<cDragon*> lista, cDragon* drg);
	void eliminarVikingo(cVikingo* objV);
	void eliminarDragon(cDragon* objD);
	
	void operator-(cDragon* objD);
	void operator+(cVikingo* objV);
	void operator+(cDragon* objD);
	void operator-(cVikingo* objV);

	void imprimir();
	string toStringS();
	cVikingo* get_vikingoxNom(string nombre);
	cVikingo* get_vikingoxPos(ePos pos);
	static int getcantVikCreados();
	
	void MandarAAtacar();
	void crearInteraccion();

	//metodos objetivo de Stoico. funcion: listar
	void DragonesDomados();
	void JinetesxDragon();
};