#include "cJinete.h"
vector<string> cJinete::PosicionNombres = {"Primero", "Segundo", "Tercero", "Cuarto", "Quinto", "Sexto"};
int cJinete::iterador = 0;
int cJinete::i = 0;
// un i para ir avanzando las formas de ataque en entrenar

cJinete::cJinete(string nom, string ape, string fecha,eCaract caracfisic):cVikingo(nom,ape,caracfisic)
{
	stringstream fechaIngresada(fecha);
	string aux = "";
	sFecha auxF = { 0,0,0 };

	//Escaneamos el string de la fecha, hasta cada '/'
	// Guardando en auxiliar los datos de dia, mes y anio
	getline(fechaIngresada, aux, '/');
    auxF.dia = stoi(aux);
	getline(fechaIngresada, aux, '/');
	auxF.mes = stoi(aux);
	getline(fechaIngresada, aux);
	auxF.anio = stoi(aux);

    /*
    // Pasamos lo guardado a un struct tm
	// el -1900 en anio es porque tm tiene en cuenta los anios pasados desde el 1900
	// el -1 en mes es porque el rango va de 0 a 11
    */

	this->fechaNac = { 0, 0, 0, auxF.dia, auxF.mes - 1, auxF.anio - 1900 };
   
    this->TrainResult = NoAsistio;
    this->listaDragonesVivos = list<cDragon*>();
    //apodo será asignado gracias al dragon que dome. inicializado en cVikingo

}

cDragon* cJinete::operator[](size_t index)
{
    if (listaDragonesVivos.size() < index)
        throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    list<cDragon*>::iterator it = this->listaDragonesVivos.begin();
    int i = 0;
    while (i < index && it!= listaDragonesVivos.end()) {
         it++;
         i++;
    }
     return *it;
}

string cJinete::toStringJ()
{
    stringstream ss;

    ss << this->nombreV << " " << this->apellidoV << ", trabaja de: " << enumPtostring() << ", su caracteristica es: "
       << enumCtostring() << ". Su fecha de nacimiento es: "<< this->apodoJ << " " << to_string(this->fechaNac.tm_mday) 
        << "/" << to_string(this->fechaNac.tm_mon + 1) << "/"<< to_string(this->fechaNac.tm_year + 1900) 
        << endl << "Resultado de entrenamiento: " << enumRtostring() << ". Cantidad de dragones eliminados: " 
        << this->DragonesEliminados << ". Sus dragones de combate son: ";
   
    if (listaDragonesVivos.size() == 0)
        ss << "0" << endl;
    list<cDragon*>::iterator itD = listaDragonesVivos.begin();
    while (itD != listaDragonesVivos.end()) {
        ss << (*itD)->toStringD() << endl;
        itD++;
    }

    return ss.str();
}

string cJinete::enumRtostring()
{
    switch (this->TrainResult) {
    case NoAsistio:
        return "No asistio";
    case Aprobado:
        return "Aprobado";
    case Desaprobado:
        return "Desaprobado";
    case Primero:
        return "Primero";
    case Ultimo:
        return "Ultimo";
    }
}

bool cJinete::entrenarDragon()
{
    bool flagTrain = true;
    cDragon * ptrDragon = this->listaDragonesVivos.back();
    if(ptrDragon!=nullptr)
    {  
        if (ptrDragon->get_estado())
        {
            cAtaque* ataaux = dynamic_cast<cAtaque*>(ptrDragon->get_FormaCombateXIndice(i));
            //va con ese i porque cada vez que llamo a esta funcion paso a modificar la siguiente forma de combate
            cDefensa* defaux = dynamic_cast<cDefensa*>(ptrDragon->get_FormaCombateXIndice(i));
            cJinete::i++;
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
                    defaux->cambiarDefensa(ResisteFuego);
                    //En el caso de la defensa no hay un numero que la represente, pero si sirve para hacer la cuenta del danio en ataque
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
    }   }

    else
    {
        throw out_of_range("No hay mas dragones");
        flagTrain = false;
    }
    return flagTrain;
}

void quitarDragon(list<cDragon*> listaux, cDragon* drg)
{
    list<cDragon*>::iterator it = listaux.begin();
    while (it != listaux.end() && (*it) != drg) it++;

    listaux.erase(it);
}

void cJinete::manejarDragon(cDragon* ptrD, int index)
{      
    cDragon* midragon = nullptr;//Creo el objeto de dragon que voy a usar 
    if (this->listaDragonesVivos.size() == 0)
        throw exception("El jinete no tiene ningun dragon guardado");
    else if (listaDragonesVivos.size() < index)
      throw out_of_range("El jinete tiene menos dragones que el numero ingresado");
    else
        try
        {
             midragon = this->operator[](index);
            //dragon de cierta posicion de la lista para que luche
        }
         catch (exception& e) { cout << e.what() << endl; }

    if ((midragon)->get_estado())
    {
        if (ptrD->get_domado() == false)
            (midragon)->atacarDragon(ptrD);
        //llamado a atacar del dragon que esta montando y le pasa el otro para la pelea
        else {//si con midragon no ataca, ataca con el proximo vivo que encuentre en la lista y mete el otro en los muertos
            quitarDragon(listaDragonesVivos, midragon);

            list<cDragon*>::iterator it = this->listaDragonesVivos.begin();

            while (it != listaDragonesVivos.end() && !((*it)->get_estado())) it++;
            (*it)->atacarDragon(ptrD);

            if (it == listaDragonesVivos.end())
                throw exception("El jinete no posee dragones vivos para luchar");
        }
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
{
    if (listaDragonesVivos.empty())
        throw exception("Lista vacía");
    else
        this->listaDragonesVivos.back()->set_domado(true);
}

void cJinete::altaNombre(cDragon* drg)
{
    if (iterador == 7)
        throw exception("No hay mas nombres para Dragones");

    string aux = cJinete::PosicionNombres[iterador];//vector static para nombres
    cJinete::iterador++;// avanzo el iterador static, como una variable global
    int i = 0;
    string s;
    if (drg->get_caracteristica() == Fogoso) {
        s = nombreV + "'s Fueguin " + aux;
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == Garras) {
        s=nombreV+"'s Garritas " + aux;
        drg->set_nombre(s);
    }
    else if (drg->get_caracteristica() == Colilargo){
        s = nombreV + "'s Colilargo " + aux;
        drg->set_nombre(s);
    }
    else {
        s=nombreV+"'s Dientudo " + aux;
        drg->set_nombre(s);
    }
}

bool cJinete::incorporarDragon(cDragon* ptrDragon)
{
    bool flagTrain = true;
    try
    {
        this->altaNombre(ptrDragon);
        this->listaDragonesVivos.push_back(ptrDragon);
        this->domar();
        flagTrain= this->entrenarDragon();
    }catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return flagTrain;
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
        flag = incorporarDragon(drgNuevo);
        break;
    case 2:
        set_trainresult(Desaprobado);
        flag = false;
        break;
    case 3:
        set_trainresult(Primero);
        flag = incorporarDragon(drgNuevo);
        break;
    case 4:
        set_trainresult(Ultimo);//aprueba con lo justo
        flag = incorporarDragon(drgNuevo);
        break;
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