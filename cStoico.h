#pragma once
#include "cGuerrero.h"
#include "cJinete.h"

class cVikingo;
class cStoico
{
private:
	static int cantVikCreados;
	static int cantDrgCreados;
	list <cVikingo*> listaVikingos;
	list <cDragon*> listaDrgS;
	list<cDragon*> listaDrgMatcheados;
public:
	cStoico();

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
	//not necesario para friend xq main posee a stoico y << metodo public
	string to_string();
	cVikingo* get_vikingoxNom(string nombre);
	cVikingo* get_vikingoxPos(ePos pos);
	static int getcantVikCreados();

	void crearInteraccion();// le cambie el nombre porque en jinete no ataca directamente, primero entrena
	

	//m�todos objetivo de Stoico. funci�n: listar
	void DragonesDomados();
	void JinetesxDragon();
	~cStoico();
};