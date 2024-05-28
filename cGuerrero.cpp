#include "cGuerrero.h"

cGuerrero::cGuerrero()
{
	//debe declarar implementar el constructor del padre. to do
}

cGuerrero::cGuerrero(string nombrev, string apellidov, string posicionv)
{
	//debe declarar implementar el constructor del padre. to do
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
