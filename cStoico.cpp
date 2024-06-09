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

    while (it !=lista.end() && !borrado) {

        if ((*it) == drg) //compara atb 1x1 
        {
            lista.remove(drg);
            borrado = true;
        }
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
//este metodo puede impleemtnar sobrecarga ==
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
        else //if (ptrG == nullptr)//es jinete
        {
            if ((*it) == objV)//imposible == lista de Jinete, entonces NECESITO identificador TODO
            {
                this->listaVikingos.remove(objV);
                borrado = true;
            }
        }

        /*
        if ((*it)->get_nombreV() == objV->get_nombreV()) 
        {//tendría que ASEGURAR q no se repiten nombres
         // imposible: usuario ingresa lo que quiere
            this->listaVikingos.remove(objV);
            borrado = true;
        }

        */
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

    while (it != this->listaDrgS.end() && !borrado) {
        
        //TODO sobrecarga ==
        if ((*it)==objD) //compara atb 1x1 
        {
            this->listaDrgS.remove(objD);
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
    return;
}

void cStoico::operator+(cDragon* objD)
{    //chequeo si ya existe en la lista. exception
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
    ss << "El jinete es: ";
    while (itV != listaVikingos.end()) {
        cJinete* jin = dynamic_cast<cJinete*>((*itV));
        ss << jin->toString()<<endl;
        ss << "El guerrero es: ";
        cGuerrero* guer = dynamic_cast<cGuerrero*>((*itV));
        ss << guer->toString() << endl;
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

void cStoico::mandarAentrenar()
{
    return;
}

void cStoico::crearInteraccion()
{
    if (!listaVikingos.empty())
    {
        list<cVikingo*>::iterator itV = this->listaVikingos.begin();
        list<cDragon*>::iterator itD = this->listaDrgS.begin();
        //bool flag = true; eliminada: que función?
        //metodo interaccion: simulacion completa

        while (itV != listaVikingos.end())
        {
            while (itD != listaDrgS.end()) {

                bool flagRD = false;
                cJinete* ptrJ = dynamic_cast<cJinete*>(*(itV));
                if (ptrJ != nullptr)
                {
                    flagRD = ptrJ->RelacionarseConDragon((*itD));
                    if (flagRD)//logró domarlo
                    {
                        agregarDrgXlista(listaDrgMatcheados, (*itD));//agrego el match a la de dragones matcheados
                        eliminarDrgXlista(listaDrgS, (*itD));//elimino el que use de la lista comun, que siempre es el primero que 
                    }
                    itD++;
                }
                else {
                    cGuerrero* ptrG = dynamic_cast<cGuerrero*>(*(itV));
                    if (ptrG != nullptr)
                    {
                        //implementacion: guerrero pelea uno por uno con los dragones de la lista.
                        flagRD = ptrG->RelacionarseConDragon((*itD));
                        if (flagRD)
                        {
                            agregarDrgXlista(listaDrgMatcheados, (*itD));
                            eliminarDrgXlista(listaDrgS, (*itD));
                        }
                        itD++;
                    }
                }

            }
            itV++;
        }
    }
    else 
        throw exception("Lista vacia");

    return;
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

//operator << no miembro
/*
//caso no miembro de cStoico. pero permite acceso desde main. xq incluido en archivo cStoico.h
ostream& operator<<(cVikingo* objV, cStoico *objS)
{
    // TODO: insert return statement here
}
*/

/*
//ostream& operator<<(ostream& out, cVikingo* objV)
// // Es una forma de hacerlo pero se me ocurrio que podia ser como esta abajo
//{
//    //ocurro llamo a toString de guerrero y jinete
//    //chequeo listas no vacias. exception (o desde donde uso los <<
//    //chequear metodo listar de matilarro
//    cGuerrero* objG = dynamic_cast<cGuerrero*>(objV);
//    if (objG != nullptr)
//    {
//        out << objG->to_string() << endl;
//    }
//    else
//    {
//        cJinete* objJ = dynamic_cast<cJinete*>(objV);
//        if (objJ != nullptr)
//        {
//            out << objJ->to_string() << endl;
//        }
//    }
//    return out;
//}
*/