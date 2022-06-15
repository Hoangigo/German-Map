#include "Adresse.h"
#include <fstream>

Adresse::Adresse()
{

}

Adresse::~Adresse()
{

}

Adresse::Adresse(int id, string typ, double x, double y, string strasse, string hausnummer, string postleitzhl, string gemeinde, string land, string name): Ort(x, y, typ, name)
{
    this->strasse_ = strasse;
    this->postleitzahl_ = postleitzhl;
    this->hausnummer_ = hausnummer;
    this->gemeinde_ = gemeinde;
    this->adresseid_ = id;
    this->land_ = land;
}

string Adresse::Strasse()
{
    return this->strasse_;
}

string Adresse::Hausnummer()
{
    return this->hausnummer_;
}

string Adresse::PLZ()
{
    return this->postleitzahl_;
}

string Adresse::Gemeinde()
{
    return this->gemeinde_;
}
int Adresse::AdresseId()
{
    return adresseid_;
}
string Adresse::Land()
{
    return land_;
}


void Adresse::Strasse(string x)
{
    this->strasse_ = x;
}
void Adresse::AdresseId(int x)
{
    this->adresseid_ = x;
}
void Adresse::Hausnummer(string x)
{
    this->hausnummer_ = x;
}
void Adresse::PLZ(string x)
{
    this->postleitzahl_ = x;
}
void Adresse::Gemeinde(string x)
{
    this->gemeinde_ = x;
}
void Adresse::Land(string x)
{
    land_ = x;
}

