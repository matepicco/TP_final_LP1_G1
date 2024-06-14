#include "cJinete.h"
vector<string> cJinete::PosicionNombres = {"uno", "dos", "tres", "cuatro", "cinco", "seis"};
int cJinete::iterador = 0;
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
    //imprimo hijo y padre
    stringstream ss;

    ss << this->nombreV << "" << this->apellidoV<< "" << this->posicion << "" << this->caractFisicasV << ""
       << this->apodoJ << "" << to_string(this->fechaNac.tm_mday) << "" << to_string(this->fechaNac.tm_mon + 1) << ""
       << to_string(this->fechaNac.tm_year + 1900) << "" << this->TrainResult << "" << this->DragonesEliminados << endl;

    return ss.str();
}

void cJinete::entrenarDragon()///////// Poner danio de acuerdo a cada INTENSIDAD
{
    cDragon * ptrDragon = this->listaDragonesVivos.back();
    cAtaque* ataaux = dynamic_cast<cAtaque*>(ptrDragon->get_FormaAtaque());//Aca toma como que el dragon siempre tiene una forma de ataque
    cDefensa* defaux = dynamic_cast<cDefensa*>(ptrDragon->get_FormaAtaque());
    switch (ptrDragon->get_caracteristica()) {
    case Fogoso:
        if (ataaux != nullptr) {
            ataaux->CambiarTipo(BolasFuego);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                //si el dragon es grande y el jinete salio primero tiene el maximo danio
                ataaux->cambiarIntensidad(Mucho);
                ataaux->setCantDanio(80);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo) {
                ataaux->cambiarIntensidad(Poco);
                ataaux->setCantDanio(20);
            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
                ataaux->cambiarIntensidad(Moderado);
                ataaux->setCantDanio(50);
            } 
            break;
        }
        else if (defaux != nullptr) {
            defaux->cambiarDefensa(ResisteFuego);//En el caso de la defensa no hay un numero que la represente, pero si sirve para hacer la cuenta del danio en ataque
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                defaux->cambiarIntensidad(Mucho);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
                defaux->cambiarIntensidad(Poco);
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
                defaux->cambiarIntensidad(Moderado);
            break;
        }
    case Garras:
        if (ataaux != nullptr) {
            ataaux->CambiarTipo(Araniar);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                //si el dragon es grande y el jinete salio primero tiene el maximo danio
                ataaux->cambiarIntensidad(Mucho);
                ataaux->setCantDanio(80);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo) { 
                ataaux->cambiarIntensidad(Poco);
                ataaux->setCantDanio(20);
            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
             ataaux->cambiarIntensidad(Moderado);
             ataaux->setCantDanio(50);
            }
            break;
        }
        else if (defaux != nullptr) {
            defaux->cambiarDefensa(EscamasResistentes);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                defaux->cambiarIntensidad(Mucho);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
            {
                defaux->cambiarIntensidad(Poco);
            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
            defaux->cambiarIntensidad(Moderado);
            } 
            break;
        }
    case Colilargo:
        if (ataaux != nullptr) {
            ataaux->CambiarTipo(Coletazo);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                ataaux->cambiarIntensidad(Mucho);
                ataaux->setCantDanio(80);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
            {
                ataaux->cambiarIntensidad(Poco);
                ataaux->setCantDanio(20);
            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
                ataaux->cambiarIntensidad(Moderado);
                ataaux->setCantDanio(50);
            }
            break;
        }
        else if (defaux != nullptr) {
            defaux->cambiarDefensa(Rapidez);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                defaux->cambiarIntensidad(Mucho);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
            {
                defaux->cambiarIntensidad(Poco);
            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
                defaux->cambiarIntensidad(Moderado);
            }
            break;
        }
    case Dientes:
        if (ataaux != nullptr) {
            ataaux->CambiarTipo(Mordidita);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                ataaux->cambiarIntensidad(Mucho);
                ataaux->setCantDanio(80);

            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
            {
                ataaux->cambiarIntensidad(Poco);
                ataaux->setCantDanio(20);

            }
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
            {
                ataaux->cambiarIntensidad(Moderado);
                ataaux->setCantDanio(50);
            }
            break;
        }
        else if (defaux != nullptr) {
            defaux->cambiarDefensa(ArmaduraDrg);
            if (ptrDragon->get_tamanio() == Grande && this->TrainResult == Primero) {
                defaux->cambiarIntensidad(Mucho);
            }
            else if (ptrDragon->get_tamanio() == Chico && this->TrainResult == Ultimo)
                defaux->cambiarIntensidad(Poco);
            else if (ptrDragon->get_tamanio() == Mediano || ptrDragon->get_tamanio() == Grande || ptrDragon->get_tamanio() == Chico)
                defaux->cambiarIntensidad(Moderado);
            break;
        }
    }
}

void quitarDragon(list<cDragon*> listaux, cDragon* drg)
{
    list<cDragon*>::iterator it = listaux.begin();
    while (it != listaux.end() && (*it) != drg) it++;

    listaux.erase(it);

    if(it == listaux.end())
        throw exception("El elemento a quitar no esta en la lista proporcionada");
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
        quitarDragon(listaDragonesVivos, midragon);
     
        while (it != listaDragonesVivos.end() && !((*it)->get_estado())) it++;
            (*it)->atacarDragon(ptrD);

            if (it == listaDragonesVivos.end())
                throw exception("El jinete no posee dragones vivos para luchar");
    }
    return;
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
    if (listaDragonesVivos.empty())
        throw exception("Lista vacía");
    else
        this->listaDragonesVivos.back()->set_domado(true);
}

void cJinete::altaNombre(cDragon* drg)
{
    if (iterador == 7)
        throw exception("No hay mas nombres para Dragones");// Y si, lo fije en 7 porque dale que va a tener mas de 7 dragones bobo no da
    string aux = cJinete::PosicionNombres[iterador];//vector static para nombres
    cJinete::iterador++;// avanzo el iterador static, como una variable global
    int i = 0;
    string s;
    if (drg->get_caracteristica() == ResisteFuego) {
        s = nombreV + "'s Fueguin" + aux;
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == Garras) {
        s=nombreV+"'s Garritas" + aux;
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == Colilargo){
        s = nombreV + "'s Colilargo" + aux;
        drg->set_nombre(s);
    }
    else {
        s=nombreV+"'s Dientudo" + aux;
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

bool cJinete::RelacionarseConDragon(cDragon* drgNuevo) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4);
    int numero_aleatorio = dis(gen);
    bool flag = true;
    switch (numero_aleatorio) {
    case 1:
        set_trainresult(Aprobado);
        incorporarDragon(drgNuevo);
    case 2:
        set_trainresult(Desaprobado);
        flag = false;
    case 3:
        set_trainresult(Primero);
        incorporarDragon(drgNuevo);
    case 4:
        set_trainresult(Ultimo);//no es que no aprobo, sino que aprobo justo
        incorporarDragon(drgNuevo);
    }
    return flag;
}

void cJinete::set_trainresult(eResultado resultado)
{
    this->TrainResult = resultado;
}

cJinete::~cJinete()
{
}
