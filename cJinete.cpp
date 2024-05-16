#include "cJinete.h"



cJinete::cJinete(string nom, time_t fecha, string caracfisic):cVikingo()
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
    domar();//le pone domado al drg
    this->dragon->entrenarDragon();//llama al metodo de dragon y lo entrena
}

void cJinete::trabajarBerk()
{
    //AGARRANDO PALA?
}

void cJinete::RelacionarseDragon()
{

}

void cJinete::domar()
{
    this->dragon->set_domado(true);
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
