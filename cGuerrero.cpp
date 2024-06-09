#include "cGuerrero.h"

cGuerrero::cGuerrero(string nombreG, string apellidoG, eCaract caracfisic, unsigned int danioG):cVikingo(nombreG,apellidoG,caracfisic)
{//tira verde porque cantDanioG esta dentro del trycatch
	this->cantVidaG = 100;
	this->estadoG = true;
	try {
		if (danioG < 100)
			this->cantDanioG = danioG;
		else
			throw invalid_argument("Cantidad Danio Invalido");
	}
	catch (const invalid_argument &e)
	{
		cout << e.what() << endl;
		cout << "Vuelva a ingresar una cantidad de danio menor a 100" << endl;
	}
}

unsigned int cGuerrero::getCantDanioG()
{
	return this->cantDanioG;
}

unsigned int cGuerrero::getCantVidaG()
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

bool cGuerrero::RelacionarseConDragon(cDragon* objD)
{//implementado en cDragon
}

bool cGuerrero::TerminarDragon(cDragon* objD)
{//implementada en cDragon (friend)
}

string cGuerrero::toString()
{
	//imprimo lo del hijo,padre
	stringstream ss;

	ss << this->nombreV << "" << this->apellidoV << "" << this->posicion << "" << this->caractFisicasV << ""
		<< this->posicion << "" << this->caractFisicasV << "" << this->DragonesEliminados << endl;

	return ss.str();
}

cGuerrero::~cGuerrero()
{
}
