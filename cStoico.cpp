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

void cStoico::eliminarVikingo(cVikingo* objV)
//Este metodo tiene que ir en un catch porque tiene throw
//este metodo puede impleemtnar sobrecarga ==
{
    list<cVikingo*>::iterator it = this->listaVikingos.begin();
    bool borrado = false;

    while (it != this->listaVikingos.end())
    {
        //opcion dynamic cast
        cGuerrero* ptrG = dynamic_cast<cGuerrero*>(objV);
        if (ptrG != nullptr)
        {
            if ((*it) == ptrG)
            {//no esperaba lo acepte pero... (comparo vikingo con guerrero)
                this->listaVikingos.remove((*it));
                borrado = true;
            }
        }
        else //if (ptrG == nullptr)//es jinete
        {
            if ((*it) == objV)//imposible == lista de Jinete, entonces NECESITO identificador
            {
                this->listaVikingos.remove(objV);
                borrado = true;
            }
        }

        //otra forma, poco precisa
        if ((*it)->get_nombreV() == objV->get_nombreV()) 
        {//tendría que ASEGURAR q no se repiten nombres
         // imposible: usuario ingresa lo que quiere
            this->listaVikingos.remove((*it)); //erase se usa para borrar la lista integra
            this->listaVikingos.remove(objV); //erase se usa para borrar la lista integra
            //decidir con cual de los dos quedarse.
            borrado = true;
        }

        it++;
    }

    if (!borrado)
        throw new exception("Error: No se encontro el vikingo");
    else
        this->cantVikCreados--;

    return;
}

void cStoico::eliminarDragon(cDragon* objD)
{
    list<cDragon*>::iterator it = this->listaDrgS.begin();
    bool borrado = false;

    while (it != this->listaDrgS.end()) {

        if ((*it)==objD) //compara atb 1x1 
        {
            this->listaDrgS.remove((*it)); //erase se usa para borrar la lista integra
            this->listaDrgS.remove(objD); //erase se usa para borrar la lista integra
            //decidir con cual de los dos quedarse. yo elijo  objD
            borrado = true;
        }
        else
            it++;
    }

    if (!borrado) {
        throw new exception("Error: No se encontro el vikingo");
    }
    else
        this->cantDrgCreados--;
    return;
}

void cStoico::operator+(cVikingo* objV)
{
    //chequeo si ya existe en la lista. exception
    agregarVikingo(objV);
}

void cStoico::operator+(cDragon* objD)
{    //chequeo si ya existe en la lista. exception
    agregarDragon(objD);
}

void cStoico::operator-(cVikingo* objV)
{//operator [], ==. si lo encuentra, lo elimina. sino exception
    if (objV != nullptr)
        eliminarVikingo(objV);
    else
        throw exception("Vacío");

    return;
}

void cStoico::operator-(cDragon* objD)
{///operator [], ==. si lo encuentra, lo elimina. sino exception
    if (objD != nullptr)
        eliminarDragon(objD);
    else
        throw exception("Vacío");

    return;
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

cVikingo* cStoico::get_vikingoxPos(ePos pos)//Tambien debe ir en un trycatch
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

void cStoico::mandarAentrenar()
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