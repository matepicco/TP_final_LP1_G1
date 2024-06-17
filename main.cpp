#include "Headers.h"

#include "cFormaCombate.h"
#include "cAtaque.h"
#include "cDefensa.h"

#include "cGuerrero.h"
#include "cJinete.h"
#include "cDragon.h"
#include "cStoico.h"

int main()
{
    cStoico Stoico = cStoico();
    cAtaque* ata1 = new cAtaque(BolasFuego, Moderado, 60);
    cDefensa* def1 = new cDefensa(ArmaduraDrg, Moderado, 60);

    cDragon* dragon1 = new cDragon(Fogoso,Grande,Rojo);
    cDragon* dragon2 = new cDragon(Garras,Mediano,Negro);
    cDragon* dragon3 = new cDragon(Colilargo,Chico,Verde);
    cDragon* dragon4 = new cDragon(Dientes,Grande,Blanco);

    cJinete* jinete1 = new cJinete("Malau","Raro","04/10/2002",Fortachon);
    cJinete* jinete2 = new cJinete("Elsa","Pato","10/10/2010",Matematico);

    cGuerrero* guerrero1 = new cGuerrero("Malau", "Raro",Fortachon, 60);
    cGuerrero* guerrero2 = new cGuerrero("Elsa", "Pato", Matematico, 50);

    try
    {
        Stoico + dragon1;
        Stoico + jinete1;
        Stoico + guerrero1;
        Stoico + jinete2;
        Stoico.crearInteraccion();
        Stoico.imprimir();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
    Stoico + jinete1;
    Stoico + jinete2;
    Stoico.imprimir();

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
}
