#ifndef ORT_H
#define ORT_H

#include <iostream>

using namespace std;

class Ort
{
public:
    Ort();
    ~Ort();
    Ort(double langengrad, double breitengrad, string typ, string name);
    void Langengrad(double x);
    void Breitengrad(double x);

    string Name();
    double Langengrad();
    double Breitengrrad();
    double Entfernung(double langengrad, double breitengrad);
    string Typ();
private:
    double laengengrad_;
    double breitengrad_;
    string typ_;
    string name_;
};

#endif // ORT_H
