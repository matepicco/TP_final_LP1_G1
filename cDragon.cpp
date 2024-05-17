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

void cGuerrero::TerminarDragon(cDragon* objD, cGuerrero *objG)
{
	//random 0 o 1 que hace q muera el dragon o muera el vikingo
	objD->set_estado(false);
	objG->set_DragonesEliminados(1);

	/*
		* constará de un enfrentamiento entre dragon y el vikingo para contrastar las habilidades y deb
		*más desarrollado aún: bajen la vida y acabe el enfrentamiento y vivan los dos
		*/
}
