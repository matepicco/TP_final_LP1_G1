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
	static int b;
public:
	cStoico();
	~cStoico();

	void agregarVikingo(cVikingo* objV);
	void agregarDragon(cDragon* objD);
	void agregarDrgXlista(list<cDragon*> lista, cDragon* drg);
	void eliminarDrgXlista(list<cDragon*> lista, cDragon* drg);
	void eliminarVikingo(cVikingo* objV);
	void eliminarDragon(cDragon* objD);
	
	friend ostream& operator<<(ostream& out, cStoico* objS);
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
	
	void MandarAAtacar();
	void crearInteraccion();

	//metodos objetivo de Stoico. funcion: listar
	//metodo que modula el add a listaMatch. parametros lista y objeto
	void DragonesDomados();
	void JinetesxDragon();
};