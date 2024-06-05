#include "cJinete.h"

cJinete::cJinete(string nom, string ape, time_t fecha,eCaract caracfisic):cVikingo(nom,ape,caracfisic)
{
    //debe declarar implementar el constructor del padre. to do
    this->fechaNac = fecha;;
    this->TrainResult = NoAsistio;
    //el apodo se lo asignará gracias al dragon que dome. inicializado en cVikingo
    this->listaDragonesVivos = list<cDragon*>();
}

cDragon* cJinete::operator[](size_t index)
{
    if (listaDragonesVivos.size() < index)
        throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    list<cDragon*>::iterator it = this->listaDragonesVivos.begin();
    while (int i = 0 != index) {
         it++;
         i++;
    }
     return *it;
}

void cJinete::entrenarDragon()
{
    //indicación de Sol. En mi pov, no necesario ya que: previamente la lista es chequeada no nula
   if(listaDragonesVivos.empty())
       throw exception("Lista vacía");

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

void cJinete::manejarDragon(cDragon* ptrD)//manejardragon(jinete1[3])) 
{ //jinete[3]
    /*
        llama al metodo de atacar en el dragon q esta montando

    */

    int index; 
    // ARREGLAR FX MANEJAR EN FX DE la sobrecarga.
    //como logro justificar,con la sobrecarga del [] que el ptr por parametro es una posicion entera (int)
    if (listaDragonesVivos.size() < index)
        throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    list<cDragon*>::iterator it = this->listaDragonesVivos.begin();
    advance(it, index);//para que avance en la lista hasta el indice pedido
    
    if ((*it)->get_estado()) {
        (*it)->atacarDragon(ptrD);//llama al atacar del dragon que esta montando y le pasa el otro para la pelea
    }
    else {//si con ese no ataca, ataca con el proximo vivo que encuentre en la lista y mete el otro en los muertos
        this->listaDragonesMuertos.push_back(*it);
        quitarDragon(listaDragonesVivos, (*it));
        it = listaDragonesVivos.begin();
        while (it != listaDragonesVivos.end() && (*it)->get_estado() == true) {
            (*it)->atacarDragon(ptrD);
        }

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

void cJinete::domar()
{//agregar si lista vacia, exception.tambien para entrenar dragon
   //list.empty(): Returns whether the list container is empty(i.e.whether its size is 0).
    if (listaDragonesVivos.empty())
        throw exception("Lista vacía");
    else
        this->listaDragonesVivos.back()->set_domado(true);
}

void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    this->listaDragonesVivos.push_back(ptrDragon);
    this->entrenarDragon();
    this->domar();//settea domado al drg
    this->listaDragonesVivos.back()->altaNombre();// le da el nombre
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

void cJinete::RelacionarseConDragon(cVikingo* ptrV)
{
    //caso stoico manda a vikingo a relacionarse. Si sos jinete:
    // caso#1: manejas los de tu lista entonces de por sí, están domados por vos.
    // caso#2: viene listaDragones por parametro (dragones no necessarily domados por vos): recorres, hasta encontrar uno domado por vos. 

    //caso#1

    cJinete* ptrJ = dynamic_cast<cJinete*>(ptrV);
    if (ptrJ != nullptr)
    {
        list<cDragon*>::iterator itObjD = ptrJ->listaDragonesVivos.begin();

        //try catch lo hace Stoico?

        if (listaDragonesVivos.empty())//PERO ACA SERIA DEL QUE LE LLEGA
            throw exception("Lista vac�a");
        
        while (itObjD != listaDragonesVivos.end())
        {
            ptrJ->entrenarYrendir(*(itObjD));
        }
        /* MODULO APARTE: función extra. relaciono con dragon por parametro
          //caso#2
          //simulo crear una lista tal que en realidad viene por parametro
            list <cDragon*> listaDragon;
            itObjD = listaDragon.begin();
           //primero chequeo jinete tenga domado al dragon xParametro. necesito
            while (itObjD != listaDragon.end())
            {//condicion posible: igualo iterador listaParametro con iterador listaObjetoJinete hasta que coincidan
                ptrJ->entrenarYrendir(*(itObjD));
            }
        }
         */
    }
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
    list<cDragon*>::iterator it = listaux.begin();
    advance(it,drg);
    listaux.erase(it);
}