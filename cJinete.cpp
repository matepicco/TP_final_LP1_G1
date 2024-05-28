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

void cJinete::RelacionarseConDragon()// esta esta rara, eliminable
{
    /*
    * metodo polimorfico. dispara el inicio de la interacción con dragon
    * primer contacto con el dragon, evalua si es domable, si es, llama a incorporar
    * compara caract del jinete con las del dragon, a ver si son compatibles
    */
}

void cJinete::domar()
{
    this->listaDragones.back()->set_domado(true);
}

void cJinete::manejarDragon()
{
    /*
        llama al metodo de atacar en el dragon q esta montando
        dispara el metodo de dragon que ataca a otro
        recorre la lista para chequear que dragon maneja y fluye hacia cDragon
    */
}

void cJinete::entrenarYrendir(cDragon* ptrDragon)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4);
    int numero_aleatorio = dis(gen);
    switch (numero_aleatorio) {
    case 1:
        set_trainresult(Aprobado);
        incorporarDragon(ptrDragon);
    case 2:
        set_trainresult(Desaprobado);
    case 3:
        set_trainresult(Primero);
        incorporarDragon(ptrDragon);
    case 4:
        set_trainresult(Ultimo);//no es que no aprobo, sino que aprobo justo
        incorporarDragon(ptrDragon);
    }
}
void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    this->listaDragones.push_back(ptrDragon);
    entrenarDragon();//llama al metodo de dragon y lo entrena. jinete fluye hacia dragon
    domar();//settea domado al drg
    this->listaDragones.back()->altaNombre();// le da el nombre
}
void cJinete::entrenarDragon()
{
    //lista de ifs que ven su habilidad y de acuerdo a esta establecen la forma de ataque
    //es lineal, digamos una habilidad va a una forma de ataque
    cDragon * ptrDragon = this->listaDragones.back();
    switch (ptrDragon->caracteristicaD) {
    case ResisteFuego:
        ptrDragon->get_FormaAtaque()->CambiarTipo(BolasFuego);
        if (ptrDragon->tamanioD == Grande && this->TrainResult == Primero)//si el dragon es grande y el jinete salio primero tiene el maximo danio
            ptrDragon->get_FormaAtaque()->cambiarDanio(Mucho);
        else if(ptrDragon->tamanioD == Chico && this->TrainResult == Ultimo)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Poco);
        else if (ptrDragon->tamanioD == Mediano || ptrDragon->tamanioD == Grande|| ptrDragon->tamanioD == Chico)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Moderado);
        break;
    case PatasLargas:
        ptrDragon->get_FormaAtaque()->CambiarTipo(Araniar);
        if (ptrDragon->tamanioD == Grande && this->TrainResult == Primero)//si el dragon es grande y el jinete salio primero tiene el maximo danio
            ptrDragon->get_FormaAtaque()->cambiarDanio(Mucho);
        else if (ptrDragon->tamanioD == Chico && this->TrainResult == Ultimo)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Poco);
        else if (ptrDragon->tamanioD == Mediano || ptrDragon->tamanioD == Grande || ptrDragon->tamanioD == Chico)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Moderado);
        break;
    case Rapidez:
        ptrDragon->get_FormaAtaque()->CambiarTipo(Coletazo);
        if (ptrDragon->tamanioD == Grande && this->TrainResult == Primero)//si el dragon es grande y el jinete salio primero tiene el maximo danio
            ptrDragon->get_FormaAtaque()->cambiarDanio(Mucho);
        else if (ptrDragon->tamanioD == Chico && this->TrainResult == Ultimo)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Poco);
        else if (ptrDragon->tamanioD == Mediano || ptrDragon->tamanioD == Grande || ptrDragon->tamanioD == Chico)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Moderado);
        break;
    case CuraFacil:
        ptrDragon->get_FormaAtaque()->CambiarTipo(Curar);
        if (ptrDragon->tamanioD == Grande && this->TrainResult == Primero)//si el dragon es grande y el jinete salio primero tiene el maximo danio
            ptrDragon->get_FormaAtaque()->cambiarDanio(Mucho);
        else if (ptrDragon->tamanioD == Chico && this->TrainResult == Ultimo)//si el dragon es chico y el jinete salio ultimo hace poco danio
            ptrDragon->get_FormaAtaque()->cambiarDanio(Poco);
        else if (ptrDragon->tamanioD == Mediano || ptrDragon->tamanioD == Grande || ptrDragon->tamanioD == Chico)
            ptrDragon->get_FormaAtaque()->cambiarDanio(Moderado);
        break;
    }
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
