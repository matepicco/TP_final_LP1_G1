#pragma once
#include <string>
#include <list>
#include <iostream>
#include <exception>
#include <ctime>
#include <sstream>


using namespace std;

enum eDamage { Poco, Moderado, Devastador };
enum eResultado { NoAsistio, Aprobado, Desaprobado, Primero, Ultimo };
enum eTipoAtaque { BolasFuego, Araniar, Coletazo, Curar, Escapar };
enum eHabilidad {ResisteFuego, PatasLargas, Rapidez, CuraFacil};