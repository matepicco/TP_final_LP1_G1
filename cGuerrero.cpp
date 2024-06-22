#include "cGuerrero.h"

cGuerrero::cGuerrero(string nombreG, string apellidoG, eCaract caracfisic, unsigned int danioG):cVikingo(nombreG,apellidoG,caracfisic)
{//tira verde porque cantDanioG esta dentro del trycatch
	this->cantVidaG = 100;
	this->estadoG = true;

	if (danioG <= 0)
		this->cantDanioG = 20;
	if (danioG >= 100)
		this->cantDanioG = 80;
	else if (danioG >= 0 || danioG < 100)
		this->cantDanioG = danioG;

}

unsigned int cGuerrero::getCantDanioG()
{
	return this->cantDanioG;
}

int cGuerrero::getCantVidaG()
{
	return this->cantVidaG;
}

void cGuerrero::setEstadoG(bool VM)
{
	this->estadoG = VM;
}

void cGuerrero::setCantDanioG(unsigned int danioAct)
{
	this->cantDanioG = danioAct;
}

void cGuerrero::setCantVidaG(unsigned int vidaAct)
{
	this->cantVidaG = vidaAct;
}

string cGuerrero::toStringG()
{
	stringstream ss;

	ss << this->nombreV << " " << this->apellidoV << ". Trabaja de: " << this->enumPtostring() << " y su caracteristica fisica es: " << this->enumCtostring() << ". Tiene " <<
	this->DragonesEliminados <<"dragones eliminados" << endl;

	return ss.str();
}

cGuerrero::~cGuerrero()
{
}
