#include "cGuerrero.h"

cGuerrero::cGuerrero(string nombreG, string apellidoG, string posicionG, unsigned int danioG):cVikingo()
{
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
	this->cantVidaG = cantVidaG - vidaAct;
}

void cGuerrero::RelacionarseConDragon(cDragon* objD)
{
	/*
	 metodo polimorfico. dispara el inicio de la interacción con dragon
	*/
	TerminarDragon(objD);

}

void cGuerrero::TerminarDragon(cDragon* objD)
{//vacia: implementada en cDragon (friend)
}

cGuerrero::~cGuerrero()
{
}
