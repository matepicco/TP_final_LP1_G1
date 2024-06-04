#include "cStoico.h"

int cStoico::cantVikCreados = 0;
int cStoico::cantDrgCreados = 0;

cStoico::cStoico()
{
	this->listaVikingos = list<cVikingo*>(); 
    this->listaDrgS = list<cDragon*>();
}

void cStoico::agregarVikingo(cVikingo* objV)
{
	this->listaVikingos.push_back(objV);
    cantVikCreados++;
}

void cStoico::agregarDragon(cDragon* objD)
{
    this->listaDrgS.push_back(objD);
    cantDrgCreados++;
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
    //Debe ir en un trycatch
    //Sobrecargar
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (nombre != (*it)->get_nombreV()) { // < o <= ???
        it++;
        if (it == this->listaVikingos.end()) {
            throw new exception("Error: No se encontro el vikingo");
        }
    }
    return *it;
}

cVikingo* cStoico::get_vikingoxPos(ePos pos)
{
    //Debe ir en un trycatch
    //Sobrecargar
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (pos != (*it)->get_posicionV()) {
        it++;
        if (it == this->listaVikingos.end()) {
            throw new exception("Error: No se encontro el vikingo");
        }
    }
    return *it;
}

void cStoico::eliminarDragon(cVikingo* objD)
{
}

void cStoico::mandarAatacar()
{
    //parametro objeto Dragon o stoico posee listaDragon. justificacion?
    if (listaVikingos.empty())
        throw exception("Lista vacia");
    else
    {
        list<cVikingo*>::iterator itV = this->listaVikingos.begin();
        while (itV != listaVikingos.end())
        {
            cJinete* ptrJ = dynamic_cast<cJinete*>(*(itV));
            if (ptrJ != nullptr)
            {
                ptrJ->RelacionarseConDragon(*(itV));
                // me hace mucho ruido. declarar el mismo vikingo (jinete) dos veces
            }
            else
            {
                list <cDragon*> ::iterator itObjD = listaDrgS.begin();
                for (itObjD; itObjD != listaDrgS.end(); itObjD++)
                {
                    cGuerrero* ptrG = dynamic_cast<cGuerrero*>(*(itV));
                    if (ptrG != nullptr)
                    {
                        //implementacion: guerrero pelea uno por uno con los dragones de la lista.
                        ptrG->RelacionarseConDragon(*(itV),(*itObjD));
                    }
                }
            }
        }
    }
}

int cStoico::getcantVikCreados()
{
	return cantVikCreados;
}

void cStoico::DragonesDomados()
{
}

void cStoico::JinetesxDragon()
{
}

cStoico::~cStoico()
{
}