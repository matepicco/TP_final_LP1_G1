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
    list <cDragon*> ::iterator itD = lista.begin();
    bool agregado = true;
    while (itD != lista.end() && agregado)
    {
        if (*itD == drg)
            agregado = false;
        itD++;
    }

    if (!agregado)
        throw new exception("Error: dragon repetido");
    else
    {
        lista.push_back(drg);
        return;
    }
}

void cStoico::eliminarDrgXlista(list<cDragon*> lista, cDragon* drg)
{
    list<cDragon*>::iterator it = listaDrgS.begin();
    bool borrado = true;
    while (borrado && it != listaDrgS.end())
    {
        if ((*it) == drg)
            borrado = false;
        it++;
    }

    if (borrado)
        throw new exception("Error: No se encontro el dragon");
    else
    {
        lista.remove(*it);
        return;
    }
}

void cStoico::eliminarVikingo(cVikingo* objV)
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
    cout << this->toStringS();
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

    out << objS->toStringS();
    return out;
}

string cStoico::toStringS()
{
    stringstream ss;

    ss << "Cantidad de Vikingos: " << cStoico::cantVikCreados << ", cantidad de Dragones: " 
        << cStoico::cantDrgCreados << endl << endl;
    list<cVikingo*>::iterator itV = this->listaVikingos.begin();
    while (itV != listaVikingos.end()) {        
        cJinete* jin = dynamic_cast<cJinete*>((*itV));   
        cGuerrero* guer = dynamic_cast<cGuerrero*>((*itV));
        if(jin!=nullptr)
        {
            ss << "El jinete es: ";
            ss << jin->toStringJ() << endl;
        }
        else if(guer!=nullptr)
        {
            ss << "El guerrero es: ";
            ss << guer->toStringG() << endl;
        }
        itV++;
    }
        return ss.str();
}

cVikingo* cStoico::get_vikingoxNom(string nombre)
{
    //Debe ir en un trycatch
    //Sobrecargar
    list<cVikingo*>::iterator it = this->listaVikingos.begin();

    while (nombre != (*it)->get_nombreV()&&it!=listaVikingos.end()) it++;

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

    while (pos != (*it)->get_posicionV()&& it!= listaVikingos.end()) it++;

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
            this->b = 0;
            while (itD != listaDrgS.end()) 
            {
                bool flagRD = false;
                cJinete* ptrJ = dynamic_cast<cJinete*>(*(itV));
                if (ptrJ != nullptr)
                {
                    flagRD = ptrJ->RelacionarseConDragon((*itD));

                    if (flagRD)//logró domarlo
                    {
                        /*
                        try
                        {
                            agregarDrgXlista(listaDrgMatcheados, (*itD));
                            eliminarDrgXlista(listaDrgS, (*itD));
                        }
                        catch (exception *e)
                        {
                            cout << e->what() << endl;
                        }
                        */
                        listaDrgMatcheados.push_back((*itD));
                        try
                        {
                            ptrJ->manejarDragon((*itD), b);
                            //esta b es porque hay que pasarle un indice para elegir un dragon
                            b++;
                        }
                        catch (exception& e)
                        {
                            cout << e.what() << endl;
                        }
                        itD = listaDrgS.erase(itD);
                    }
                    else
                        itD++;
                }
                else
                {
                    cGuerrero* ptrG = dynamic_cast<cGuerrero*>(*(itV));
                    //No chequeo si es nullptr porque si no es jinete si o si es Guerrero
                    //ojo q el null puede ser por no haber objetos en lista
                    //implementacion: guerrero pelea uno por uno con los dragones de la lista.
                        flagRD = ptrG->RelacionarseConDragon((*itD));
                        if (flagRD)
                        {
                            itD=listaDrgS.erase(itD);
                            /*
                            try
                            {
                                eliminarDrgXlista(listaDrgS, (*itD));
                            }
                            catch (exception* e)
                            {
                                cout << e->what() << endl;
                            }
                            */
                        }
                        else
                        itD++;
                }
                break;
            }
            itV++;
        }
    }
    else 
        throw exception("Lista vacia");
}

void cStoico::MandarAAtacar()
{
    //particularizar
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