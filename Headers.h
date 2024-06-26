#pragma once
#include <string>
#include <list>
#include <iostream>
#include <exception>
#include <ctime>
#include <sstream>
#include <random>
#include <cstdlib>

using namespace std;

enum eHabilidad { Fogoso, Garras, Colilargo, Dientes};
enum eIntensidad { Poco, Moderado, Mucho };
enum eTipoAtaque { BolasFuego, Araniar, Coletazo, Mordidita};
enum eTipoDefensa { ResisteFuego, EscamasResistentes, Rapidez, ArmaduraDrg };
enum eTamanio {Grande, Mediano, Chico};
enum eColor {Rojo,Negro,Azul,Naranja,Verde,Blanco};
enum eResultado { NoAsistio, Aprobado, Desaprobado, Primero, Ultimo };
enum eCaract {Fortachon, Matematico, Botanico};
enum ePos {Leniador, Comerciante, Agricultor};

typedef struct Fecha {
	int dia, mes, anio;
}sFecha;