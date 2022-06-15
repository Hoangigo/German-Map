#include "Ort.h"

Ort::Ort()
{

}

Ort::~Ort()
{

}

Ort::Ort(double langengrad, double breitengrad, string typ, string name)
{
    this->laengengrad_ = langengrad;
    this->breitengrad_ = breitengrad;
    this->typ_ = typ;
    this->name_ = name;
}

double Ort::Langengrad()
{
    return this->laengengrad_;
}

double Ort::Breitengrrad()
{
    return this->breitengrad_;
}

void Ort::Langengrad(double x)
{
    this->laengengrad_ = x;

}
void Ort::Breitengrad(double x)
{
    this->breitengrad_ = x;
}

string Ort::Typ()
{
    return this->typ_;
}

string Ort::Name()
{
    return this->name_;
}
