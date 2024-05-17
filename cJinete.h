#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
private:
	string apodoD;
	time_t fechaNac;
	string caractFisicasJ;
	eResultado TrainResult;
	list <cDragon*> listaDragones;
	
public:
	cJinete(string nom, string ape, time_t fecha, string caracfisic);//el apodo se lo asigna gracias al dragon que doma

	string get_apodo();
	string get_caracteristicas();
	eResultado get_trainresult();
	void set_trainresult(eResultado resultado);

	void incorporarDragon(cDragon* ptrDragon);//lo incorpora, setea el domado y lo entrena
	void domar();//listo
	void RelacionarseDragon();/*
	* primer contacto con el dragon, evalua si es domable, si es, llama a incorporar
	* compara caract del jinete con las del dragon, a ver si son compatibles
	*/
	void manejarDragon();//dispara el metodo de dragon que ataca a otro dragon

	~cJinete();
};
