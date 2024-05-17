#include "cStoico.h"

int cStoico::cantVikCreados = 0;

cStoico::cStoico()
{
	this->listaVikingos = list<cVikingo*>(); 
}

void cStoico::agregarVikingo(cVikingo* objV)
{
	this->listaVikingos.push_back(objV);
    cantVikCreados++;
}

void cStoico::eliminarVikingo(cVikingo* objV)//Este metodo tiene que ir en un catch porque tiene throw
{
    list<cVikingo*>::iterator it = this->listaVikingos.begin();
    bool borrado = false;

    while (it != this->listaVikingos.end()) {

        if ((*it)->get_nombreV() == objV->get_nombreV()) {
            this->listaVikingos.erase(it);
            borrado = true;
            break;
        }
        it++;
    }

    if (!borrado) {
        throw new exception("Error: No se encontro el vikingo");
    }

    this->cantVikCreados--;
}

cVikingo* cStoico::get_vikingoxNom(string nombre)
{
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (nombre != (*it)->get_nombreV()) { // < o <= ???
        it++;
        if (it == this->listaVikingos.end()) {
            throw new exception("Error: No se encontro el vikingo");
        }
    }
    return *it;
}

cVikingo* cStoico::get_vikingoxPos(string pos)//Tambien debe ir en un trycatch
{
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (pos != (*it)->get_posicionV()) {
        it++;
        if (it == this->listaVikingos.end()) {
            throw new exception("Error: No se encontro el vikingo");
        }
    }
    return *it;
}

int cStoico::getcantVikCreados()
{
	return cantVikCreados;
}

cStoico::~cStoico()
{
}