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

//mantenemos eHab para caracteristicas sea Ata/Def
enum eHabilidad { ResisteFuego, PatasLargas, Rapidez, CuraFacil }; 
enum eDanio { Poco, Moderado, Mucho };
enum eTipoAtaque { BolasFuego, Araniar, Coletazo, Curar };
enum eTipoDefensa {};
enum eTamanio {Grande, Mediano, Chico};
enum eColor {Rojo,Negro,Azul,Naranja,Verde,Blanco};
enum eResultado { NoAsistio, Aprobado, Desaprobado, Primero, Ultimo };
enum eCaract {Fortachon, Matematico, Botanico};
enum ePos {Leniador, Comerciante, Agricultor};

typedef struct Fecha {
	int dia, mes, anio;
}sFecha;