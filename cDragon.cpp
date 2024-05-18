#include "cDragon.h"

cDragon::cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord)
{
	this->nombreD = "";
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

		if ((*itObjP)->get_danio() < (*itObjL)->get_danio()) //el objeto mas debil, pierde. se elimina respectiv.
		{	
			objD->bajaDragon();//muere el dragon parametro, mas adelante vemos tema destructores
			flag = true;
			break;
		}
		else if ((*itObjP)->get_danio() > (*itObjL)->get_danio()) {
			this->bajaDragon();//muere el dragon actual, mas adelante vemos tema destructores
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
	eHabilidad habilidad = this->caracteristicaD;
	switch(habilidad){
	case ResisteFuego:
		this->get_FormaAtaque()->CambiarTipo(BolasFuego);
		if (this->tamanioD = Grande)
			this->get_FormaAtaque()->cambiarDanio(Mucho);
		else if (this->tamanioD = Mediano)
			this->get_FormaAtaque()->cambiarDanio(Moderado);
		else
			this->get_FormaAtaque()->cambiarDanio(Poco);
		break;
	case PatasLargas:
		this->get_FormaAtaque()->CambiarTipo(Araniar);
		if (this->tamanioD = Grande)
			this->get_FormaAtaque()->cambiarDanio(Mucho);
		else if (this->tamanioD = Mediano)
			this->get_FormaAtaque()->cambiarDanio(Moderado);
		else
			this->get_FormaAtaque()->cambiarDanio(Poco);
		break;
	case Rapidez:
		this->get_FormaAtaque()->CambiarTipo(Coletazo);
		if (this->tamanioD = Grande)
			this->get_FormaAtaque()->cambiarDanio(Mucho);
		else if (this->tamanioD = Mediano)
			this->get_FormaAtaque()->cambiarDanio(Moderado);
		else
			this->get_FormaAtaque()->cambiarDanio(Poco);
		break;
	case CuraFacil:
		this->get_FormaAtaque()->CambiarTipo(Curar);
		if (this->tamanioD = Grande)
			this->get_FormaAtaque()->cambiarDanio(Mucho);
		else if (this->tamanioD = Mediano)
			this->get_FormaAtaque()->cambiarDanio(Moderado);
		else
			this->get_FormaAtaque()->cambiarDanio(Poco);
		break;
	}
}

void cDragon::altaNombre()
{
	//de acuerdo a las caracteristicas, al dragon se le asigna un nombre
	if (this->caracteristicaD = ResisteFuego)
		this->nombreD = "Fueguin";
	else if (this->caracteristicaD =PatasLargas)
		this->nombreD = "El Patas";
	else if (this->caracteristicaD = Rapidez)
		this->nombreD = "Rapidrag";
	else
		this->nombreD = "Curita";
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
	return this->listaFA.front();//es el frente porque solo tiene uno por ahora entonces funca
}

cDragon::~cDragon()
{
}
