//@(#) Rezeptbuch.h

#ifndef REZEPTBUCH_H_H
#define REZEPTBUCH_H_H

#include <list>
#include <string>
#include "string.h"
//Jeder Rezeptsschritt hat eine Zutat und eine Menge. Das wird frei interpretiert, d.h. eine Zutat kann auch "Mixen" sein. Die Menge bezieht sich dann auf die Zeit (20 = 20 Sekunden)
// 
class Rezeptschritt
{
    
public:
    //Destruktor 
    virtual ~Rezeptschritt();
    //Liefert den Wert des Rezeptschrittes (die Menge) 
    virtual float getMenge(void) const;
    //Liefert die Zutat des Rezeptschrittes 
    virtual std::string getZutat(void) const;
    //Konstruktor 
    Rezeptschritt(void);
    //Setzt den Wert des Rezeptschrittes (die Menge) 
    virtual void setMenge(float m_Menge);
    //Setzt die Zutat des Rezeptschrittes 
    virtual void setZutat(std::string m_Zutat);
    
private:
    //Die Menge der Zutat - das k�nnen Sekunden, St�ck oder Gramm sein 
    float m_Menge;
    
    //Der Name der Zutat 
    std::string m_Zutat;
    
    
};
//Ein Rezept hat einen Namen und verwaltet eine beliebig lange Liste von Rezeptschritten.
// 
class Rezept
{
    
public:
    //Destruktor. L�scht ein Rezept inklusive der enthaltenen Rezeprtschritte. 
    virtual ~Rezept();
    //Erzeugt einen neuen Rezeptschritt mit der �bergebenen Zutat und der Menge und h�ngt den an die Liste der Schritte an.
    //	 
    virtual void append(std::string z, float m);
    //Liefert die Anzahl der Rezeptschritte 
    virtual int getAnzahlRezeptschritte();
    //Liefert den Namen des Rezeptes 
    virtual std::string getName(void) const;
    //Liefert einen Verweis auf den i-ten Rezeptschritt (0..n-1).
    //Sonst wird eine NULL geliefert.
    //	 
    virtual Rezeptschritt * getRezeptSchritt(unsigned int i);
    //Konstruktor - legt ein Rezept an. 
    Rezept(void);
    //Setzt den Namen des Rezeptes 
    virtual void setName(std::string Name);
    
private:
    //Der Name des Rezeptes	 
    std::string m_Name;
    
    //Jedes Rezept besteht aus vielen Rezeptschritten. Die werden hier (geordnet) in einer Liste abgelegt.
    //	 
    std::list<Rezeptschritt> m_Rezeptschritte;
    
    
};
//Das Rezeptbuch kennt eine Liste von Rezepten. Es bietet die M�glichkeit Rezepte zu suchen und abzufragen. Das Initialisieren der Rezepte erfolgt �ber den Dateileser. 
// 
class Rezeptbuch
{
    
public:
    //Destruktor. L�scht insbesondere den Initialisierer 
    virtual ~Rezeptbuch();
    //L�scht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
    virtual bool deleteRezept(unsigned int i);
    //Liefert die Anzahl der verf�gbaren Rezepte. 
    virtual int getAnzahlRezepte();
    //Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
    //Ansonsten NULL.
    //	 
    virtual Rezept * getRezept(unsigned int i);
    //Konstruktor; legt tempor�r einen Initialisierer an, damit dieser die Liste auff�llt.
    // 
    Rezeptbuch(void);
    
private:
    //Ein Rezeptbuch besteht aus vielen Rezepten - diese werden als eine Liste abgelegt.
    //	 
    std::list<Rezept *> m_Rezepte;
    
    
};

#endif
