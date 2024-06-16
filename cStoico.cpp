#include "cStoico.h"

int cStoico::cantVikCreados = 0;
int cStoico::cantDrgCreados = 0;
int cStoico::b = 0;

cStoico::cStoico()
{
    this->listaVikingos = list<cVikingo*>();
    this->listaDrgS = list<cDragon*>();
}

void cStoico::agregarVikingo(cVikingo* objV)
{
    this->listaVikingos.push_back(objV);
    cantVikCreados++;
    return;
}

void cStoico::agregarDragon(cDragon* objD)
{
    this->listaDrgS.push_back(objD);
    cantDrgCreados++;
    return;
}
void cStoico::agregarDrgXlista(list<cDragon*> lista, cDragon* drg)
{
    lista.push_back(drg);
    return;
}

void cStoico::eliminarDrgXlista(list<cDragon*> lista, cDragon* drg)
{
    list<cDragon*>::iterator it = lista.begin();
    bool borrado = false;
    while (it != lista.end())
    {
        if ((*it) == drg)
            lista.remove(*it);
        else
            it++;
    }

    if (!borrado)
        throw new exception("Error: No se encontro el vikingo");
    else
        return;
}

void cStoico::eliminarVikingo(cVikingo* objV)
//Este metodo tiene que ir en un catch porque tiene throw
{
    list<cVikingo*>::iterator it = this->listaVikingos.begin();
    bool borrado = false;

    while (it != this->listaVikingos.end() && !borrado)
    {
        cGuerrero* ptrG = dynamic_cast<cGuerrero*>(objV);
        if (ptrG != nullptr)
        {
            if ((*it) == ptrG)
            {
                this->listaVikingos.remove((*it));
                borrado = true;
            }
        }
        else 
        {
            cJinete* auxJine = dynamic_cast<cJinete*>(*it);
            if(auxJine!=nullptr)
            {
                if ((*it)->getVikiID() == objV->getVikiID())
                {
                    this->listaVikingos.remove(objV);
                    borrado = true;
                }
            }
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

    while (it != this->listaDrgS.end() && !borrado) 
    {
        if ((*it)==objD)
        {
            this->listaDrgS.remove(*it);
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
    //exception si ya existente
    agregarVikingo(objV);
    return;
}

void cStoico::operator+(cDragon* objD)
{    //exception
    agregarDragon(objD);
    return;
}

void cStoico::operator-(cVikingo* objV)
{//operator [], ==. si lo encuentra, lo elimina. sino exception
    if (objV != nullptr)
        eliminarVikingo(objV);
    else
        throw exception("Vacío");

    return;
}

void cStoico::imprimir()
{
    cout << this->to_string();
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

ostream& operator<<(ostream& out, cStoico* objS) {

    out << objS->to_string();
    return out;
}

string cStoico::to_string()
{
    stringstream ss;

    ss << "Cantidad de Vikingos: " << cStoico::cantVikCreados << ", cantidad de Dragones: " << cStoico::cantDrgCreados << endl;
    list<cVikingo*>::iterator itV = this->listaVikingos.begin(); 
    while (itV != listaVikingos.end()) {
        cJinete* jin = dynamic_cast<cJinete*>((*itV));
        ss << "El jinete es: ";
        ss << jin->toString()<<endl;
        ss << "El guerrero es: ";
        cGuerrero* guer = dynamic_cast<cGuerrero*>((*itV));
        ss << guer->toString() << endl;
        itV++;
    }
        return ss.str();
}

cVikingo* cStoico::get_vikingoxNom(string nombre)
{
    //Debe ir en un trycatch
    //Sobrecargar
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (nombre != (*it)->get_nombreV()) it++;

    if (it == this->listaVikingos.end()) {
        throw new exception("Error: No se encontro el vikingo");
    }
    return *it;
}

cVikingo* cStoico::get_vikingoxPos(ePos pos)//Tambien debe ir en un trycatch
{
    //Debe ir en un trycatch
    //Sobrecargar
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (pos != (*it)->get_posicionV()) it++;

    if (it == this->listaVikingos.end()) {
        throw new exception("Error: No se encontro el vikingo");
    }

    return *it;
}

void cStoico::crearInteraccion()
{
    if (!listaVikingos.empty())
    {
        list<cVikingo*>::iterator itV = this->listaVikingos.begin();
        list<cDragon*>::iterator itD = this->listaDrgS.begin();

        while (itV != listaVikingos.end())
        {
            while (itD != listaDrgS.end()) {

                bool flagRD = false;
                cJinete* ptrJ = dynamic_cast<cJinete*>(*(itV));
                if (ptrJ != nullptr)
                {
                    flagRD = ptrJ->RelacionarseConDragon((*itD));
                    list<cDragon*>::iterator itDaux = itD;
                    itDaux++;
                    ptrJ->manejarDragon(*itDaux,b);//esta b es porque hay que pasarle un indice para elegir un dragon
                    b++;
                    if (flagRD)//logró domarlo
                    {
                        agregarDrgXlista(listaDrgMatcheados, (*itD));
                        eliminarDrgXlista(listaDrgS, (*itD));
                    }
                    itD++;                    
                    break;
                }
                else
                {
                    cGuerrero* ptrG = dynamic_cast<cGuerrero*>(*(itV));
                    //No chequeo si es nullptr porque si no es jinete si o si es Guerrero
                        //implementacion: guerrero pelea uno por uno con los dragones de la lista.
                        flagRD = ptrG->RelacionarseConDragon((*itD));
                        if (flagRD)
                        {
                            agregarDrgXlista(listaDrgMatcheados, (*itD));
                            eliminarDrgXlista(listaDrgS, (*itD));
                        }
                        itD++;

                        list<cDragon*>::iterator itDaux2 = this->listaDrgS.begin();
                        itDaux2 = itD;
                        itD++;
                        ptrG->RelacionarseConDragon((*itDaux2));
                        agregarDrgXlista(listaDrgMatcheados,(*itDaux2));
                        eliminarDrgXlista(listaDrgS,(*itDaux2));
                        
                        break;
                }

            }
            itV++;
        }
    }
    else 
        throw exception("Lista vacia");
}

void cStoico::MandarAAtacar()
{

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