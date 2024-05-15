#include "cJinete.h"

cJinete::cJinete(string nom, time_t fecha, string caracfisic)
{
    this->nombreJ = nom;
    this->fechaNac = fecha;;
    this->caractFisicasJ = caracfisic;
    this->apodoD = "";
    this->TrainResult = NoAsistio;
    this->dragon = nullptr;
}

cJinete::~cJinete()
{
}

string cJinete::get_nombreJ()
{
    return this->nombreJ;
}

void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    this->dragon = ptrDragon;
}

void cJinete::trabajarBerk()
{
    //AGARRANDO PALA?
}

void cJinete::atacarDragones()
{//atacandooooooooooooooooooooooooooooooooooooooo
}

void cJinete::domar()
{
    //domado te tienen dragon puto
}

eResultado cJinete::get_trainresult()
{
    return this->TrainResult;
}

string cJinete::get_apodo()
{
    return this->apodoD;
}

string cJinete::get_caracteristicas()
{
    return this->caractFisicasJ;
}

void cJinete::set_trainresult(eResultado resultado)
{
    this->TrainResult = resultado;
}
