#include "cDragon.h"

int cDragon::dragonesCreados = 0;

cDragon::cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord): dragonID(dragonesCreados)
{
	//paso x parametro FA, igualo al parametro
	//si con new no recibe x param
	this->nombreD = "";
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = true;
	this->domadoD = false;
	this->vidaD = 100;

	this->listaFA = list<cFormaAtaque*>();
	dragonesCreados++;
}

void cGuerrero::TerminarDragon(cDragon* objD)
{
	if (objD->get_estado() == false)
		throw exception("Este Dragon esta muerto");
	else if (objD->get_domado() == true)
		throw exception("Este Dragon es bueno");

	/*
	* constará de un enfrentamiento entre dragon y vikingo: contrastará las habilidades y deb
	* más desarrollado aún: ambos 100 de daño, entonces empate, knock out doble, evaluo con if
	*/
	while (this->cantVidaG > 0 && objD->getVidaD() > 0)
	{
		objD->setVidaD(objD->getVidaD() - this->getCantDanioG());
		this->cantVidaG = this->cantVidaG - objD->get_FormaAtaque()->getCantDanioD();
	}

	if (this->getCantVidaG() > 0)
	{
		set_DragonesEliminados(1);
		objD->bajaDragon();
	}
	else if (objD->getVidaD() > 0)
		this->setEstadoG(false);
}

void cGuerrero::RelacionarseConDragon(cDragon* drgNuevo)
{
	if (drgNuevo->get_estado() == false)
		throw exception("Este Dragon esta muerto");
	else if (drgNuevo->get_domado() == true)
		throw exception("Este Dragon es bueno");
	else
	{
		this->TerminarDragon(drgNuevo);
	}
}

void cDragon::atacarDragon(cDragon *objD)
{//esta funcion mimebro del objeto X compara sus atributos con los de un dragon externo Y
	
	//creo dos iteradores, recorran ambas listas
	list<cFormaAtaque*>::iterator itObjP = objD->listaFA.begin();
	list<cFormaAtaque*>::iterator itObjL = this->listaFA.begin();
	//necesito crear metodo elegir forma ataque (elige de forma random). en getFA-> cambio
	bool flag = false;

	while (itObjP != this->listaFA.end()) 
	{

		if ((*itObjP)->get_danio() < (*itObjL)->get_danio()) //el objeto mas debil, pierde. se elimina respectiv.
		{	
			objD->bajaDragon();
			break;
		}
		else if ((*itObjP)->get_danio() > (*itObjL)->get_danio()) {
			this->bajaDragon();
			break;
		}
		itObjP++;
		itObjL++;
	}
	/*
	opciones - Tipos de exception.
	dragon no tenga forma ataque, no entra. 
	cambio de relacion entre D y FA -> COMPOSICION. Dragon nace con FA. Sino, alternativa para asignarla?
	*/
}

void cDragon::agregarFA(cFormaAtaque *objFA)
{
	//objeto llego con todas las caracteristicas aplicadas, desde entrenardragon, en jinete
	this->listaFA.push_back(objFA);
}

bool cDragon::get_domado()
{
	return this->domadoD;
}

unsigned int cDragon::getVidaD()
{
	return this->vidaD;
}

void cDragon::setVidaD(unsigned int vidaAct)
{
	this->vidaD = vidaAct;
}

void cDragon::bajaDragon()
{
	this->estadoD = false;
}

void cDragon::set_nombre(string nombre)
{
	this->nombreD = nombre;
}

eHabilidad cDragon::get_caracteristica()
{
	return this->caracteristicaD;
}

const int cDragon::getDragonID()
{
	return this->dragonID;
}

string cDragon::get_nombre()
{
	return this->nombreD;
}

eTamanio cDragon::get_tamanio()
{
	return this->tamanioD;
}

eColor cDragon::get_color()
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

cFormaAtaque* cDragon::get_FormaAtaque()
{
	return this->listaFA.back();
}

cDragon::~cDragon()
{
}
