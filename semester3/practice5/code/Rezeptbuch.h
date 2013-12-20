/**********************************************************************************/
/*                                Deklarationsmodul                               */
/**********************************************************************************/
/* 
 * generiert mit MagicDraw
 *
 * erstellt am: 04.10.2013  14:49:08
 * Repository : RezeptbuchV5
 * Modell     : Rezeptbuch
 * Benutzer   : RaHa 
 * File       : Rezeptbuch.h
 *
 */


#ifndef _REZEPTBUCH_H_489
#define _REZEPTBUCH_H_489

#include "string.h"
#include <list>
#include <string>

using namespace std;


//Jeder Rezeptsschritt hat eine Zutat und eine Menge. Das wird frei interpretiert, d.h. eine Zutat kann auch "Mixen" sein. Die Menge bezieht sich dann auf die Zeit (20 = 20 Sekunden)
// 
class Rezeptschritt
{
   //Der Name der Zutat 
    std::string m_Zutat;
   
   //Die Menge der Zutat - das k�nnen Sekunden, St�ck oder Gramm sein 
    float m_Menge;
   
   public:
    //Konstruktor 
    Rezeptschritt(void);
   
   //Destruktor 
    virtual ~Rezeptschritt();
   
   //Liefert die Zutat des Rezeptschrittes 
    virtual std::string getZutat(void) const;
   
   //Liefert den Wert des Rezeptschrittes (die Menge) 
    virtual float getMenge(void) const;
   
   //Setzt die Zutat des Rezeptschrittes 
    virtual void setZutat(std::string m_Zutat);
   
   //Setzt den Wert des Rezeptschrittes (die Menge) 
    virtual void setMenge(float m_Menge);
   
};


//Ein Rezept hat einen Namen und verwaltet eine beliebig lange Liste von Rezeptschritten.
// 
class Rezept
{
   //Jedes Rezept besteht aus vielen Rezeptschritten. Die werden hier (geordnet) in einer Liste abgelegt.
    //	 
    std::list<Rezeptschritt> m_Rezeptschritte;
   
   //Der Name des Rezeptes	 
    std::string m_Name;
   
   public:
    //Konstruktor - legt ein Rezept an. 
    Rezept(void);
   
   //Destruktor. L�scht ein Rezept inklusive der enthaltenen Rezeprtschritte. 
    virtual ~Rezept();

   
   //Liefert die Anzahl der Rezeptschritte 
    virtual int getAnzahlRezeptschritte();

   //Liefert einen Verweis auf den i-ten Rezeptschritt (0..n-1).
    //Sonst wird eine NULL geliefert.
    //	 
    virtual Rezeptschritt * getRezeptSchritt(unsigned int i);
   
   //Liefert den Namen des Rezeptes 
    virtual std::string getName(void) const;
   
   //Setzt den Namen des Rezeptes 
    virtual void setName(std::string Name);

   //Erzeugt einen neuen Rezeptschritt mit der �bergebenen Zutat und der Menge und h�ngt den an die Liste der Schritte an.
    //	 
    virtual void append(std::string z, float m);
   
};

//Das Rezeptbuch kennt eine Liste von Rezepten. Es bietet die M�glichkeit Rezepte zu suchen und abzufragen. Das Initialisieren der Rezepte erfolgt �ber den Dateileser. 
// 
class Rezeptbuch
{
   //Ein Rezeptbuch besteht aus vielen Rezepten - diese werden als eine Liste abgelegt.
    //	 
    std::list<Rezept *> m_Rezepte;

   public:
    //Konstruktor; legt tempor�r einen Initialisierer an, damit dieser die Liste auff�llt.
    // 
    Rezeptbuch(void);
   
   //Destruktor. L�scht insbesondere den Initialisierer 
    virtual ~Rezeptbuch();
   
   //Liefert die Anzahl der verf�gbaren Rezepte. 
    virtual int getAnzahlRezepte();

   //Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
    //Ansonsten NULL.
    //	 
    virtual Rezept * getRezept(unsigned int i);
   //L�scht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
    virtual bool deleteRezept(unsigned int i);  
   

};

#endif
