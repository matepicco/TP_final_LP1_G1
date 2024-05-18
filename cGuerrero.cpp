#include "cGuerrero.h"

cGuerrero::cGuerrero()
{
	//debe declarar implementar el constructor del padre. to do
}

cGuerrero::cGuerrero(string nombrev, string apellidov, string posicionv)
{
	//debe declarar implementar el constructor del padre. to do
}

void cGuerrero::RelacionarseConDragon(cDragon* objD, cGuerrero* objG)
{
	/*
	 metodo polimorfico. dispara el inicio de la interacción con dragon
	*/
	TerminarDragon(objD, objG);

}

void cGuerrero::TerminarDragon(cDragon* objD, cGuerrero* objG)
{//vacia: implementada en cDragon (friend)
}

cGuerrero::~cGuerrero()
{
}
