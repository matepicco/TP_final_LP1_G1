#include "cDragon.h"

cDragon::cDragon(string nombred, eHabilidad caracteristicad, string tamaniod, string colord)
{
	this->nombreD = nombred;
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = true;
	this->domadoD = false;
}

void cDragon::altaNombre()
{
//eeeeeee lo que dice la def, tonto esta ahi, para que venis a verlo aca, tonto
}

void cDragon::atacarDragon()
{
}

void cDragon::entrenarDragon()
{
	//lista de ifs que ven su habilidad y de acuerdo a esta establecen la forma de ataque
	//es lineal, digamos una habilidad va a una forma de ataque
}

bool cDragon::get_domado()
{
	return this->domadoD;
}

void cDragon::bajaDragon()//hace esto??// seria como un set cuando lo matan?
{
	this->estadoD = false;
}

eHabilidad cDragon::get_caracteristica()
{
	return this->caracteristicaD;
}

string cDragon::get_nombre()
{
	return this->nombreD;
}

string cDragon::get_tamanio()
{
	return this->tamanioD;
}

string cDragon::get_color()
{
	return this->colorD;
}

bool cDragon::get_estado()
{
	return this->estadoD;
}

void cDragon::set_estado(bool estado)
{
	this->estadoD = estado;
}

void cDragon::set_domado(bool domado)
{
	this->domadoD = domado;
}

cDragon::~cDragon()
{
}

void cVikingo::TerminarDragon(cDragon* objD)
{//random 0 o 1 que hacer q muera el dragon o muera l vikin
		objD->set_estado(false);
		this->DragonesEliminados++;

		//mas adelante iria mas desarrollado con el tema de comparar habilidades
		//o que le baje la vida o simplemente vivan los dos
}
