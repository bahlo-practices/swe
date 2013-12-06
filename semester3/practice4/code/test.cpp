// Main.cpp
// Programm zum Testen der Methodenaufrufe des Rezeptbuchs aus dem SWE Praktikum im WS 2013
// Ralf Hahn,  04.10.2013

#include "Rezeptbuch.h"

#include <iostream>
using namespace std;
#include <iomanip>

int main()
{

int i=0;

// das Rezeptbuch anlegen
Rezeptbuch* MyRezeptbuch = new Rezeptbuch;


// Rezeptliste ausgeben
cout << "*********************************************" << endl;
cout << "Es gibt " << MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;

for (i=0; i<MyRezeptbuch->getAnzahlRezepte(); i++)
{
    Rezept* r = MyRezeptbuch->getRezept(i);
    cout << i << ". " << r->getName() << endl;
}
cout << "*********************************************" << endl;

// Rezeptschritte abfragen
for (i=0; i<MyRezeptbuch->getAnzahlRezepte(); i++) // für jedes Rezept...
{
    cout << endl << endl;
    // Cocktailname als Überschrift
    Rezept* r = MyRezeptbuch->getRezept(i);
    cout << "**** " << r->getName() << " ****" << endl;

    for (int j=0; j<r->getAnzahlRezeptschritte(); j++) // für jeden Rezeptschritt...
    {
        Rezeptschritt* rs = r->getRezeptSchritt(j);
        float Menge = rs->getMenge();
        string Zutat = rs->getZutat();

        cout << j << ". " << ": " << setw(15) << Zutat << "\t" << Menge << endl;
    }
}

// Rezept loeschen
cout << "*********************************************" << endl;
cout << "Teste das Loeschen von Rezepten!" << endl;
cout << "Es gibt " << MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;
    MyRezeptbuch->deleteRezept(2);
cout << "Jetzt gibt es ein Rezept weniger, naemlich: " <<
        MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;

// Neue Tests
// Rezept loeschen außerhalb der Liste
cout << "*********************************************" << endl;
cout << "Teste das Loeschen von nicht vorhandenen Rezepten!" << endl;
cout << "Loesche Rezept " << MyRezeptbuch->getAnzahlRezepte()+1 << "/" << MyRezeptbuch->getAnzahlRezepte() << endl;
    MyRezeptbuch->deleteRezept(MyRezeptbuch->getAnzahlRezepte()+1);

// Hol Rezept außerhalb der Liste
cout << "*********************************************" << endl;
cout << "Teste das Zugreifen von nicht vorhandenen Rezepten!" << endl;
cout << "Greife zu auf Rezept " << MyRezeptbuch->getAnzahlRezepte()+1 << "/" << MyRezeptbuch->getAnzahlRezepte() << endl;
    MyRezeptbuch->getRezept(MyRezeptbuch->getAnzahlRezepte()+1);

// Lösche Rezept und greife danach darauf zu
cout << "*********************************************" << endl;
cout << "Teste das Zugreifen auf bereits geloeschtes Rezept!" << endl;
cout << "Hole Rezept " << MyRezeptbuch->getAnzahlRezepte() << endl;
    Rezept *r = MyRezeptbuch->getRezept(MyRezeptbuch->getAnzahlRezepte());
cout << "Loesche Rezept " << MyRezeptbuch->getAnzahlRezepte() << endl;
    MyRezeptbuch->deleteRezept(MyRezeptbuch->getAnzahlRezepte());
cout << "Greife auf Rezept zu" << endl;
cout << "Pointer: " << r << endl;
// cout << r->getName() << endl; // Nullpointer

// Wenn es keine Schritte gibt, abfangen

 delete MyRezeptbuch;

 return 1;
}
