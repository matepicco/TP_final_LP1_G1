#include "cDragon.h"

int cDragon::dragonesCreados = 0;

cDragon::cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord): dragonID(dragonesCreados)
{
	//paso x parametro FA, igualo al parametro. sobrecargo en main 
	this->nombreD = "";
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = true;
	this->domadoD = false;
	this->vidaD = 100;

	//plantear dos opciones
	/*
	cFormaAtaque* at1= objA(Resistente);
	this->listaFA = listaFA.push_back(at1)
	
	this->listaFA = list<cFormaAtaque*>();
	*/
	dragonesCreados++;
}

bool cDragon::operator==(cDragon& drg)
{
	bool flag = false;
	if (this->nombreD == drg.nombreD && this->dragonID == drg.dragonID) {
		if (this->caracteristicaD == drg.caracteristicaD && this->dragonesCreados == drg.dragonesCreados)
			if (this->tamanioD == drg.tamanioD && this->colorD == drg.colorD) {
				if (this->estadoD == drg.estadoD && this->domadoD == drg.domadoD)
					flag = true;
			}
		return flag;
	}
}

void cDragon::getFAfuerte()
{
	//metodo available para dragones pertenecientes a jinete
	if (this->domadoD != true)
		return;

	list<cFormaAtaque*>::iterator itFA = this->listaFA.begin();
	bool flag = true;
	int maxDanio = 0;

	while (itFA != listaFA.end())
	{
		cAtaque* fAtaque = dynamic_cast<cAtaque*>(*itFA);
		if (fAtaque != nullptr)
		{
			if (maxDanio < (*itFA)->getCantDanioD())
			{
				maxDanio = (*itFA)->getCantDanioD();
				listaFA.push_front(*itFA);
			}
		}
		itFA++;
	}
	return;
}

list<cFormaAtaque*> cDragon::getListFA()
{
	return this->listaFA;
}

void cDragon::ordenarFAsalvajes(cFormaAtaque* objFA)
{
	//dragon salvaje
	if (this->domadoD != true)
	{
		if (dynamic_cast<cAtaque*>(objFA) != nullptr)
		{
			listaFA.push_front(objFA);
			//defensa queda en back: segundo
		}
	}
	return;
}

bool cGuerrero::TerminarDragon(cDragon* objD)
{
	bool terminado = false;
	//double check: innecesario? Solo necesario si ejecuto directo este metodo
	if (objD->get_estado() == false)
		throw exception("Este Dragon esta muerto");
	else if (objD->get_domado() == true)
		throw exception("Este Dragon es bueno");

	while (this->cantVidaG > 0 && objD->getVidaD() > 0)
	{	
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 1);
		int numAleato = dis(gen);
	
		switch (numAleato)
		{
		case 0: //ataca solo guerrero
			objD->setVidaD(objD->getVidaD() - this->getCantDanioG());
			break;
		case 1: //ataca solo dragon
			this->cantVidaG = this->cantVidaG - objD->getListFA().front()->getCantDanioD();
			break;
		}
	}

	if (this->getCantVidaG() > 0)
	{
		set_DragonesEliminados(1);
		objD->bajaDragon();
		!terminado;
		//pendiente: metodo que llame, dependiendo el return 
		//settea dragon muerto en listaDraognes muertos
	}
	else if (objD->getVidaD() > 0)
		this->setEstadoG(false);

	return terminado;
}

bool cGuerrero::RelacionarseConDragon(cDragon* drgNuevo)
{
	bool terminado = false;
	if (drgNuevo->get_estado() == false)
		throw exception("Este Dragon esta muerto");
	else if (drgNuevo->get_domado() == true)
		throw exception("Este Dragon es bueno");
	else
		terminado = this->TerminarDragon(drgNuevo);
	return terminado;
}

void cDragon::atacarDragon(cDragon * objD)
{
	this->getFAfuerte(); //retorna ataque mayor intensidad al principio
	ordenarFAsalvajes(objD->getListFA().front());
	//dragones salvajes tienen Ataque primero, defensa segundo

	list <cFormaAtaque*> ::iterator itFA = listaFA.begin();
	while (objD->getVidaD() > 0 || this->getVidaD() > 0)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 1);
		int numAleato = dis(gen);
		switch (numAleato)
		{
		case 0:
			//ataca solo domado
			//chequeo nerf de ataque
			cAtaque* ataAux = dynamic_cast<cAtaque*>((*itFA));
			cDefensa* defObj = dynamic_cast<cDefensa*>(objD->getListFA().back());

			if (ataAux != nullptr && defObj !=nullptr)
			{
				//cuando encuentro ataque y defensa equivalente: varío la cantidad daño aplicada
				if (ataAux->getTipoAtaque() == BolasFuego && defObj->getTipoDefensa() == ResisteFuego)
				{
					objD->setVidaD(objD->getVidaD() - this->listaFA.front()->getCantDanioD() / 2);
					itFA++;
					break;
				}
				else if (ataAux->getTipoAtaque() == Araniar && defObj->getTipoDefensa() == EscamasResistentes)
				{
					objD->setVidaD(objD->getVidaD() - this->listaFA.front()->getCantDanioD() / 2);
					itFA++;
					break;
				}
				else if (ataAux->getTipoAtaque() == Coletazo && defObj->getTipoDefensa() == Rapidez)
				{
					objD->setVidaD(objD->getVidaD() - this->listaFA.front()->getCantDanioD() / 2);
					itFA++;
					break;
				}
				else if (ataAux->getTipoAtaque() == Mordidita && defObj->getTipoDefensa() == ArmaduraDrg)
				{
					objD->setVidaD(objD->getVidaD() - this->listaFA.front()->getCantDanioD() / 2);
					itFA++;
					break;
				}
				else
					objD->setVidaD(objD->getVidaD() - this->listaFA.front()->getCantDanioD());
				break;
			}
		case 1://ataca solo salvaje
			list <cFormaAtaque*> ::iterator itFAD = listaFA.begin();
			while (itFAD != listaFA.end()) {
				cDefensa* def = dynamic_cast<cDefensa*>(*itFAD);
				if (def != nullptr)
					break;
				itFAD++;
			}

			cDefensa * defAux = dynamic_cast<cDefensa*>((*itFAD));
			cAtaque* ataObj = dynamic_cast<cAtaque*>(objD->getListFA().front());

			if (defAux != nullptr)
			{
				//cuando encuentro ataque y defensa equivalente: varío la cantidad daño aplicada
				if( ataObj->getTipoAtaque() == BolasFuego && defAux->getTipoDefensa() == ResisteFuego)
				{
					this->vidaD = (vidaD - ataObj->getCantDanioD()/2);
					itFA++;
					break;
				}
				else if (ataObj->getTipoAtaque() == Araniar && defAux->getTipoDefensa() == EscamasResistentes)
				{
					this->vidaD = (vidaD - ataObj->getCantDanioD()/2);
					itFA++;
					break;
				}
				else if (ataObj->getTipoAtaque() == Coletazo && defAux->getTipoDefensa() == Rapidez)
				{
					this->vidaD = (vidaD - ataObj->getCantDanioD()/2);
					itFA++;
					break;
				}
				else if (ataObj->getTipoAtaque() == Mordidita && defAux->getTipoDefensa() == ArmaduraDrg)
				{
					this->vidaD = (vidaD - ataObj->getCantDanioD()/2);
					itFA++;
					break;
				}
				else
					this->vidaD=(vidaD - ataObj->getCantDanioD());
				break;
			}

		}
	}

		/*
		cambio de relacion entre D y FA -> COMPOSICION. Dragon nace con FA. Sino, alternativa para asignarla?
		Drg nace con ataque y defensa. ambas dos. todos drg sobrecargados salvajes tambien.
		*/
}

void cDragon::agregarFA(cFormaAtaque *objFA)
{
	//proviene de entrenarDrg
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

cDragon::~cDragon()
{
}