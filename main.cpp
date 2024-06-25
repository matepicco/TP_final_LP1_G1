#include "Headers.h"
#include "cStoico.h"

int main()
{
    cStoico Stoico = cStoico();
    cAtaque* ata1 = new cAtaque(BolasFuego, Moderado, 60);
    cDefensa* def1 = new cDefensa(ArmaduraDrg, Moderado, 60);
    cAtaque* ata2 = new cAtaque(Araniar, Poco, 40);
    cDefensa* def2 = new cDefensa(Rapidez, Poco, 40);
    cAtaque* ata3 = new cAtaque(Mordidita, Moderado, 70);
    cDefensa* def3 = new cDefensa(ResisteFuego, Moderado, 70);
    cAtaque* ata4 = new cAtaque(Coletazo, Poco, 40);
    cDefensa* def4 = new cDefensa(EscamasResistentes, Poco, 40);

    cDragon* dragon1 = new cDragon(Fogoso, Grande, Rojo);
    cDragon* dragon2 = new cDragon(Garras, Mediano, Negro);
    cDragon* dragon3 = new cDragon(Colilargo, Chico, Verde);
    cDragon* dragon4 = new cDragon(Dientes, Grande, Blanco);

    dragon1->agregarFA(def1);
    dragon1->agregarFA(ata1);
    dragon2->agregarFA(ata2);
    dragon2->agregarFA(def2);
    dragon3->agregarFA(ata3);
    dragon3->agregarFA(def3);
    dragon4->agregarFA(ata4);
    dragon4->agregarFA(def4);

    cJinete* jinete1 = new cJinete("Malau", "Raro", "04/10/2002", Fortachon);
    cJinete* jinete2 = new cJinete("Elsa", "Pato", "10/10/2010", Matematico);

    cGuerrero* guerrero1 = new cGuerrero("Andrew", "Hubberman", Fortachon, 60);
    cGuerrero* guerrero2 = new cGuerrero("Joe", "Rogan", Matematico, 50);

    Stoico + guerrero1;
    Stoico + guerrero2;
    Stoico + jinete1;
    Stoico + jinete2;

    Stoico + dragon1;
    Stoico + dragon2;
    Stoico + dragon3;
    Stoico + dragon4;

    try
    {
        Stoico.crearInteraccion();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    cout << Stoico;

    delete ata1;
    delete def1;
    delete dragon1;
    delete dragon2;
    delete dragon3;
    delete dragon4;
    delete jinete1;
    delete jinete2;
    delete guerrero1;
    delete guerrero2;

    return 0;
}
