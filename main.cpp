#include "Headers.h"
#include "cStoico.h"

int main()
{
    cStoico Stoico = cStoico();
    cDragon* dragon1 = new cDragon(ResisteFuego,Grande,Rojo);
    cDragon* dragon2 = new cDragon(Rapidez,Mediano,Negro);
    cDragon* dragon3 = new cDragon(CuraFacil,Chico,Verde);
    cDragon* dragon4 = new cDragon(PatasLargas,Grande,Blanco);

    cJinete* jinete1 = new cJinete();
    cJinete* jinete2 = new cJinete();

    Stoico + jinete1;

    cout << jinete1;
    cout << dragon1; //comprueba q << mal hecho

//aca luego de instanciar a los jinetes y vikingos,
//se llama a ingresar dragon, se pasa el puntero y ahi empieza el programa llamando a entrenar
//luego se llamaria a atacar dragon y eso haria que dos peleen
}
