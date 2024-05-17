#include "cJinete.h"



cJinete::cJinete(string nom, string ape, time_t fecha, string caracfisic):cVikingo(nom,ape,"")
{

    this->fechaNac = fecha;;
    this->caractFisicasJ = caracfisic;
    this->apodoD = "";
    this->TrainResult = NoAsistio;

    this->listaDragones = list<cDragon*>();
}

cJinete::~cJinete()
{
}

void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    this->listaDragones = ptrDragon;
    domar();//le pone domado al drg
    this->listaDragones->entrenarDragon();//llama al metodo de dragon y lo entrena
}

void cJinete::RelacionarseDragon()
{

}

void cJinete::domar()
{
    this->listaDragones->set_domado(true);
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

void cJinete::manejarDragon()
{
 //aca llama al metodo de atacar en el dragon q esta montando
}
