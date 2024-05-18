#include "cDragon.h"

cDragon::cDragon(string nombred, eHabilidad caracteristicad, string tamaniod, string colord)
{
	this->nombreD = nombred;
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = true;
	this->domadoD = false;

	this->listaFA = list<cFormaAtaque*>();
}

void cGuerrero::TerminarDragon(cDragon* objD, cGuerrero* objG)
{
	/*
	* constará de un enfrentamiento entre dragon y vikingo: contrastará las habilidades y deb
	* más desarrollado aún: bajen la vida,segun danio,acabe el enfrentamiento y vivan los dos...
	*/
	objD->set_estado(false);
	objG->set_DragonesEliminados(1);

}

void cDragon::atacarDragon(cDragon *objD)
{//esta funcion mimebro de el objeto X compara sus atributos con los de un dragon externo Y
	
	//creo dos iteradores, recorran ambas listas
	list<cFormaAtaque*>::iterator itObjP = objD->listaFA.begin();
	list<cFormaAtaque*>::iterator itObjL = this->listaFA.begin();
	bool flag = false;

	while (itObjP != this->listaFA.end()) 
	{

		if ((*itObjP)->get_danio() <= (*itObjL)->get_danio()) //el objeto mas debil, pierde. se elimina respectiv.
		{	
			//accedo al jinete y con un set cambio el atb del objeto dEliminados.
			flag = true;
			break;
		}
		itObjP++;
		itObjL++;

	}

	/*
	opciones - Tipos de exception.
	dragon no tenga forma ataque, no entra.
	una llega al final antes q la otra, se dejan FA sin comparar
	*/
	if (!flag) {
		throw new exception("Error: Tie");
	}
}

void cDragon::entrenarDragon()
{
	//lista de ifs que ven su habilidad y de acuerdo a esta establecen la forma de ataque
	//es lineal, digamos una habilidad va a una forma de ataque
}

void cDragon::altaNombre()
{//de acuerdo a las caracteristicas o ataque, al dragon se le asigna un nombre
}

bool cDragon::get_domado()
{
	return this->domadoD;
}

void cDragon::bajaDragon()//(setter) llamado cuando dragon eliminado
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
