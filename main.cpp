#include "Headers.h"
#include "cStoico.h"

int main()
{
    cStoico Stoico = cStoico();
    cAtaque* ata1 = new cAtaque(BolasFuego, Moderado, 60);
    cDefensa* def1 = new cDefensa(ArmaduraDrg, Moderado, 60);

    cDragon* dragon1 = new cDragon(Fogoso, Grande, Rojo);
    cDragon* dragon2 = new cDragon(Garras, Mediano, Negro);
    cDragon* dragon3 = new cDragon(Colilargo, Chico, Verde);
    cDragon* dragon4 = new cDragon(Dientes, Grande, Blanco);

    //dragon1 + ata1;
    //no me permite con operator+ de dragon entonces
    dragon1->agregarFA(def1);
    dragon1->agregarFA(ata1);
    dragon2->agregarFA(ata1);
    dragon2->agregarFA(def1);
    dragon3->agregarFA(ata1);
    dragon3->agregarFA(def1);
    dragon4->agregarFA(ata1);
    dragon4->agregarFA(def1);

    cJinete* jinete1 = new cJinete("Malau", "Raro", "04/10/2002", Fortachon);
    cJinete* jinete2 = new cJinete("Elsa", "Pato", "10/10/2010", Matematico);

    cGuerrero* guerrero1 = new cGuerrero("Malau", "Raro", Fortachon, 60);
    cGuerrero* guerrero2 = new cGuerrero("Elsa", "Pato", Matematico, 50);

    try
    {
        Stoico + guerrero1;
        Stoico + guerrero2;
        Stoico + jinete1;
        Stoico + jinete2;

        Stoico + dragon1;
        Stoico + dragon2;
        Stoico + dragon3;
        Stoico + dragon4;

        Stoico.crearInteraccion();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    cout << guerrero1->toStringG();
    cout << Stoico.toStringS();
    /*
    cout << jinete1 << endl;
    cout << Stoico;
    no se porque tira error, como si no hubiese sobrecarga
   cout << dragon1 << endl;
     */

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
