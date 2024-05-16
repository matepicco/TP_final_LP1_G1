#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
private:
	string nombreJ;
	string apodoD;
	time_t fechaNac;
	string caractFisicasJ;
	eResultado TrainResult;
	cDragon* dragon;

public:
	cJinete(string nom, time_t fecha, string caracfisic);//el apodo se lo asigna gracias al dragon que doma
	~cJinete();
	string get_nombreJ();
	void incorporarDragon(cDragon* ptrDragon);//lo incorpora, setea el domado y lo entrena
	void trabajarBerk();// para mi no va
	
	void domar();//listo
	eResultado get_trainresult();
	string get_apodo();
	string get_caracteristicas();
	void set_trainresult(eResultado resultado);

	void RelacionarseDragon();//primer contacto con el dragon, evalua si es domable, si es, llama a incorporar
	//compara caract del jinete con las del dragon, a ver si son compatibles
	//mate dice que se deberian pelear ademas


	void manejarDragon();//dispara el metodo de dragon que ataca a otro dragon
};
