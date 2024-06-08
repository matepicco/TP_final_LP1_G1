#include "cJinete.h"

cJinete::cJinete(string nom, string ape, time_t fecha,eCaract caracfisic):cVikingo(nom,ape,caracfisic)
{
	stringstream fechaIngresada(fecha);
	string aux = "";
	sFecha auxF = { 0,0,0 };

	// Escaneamos el string de la fecha, hasta cada '/'
	// Guardando en auxiliar los datos de dia, mes y anio
	getline(fechaIngresada, aux, '/');
	auxF.dia = stoi(aux);

	getline(fechaIngresada, aux, '/');
	auxF.mes = stoi(aux);

	getline(fechaIngresada, aux);
	auxF.anio = stoi(aux);

	// Pasamos lo guardado a un struct tm
	// el -1900 en anio es porque tm tiene en cuenta los anios pasados desde el 1900
	// el -1 en mes es porque el rango va de 0 a 11
	this->fechaNac = { 0, 0, 0, auxF.dia, auxF.mes - 1, auxF.anio - 1900 };
   
    this->TrainResult = NoAsistio;
    //el apodo se asignará gracias al dragon que dome. inicializado en cVikingo
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

string cJinete::toString()
{
    //imprimo lo del hijo,padre
    stringstream ss;

    ss << this->nombreV << "" << this->apellidoV<< "" << this->posicion << "" << this->caractFisicasV << ""
       << this->apodoJ << "" << to_string(this->fechaNac.tm_mday) << "" << to_string(this->fechaNac.tm_mon + 1) << ""
       << to_string(this->fechaNac.tm_year + 1900) << "" << this->TrainResult << "" << this->DragonesEliminados << endl;

    return ss.str();
}

void cJinete::entrenarDragon()
{
    //indicación de Sol.Necesario? previamente lista es chequeada no nula
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

void cJinete::manejarDragon(cDragon* ptrD, int index)//manejardragon(jinete1[3])) 
{      
    cDragon* midragon;//Creo el objeto de dragon que voy a usar 
    if (this->listaDragonesVivos.size() == 0)
        throw exception("El jinete no tiene ningun dragon guardado");
    else if (listaDragonesVivos.size() < index)
      throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    else
        midragon = this->operator[](index);// se trae el dragon de cierta posicion de la lista para que luche
    
    list<cDragon*>::iterator it = this->listaDragonesVivos.begin();
    
    if ((midragon)->get_estado()) {
        (midragon)->atacarDragon(ptrD);//llama al atacar del dragon que esta montando y le pasa el otro para la pelea
    }
    else {//si con midragon no ataca, ataca con el proximo vivo que encuentre en la lista y mete el otro en los muertos
        this->listaDragonesMuertos.push_back(midragon);
        quitarDragon(listaDragonesVivos, (midragon));
     
        while (it != listaDragonesVivos.end() && !((*it)->get_estado())) it++;
            (*it)->atacarDragon(ptrD);

            if (it == listaDragonesVivos.end())
                throw exception("El jinete no posee dragones vivos para luchar");
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

void cJinete::altaNombre(cDragon* drg)
{
    string s;
    if (drg->get_caracteristica() == ResisteFuego) {
            s = nombreV + "'s Fueguin";
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == PatasLargas) {
        s=nombreV+"'s Patudo";
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == Rapidez) {
        s = nombreV + "'s Rapidragui";
        drg->set_nombre(s);
    }
    else {
        s=nombreV+"'s Curita";
        drg->set_nombre(s);
    }
}

void cJinete::incorporarDragon(cDragon* ptrDragon)
{
    this->altaNombre(ptrDragon);
    this->domar();//settea domado al drg
    this->listaDragonesVivos.push_back(ptrDragon);
    this->entrenarDragon();
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

void cJinete::RelacionarseConDragon(cDragon* drgNuevo) {

    //caso stoico manda a vikingo a relacionarse. Si sos jinete:
    // caso#1: manejas los de tu lista entonces de por sí, están domados por vos.
    // caso#2: viene listaDragones por parametro (dragones no necessarily domados por vos): recorres, hasta encontrar uno domado por vos. 
    //caso#1
    

    this->entrenarYrendir(drgNuevo);


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