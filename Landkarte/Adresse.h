#ifndef ADRESSE_H
#define ADRESSE_H
#include <iostream>
#include "Ort.h"
#include <fstream>

using namespace std;

class Adresse : public Ort
{
public:
    Adresse();
    ~Adresse();
    Adresse(int adresseid, string typ, double x, double y, string strasse, string hausnummer, string postleitzhl, string gemeinde, string land, string name);
    string Strasse();
    string Hausnummer();
    string PLZ();
    string Gemeinde();
    string Land();
    int AdresseId();
    void Strasse(string x);
    void Hausnummer(string x);
    void PLZ(string x);
    void Gemeinde(string);
    void AdresseId(int x);
    void Land(string x);
    void read(ifstream *in)
    {
        in->read((char *) this, sizeof(Adresse));
    };
    void write(ofstream *out)
    {
        out->write((char *) this, sizeof(Adresse));
    };
private:
    string strasse_;
    string hausnummer_;
    string postleitzahl_;
    string gemeinde_;
    string land_;
    int adresseid_;
};

#endif // ADRESSE_H
