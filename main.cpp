#include "Headers.h"
#include "cStoico.h"

int main()
{
    cStoico Stoico = cStoico();
    cDragon* dragon1 = new cDragon(Fogoso,Grande,Rojo);
    cDragon* dragon2 = new cDragon(Garras,Mediano,Negro);
    cDragon* dragon3 = new cDragon(Colilargo,Chico,Verde);
    cDragon* dragon4 = new cDragon(Dientes,Grande,Blanco);

    cJinete* jinete1 = new cJinete("Malau","Raro",04/10/2002,Fortachon);
    cJinete* jinete2 = new cJinete("Elsa","Pato",10/10/2010,Matematico);
    try
    {
        Stoico + jinete1;
        Stoico + jinete2;
        Stoico.imprimir();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
    Stoico + jinete1;
    Stoico + jinete2;
    Stoico.imprimir();
   // cout << Stoico;  // no se porque tira error, como si no hubiese sobrecarga
 /*   cout << jinete1 << endl;
    cout << dragon1 << endl;*/
}
