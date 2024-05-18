#include "cJinete.h"

cJinete::cJinete(string nom, string ape, time_t fecha, string caracfisic):cVikingo(nom,ape,"")
{
    //debe declarar implementar el constructor del padre. to do
    this->fechaNac = fecha;;
    this->caractFisicasJ = caracfisic;
    this->TrainResult = NoAsistio;
    //el apodo se lo asignará gracias al dragon que dome. inicializado en cVikingo

    this->listaDragones = list<cDragon*>();
}

void cJinete::trabajarEnBerk()
{
    string descrip;
    //posicion asignada segun caracteristicas u otro factor determinante
   if(descrip==get_caractFisicasJ())
    set_posicionV("tal");
}

void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    //lo incorpora, setea el domado y lo entrena
    this->listaDragones.push_back(ptrDragon);
    domar(ptrDragon);//settea domado al drg
    ptrDragon->entrenarDragon();//llama al metodo de dragon y lo entrena. jinete fluye hacia dragon
    this->TrainResult = Aprobado;
    //mas adelante, organizamos los otros tipos de resultado.
    //una vez ingresado en la lista de dragones, lo manejamos con los comandos respectivos
}

void cJinete::RelacionarseConDragon()
{
    /*
    * metodo polimorfico. dispara el inicio de la interacción con dragon
    * primer contacto con el dragon, evalua si es domable, si es, llama a incorporar
    * compara caract del jinete con las del dragon, a ver si son compatibles
    */
}

void cJinete::domar(cDragon* ptrDragon)
{
    ptrDragon->set_domado(true);
}

void cJinete::manejarDragon()
{
    /*
        llama al metodo de atacar en el dragon q esta montando
        dispara el metodo de dragon que ataca a otro
        recorre la lista para chequear que dragon maneja y fluye hacia cDragon
    */
}

eResultado cJinete::get_trainresult()
{
    return this->TrainResult;
}

string cJinete::get_apodoJ()
{
    return this->apodoJ;
}

string cJinete::get_caractFisicasJ()
{
    return this->caractFisicasJ;
}

void cJinete::set_trainresult(eResultado resultado)
{
    this->TrainResult = resultado;
}

cJinete::~cJinete()
{
}
