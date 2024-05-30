#include "cJinete.h"

cJinete::cJinete(string nom, string ape, time_t fecha,eCaract caracfisic):cVikingo(nom,ape,caracfisic)
{
    //debe declarar implementar el constructor del padre. to do
    this->fechaNac = fecha;;
    this->TrainResult = NoAsistio;
    //el apodo se lo asignará gracias al dragon que dome. inicializado en cVikingo
    this->listaDragonesVivos = list<cDragon*>();
}

void cJinete::domar()
{
    this->listaDragonesVivos.back()->set_domado(true);
}

cDragon* cJinete::operator[](size_t index)
{
    if (listaDragonesVivos.size() < index)
        throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    list<cDragon*>::iterator it = this->listaDragonesVivos.begin();
   /* while (int i = 0 != index) {
        it++;
        i++;
    }
    return *it;*/
    auto it = listaDragonesVivos.begin();
    advance(it, index);
    return *it;
}

void cJinete::manejarDragon(int index, cDragon* ptrD)
{
    /*
        llama al metodo de atacar en el dragon q esta montando
        
    */
    if (listaDragonesVivos.size() < index)
        throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    auto it = listaDragonesVivos.begin();
    advance(it, index);//para que avance en la lista hasta el indice pedido
    (*it)->atacarDragon(ptrD);//llama al atacar del dragon que esta montando y le pasa el otro para la pelea
    if ((*it)->get_estado() == false) {
        this->listaDragonesMuertos.push_back(*it);
        quitarDragon(listaDragonesVivos,(*it));
    }
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
    this->listaDragonesVivos.push_back(ptrDragon);
    entrenarDragon();//llama al metodo de dragon y lo entrena. jinete fluye hacia dragon
    domar();//settea domado al drg
    this->listaDragonesVivos.back()->altaNombre();// le da el nombre
}
void cJinete::entrenarDragon()
{
    //lista de ifs que ven su habilidad y de acuerdo a esta establecen la forma de ataque
    //es lineal, digamos una habilidad va a una forma de ataque
    cDragon * ptrDragon = this->listaDragonesVivos.back();
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


void cJinete::set_trainresult(eResultado resultado)
{
    this->TrainResult = resultado;
}

cJinete::~cJinete()
{
}

void quitarDragon(list<cDragon*> listaux, cDragon* drg)
{
    auto it = std::find(listaux.begin(), listaux.end(), drg);
    if (it != listaux.end()) {
        listaux.erase(it);
    }
}
