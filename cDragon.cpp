#include "cDragon.h"

int cDragon::dragonesCreados = 0;

cDragon::cDragon(eHabilidad caracteristicad, eTamanio tamaniod, eColor colord): dragonID(dragonesCreados)
{
	this->nombreD = "";
	this->caracteristicaD = caracteristicad;
	this->tamanioD = tamaniod;
	this->colorD = colord;
	this->estadoD = true;
	this->domadoD = false;
	this->vidaD = 100;
	
	this->listaFA = list<cFormaCombate*>();
	dragonesCreados++;
}

string cDragon::enumColorTostring()
{
	switch (this->colorD)
	{
	case Rojo:
		return "Rojo";
	case Negro:
		return "Negro";
	case Azul:
		return "Azul";
	case Naranja:
		return "Naranja";
	case Verde:
		return "Verde";
	case Blanco:
		return "Blanco";
	}
}

string cDragon::estadoToString()
{
	switch (this->estadoD)
	{
	case 0:
		return "Muerto";
	case 1:
		return "Vivo";
	}
}

string cDragon::domadoToString()
{
	switch (this->domadoD)
	{
	case 0:
		return "Libre";
	case 1:
		return "Domado";
	}
}

string cDragon::enumTamTostring()
{
	switch (this->tamanioD)
	{
	case Grande:
		return "Grande";
	case Mediano:
		return "Mediano";
	case Chico:
		return "Chico";
	}
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
	}
	return flag;
}

void cDragon::operator+(cFormaCombate *FC)
{
	agregarFA(FC);
}

void cDragon::FAfuerteAdelante()
{
	//metodo available para dragones pertenecientes a jinete
	if (this->domadoD != true)
		return;

	list<cFormaCombate*>::iterator itFA = this->listaFA.begin();
	bool flag = true;
	unsigned int maxDanio = 0;

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
}

list<cFormaCombate*> cDragon::getListFA()
{
	return this->listaFA;
}

void cDragon::ordenarFAsalvajes(cDragon* objD)
{	
	//dragon salvaje
	//metodo ordena todas las defensas atras, ataques adelante
	if (objD->domadoD == false)
	{	
		list <cFormaCombate*> ::iterator itFC = objD->listaFA.begin();
		list <cFormaCombate*> ::iterator itFC1 = objD->listaFA.end();

		while (itFC != objD->listaFA.end())
		{
			if (dynamic_cast<cAtaque*>(*itFC) != nullptr)
			{
				objD->listaFA.push_front(*itFC);
				//si 2 FC: defensa queda en back: segundo
			}
			else if (dynamic_cast<cDefensa*>(*itFC) != nullptr)
			{
				objD->listaFA.splice(itFC, listaFA, itFC1);
			}
			itFC++;
		}

	}
	return;
}

bool cGuerrero::PelearDragon(cDragon* objD)
{
	bool terminado = false;
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
			this->cantVidaG = this->cantVidaG - objD->getListFA().front()->getCantDanioD();//agarra el frente porque es el del ataque
			break;
		}
	}

	if (this->cantVidaG > 0)
	{
		set_DragonesEliminados(1);
		objD->bajaDragon();
		terminado =!terminado;
	}
	else if (objD->getVidaD() > 0)
		this->setEstadoG(false);

	return terminado;
}

bool cGuerrero::RelacionarseConDragon(cDragon* drgNuevo)
{
	bool terminado = false;
	if (drgNuevo->get_estado() == false || drgNuevo->get_domado() == true)
		return terminado;
	else
		terminado = this->PelearDragon(drgNuevo);
	return terminado;
}

void cDragon::atacarDragon(cDragon* objD)
{
	this->FAfuerteAdelante();
	/*
	* mueve el ataque de mas intensidad al principio
	*ordenarFAsalvajes(objD);//Envia a la forma de ataque adelante
	*dragones salvajes tienen Ataque primero, defensa segundo por el metodo de arriba
	*/

	list <cFormaCombate*> ::iterator itFA = listaFA.begin();
	while ((objD->getVidaD() > 0) && ((this->getVidaD()) >= 0))
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 1);
		int numAleato = dis(gen);
		switch (numAleato)
		{
			case 0:
			{
				//ataca solo domado
				//chequeo nerf de ataque
				cAtaque* ataAux = dynamic_cast<cAtaque*>((*itFA));
				cDefensa* defObj = dynamic_cast<cDefensa*>(objD->getListFA().back());

				if (ataAux != nullptr && defObj != nullptr)
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
			}
			case 1://ataca solo salvaje
			{
				bool flagDef = true;
				list <cFormaCombate*> ::iterator itFAD = listaFA.begin();
				while (itFAD != listaFA.end() && flagDef) {
					cDefensa* def = dynamic_cast<cDefensa*>(*itFAD);
					if (def != nullptr)
						flagDef=false;
					else
						itFAD++;
				}

				bool flagAta = true;
				list <cFormaCombate*> ::iterator itFA = objD->listaFA.begin();
				while (itFA != objD->listaFA.end() && flagAta) {
					cAtaque* ata = dynamic_cast<cAtaque*>(*itFA);
					if (ata != nullptr)
						flagAta = false;
					else
						itFA++;
				}
				cDefensa* defAux = dynamic_cast<cDefensa*>(*itFAD);
				cAtaque* ataObj = dynamic_cast<cAtaque*>(*itFA);

				if (defAux != nullptr)
				{
					//cuando encuentro ataque y defensa equivalente: varío la cantidad daño aplicada
					if (ataObj->getTipoAtaque() == BolasFuego && defAux->getTipoDefensa() == ResisteFuego)
					{
						this->vidaD = (vidaD - ataObj->getCantDanioD() / 2);
						itFA++;
						break;
					}
					else if (ataObj->getTipoAtaque() == Araniar && defAux->getTipoDefensa() == EscamasResistentes)
					{
						this->vidaD = (vidaD - ataObj->getCantDanioD() / 2);
						itFA++;
						break;
					}
					else if (ataObj->getTipoAtaque() == Coletazo && defAux->getTipoDefensa() == Rapidez)
					{
						this->vidaD = (vidaD - ataObj->getCantDanioD() / 2);
						itFA++;
						break;
					}
					else if (ataObj->getTipoAtaque() == Mordidita && defAux->getTipoDefensa() == ArmaduraDrg)
					{
						this->vidaD = (vidaD - ataObj->getCantDanioD() / 2);
						itFA++;
						break;
					}
					else
						this->vidaD = (vidaD - ataObj->getCantDanioD());
					break;
				}
			}
		}
	}

	if (this->vidaD <= 0) {
		this->estadoD = false;
	}
	else if (objD->getVidaD() <= 0)
		objD->set_estado(false);
}

string cDragon::toStringD()
{		
	stringstream ss;
	ss << endl << this->nombreD << ", de ID: " << this->dragonID << ", carcaterizado como: "
		<< this->enumHTostring() << ", de color: " << this->enumColorTostring() << " y tamanio: "
		<< this->enumTamTostring() << endl << "Se encuentra: " << estadoToString() << " y " 
		<< this->domadoToString() << " con un nivel de "<< this->vidaD << " de vida " << endl;
	
	list<cFormaCombate*>::iterator itFA = listaFA.begin();
	while (itFA != listaFA.end()) {
		cAtaque* ata = dynamic_cast<cAtaque*>(*itFA);
		cDefensa* def = dynamic_cast<cDefensa*>(*itFA);
		if(ata != nullptr)
			ss << (*itFA)->toStringFA() << endl;
		else
			ss << (*itFA)->toStringFA() << endl;
		itFA++;
	}
	return ss.str();
}

string cDragon::enumHTostring()
{
	switch (this->caracteristicaD)
	{
	case Fogoso:
		return "Fogoso";
	case Garras:
		return "Garras";
	case Colilargo:
		return "Colilargo";
	case Dientes:
		return "Dientes";
	}
}

void cDragon::agregarFA(cFormaCombate *objFA)
{
	this->listaFA.push_back(objFA);
}

bool cDragon::get_domado()
{
	return this->domadoD;
}

int cDragon::getVidaD()
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

cFormaCombate* cDragon::get_FormaCombateXIndice(int i)
{
	list<cFormaCombate*>::iterator it = listaFA.begin();
	int a = 0;
	while (it != listaFA.end()&& a<i) {
		it++;
		a++;
	}
	return (*it);
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