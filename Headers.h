#pragma once
#include <string>
#include <list>
#include <iostream>
#include <exception>
#include <ctime>
#include <sstream>
#include <random>


using namespace std;

enum eDanio { Poco, Moderado, Mucho };
enum eResultado { NoAsistio, Aprobado, Desaprobado, Primero, Ultimo };
enum eTipoAtaque { BolasFuego, Araniar, Coletazo, Curar};
enum eHabilidad {ResisteFuego, PatasLargas, Rapidez, CuraFacil};
enum eTamanio {Grande, Mediano, Chico};
enum eColor {Rojo,Negro,Azul,Naranja,Verde,Blanco};