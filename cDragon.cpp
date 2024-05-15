#include "cDragon.h"

cDragon::cDragon(string nombred, string caracteristicad, string tamaniod, string colord, bool estadod, bool domadod)
{
	this->nombreD = nombred;
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = estadod;
	this->domadoD = domadod;
	//this->listaforma = nullptr;//no permite en inicializar en null (agregacion)
}

void cDragon::altaNombre(string nom)
{
	this->nombreD = nom;
}

bool cDragon::get_domado()
{
	return this->domadoD;
}

void cDragon::entrenarDragon()
{
	//entrenando
}

void cDragon::bajaDragon()//hace esto??
{
	this->estadoD = false;
}

string cDragon::get_caracteristica()
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