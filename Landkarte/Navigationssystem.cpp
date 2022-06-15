#include "Navigationssystem.h"
#include "ui_Navigationssystem.h"
#include "Ort.h"
#include "Point_Of_Interest.h"
#include "Adresse.h"
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

Navigationssystem::Navigationssystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Navigationssystem)
{
    ui->setupUi(this);
    id_ = 0;
    connect(ui->anlegen,&QPushButton::clicked ,this, &Navigationssystem::Orte_Anlegen);
    connect(ui->anzeigen,&QPushButton::clicked, this, &Navigationssystem::Krte_Anzeigen);
    connect(ui->deutschland, &QPushButton::clicked, this, &Navigationssystem::Map_Anzeigen);
    connect(ui->importieren, &QPushButton::clicked, this, &Navigationssystem::Karte_Importieren);
    connect(ui->exportieren, &QPushButton::clicked, this, &Navigationssystem::Karte_Exportieren);
    connect(ui->entfernung, &QPushButton::clicked, this, &Navigationssystem::Entfernung_Berechnen);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 52.517036, 13.388859, "LandesHauptstadt", "Berlin", "Berlin");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 53.075819, 8.807164, "LandesHauptstadt", "Bremen", "Bremen");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 51.049328, 13.738143, "LandesHauptstadt", "Dresden", "Dresden");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 49.867373, 8.638491, "LandesHauptstadt", "Hochschule", "H-da");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 48.137107, 11.575382, "LandesHauptstadt", "Muenchen", "Muenchen");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 49.453872, 11.077298, "LandesHauptstadt", "Nuernberg", "Nuernberg");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 49.234362, 6.996379, "LandesHauptstadt", "Saarbruecken", "Saarbruecken");
    poiliste_.push_back(neupoi_);
    id_++;
    neupoi_ = new Point_Of_Interest(id_,"Poi", 48.778448, 9.180013, "LandesHauptstadt", "Stuttgart", "Stuttgart");
    poiliste_.push_back(neupoi_);
}

Navigationssystem::~Navigationssystem()
{
    delete ui;
}

void Navigationssystem::Orte_Anlegen()
{

    Anlegen* anleg = new Anlegen(id_, this->poiliste_, this->adresseliste_);
    anleg->show();
}

void Navigationssystem::Krte_Anzeigen()
{
    Anzeigen* anzeig = new Anzeigen(this->poiliste_, this->adresseliste_);
    anzeig->show();
}

void Navigationssystem::Map_Anzeigen()
{
    Navigation* navi = new Navigation(poiliste_, adresseliste_);
    navi->show();
}

void Navigationssystem::Entfernung_Berechnen()
{
    Entfernung* ent = new Entfernung(poiliste_, adresseliste_);
    ent->show();
}

void Navigationssystem::Karte_Exportieren()
{
    int adresse_size = this->adresseliste_.size();
    int poi_size = this->poiliste_.size();
    int count;
    string id;
    string typ;
    string laengengrad;
    string breitengrad;
    string strasse;
    string hausnummer;
    string plz;
    string gemeinde;
    string kategorie;
    string bemerkung;
    string land;
    string name;
    const string adresse = "Adresse\n";
    const string poi = "Point of Interest\n";
    const char zeile = '\n';
    const char semicolon = ';';

    ofstream ziel("karte.txt", ios::trunc|ios::out);
    if(adresse_size != 0)
    {
        count = 0;
        ziel.write(adresse.c_str(), adresse.size());
        do{
            id = to_string(adresseliste_[count]->AdresseId());
            typ = adresseliste_[count]->Typ();
            name = adresseliste_[count]->Name();
            laengengrad = to_string(adresseliste_[count]->Langengrad());
            breitengrad = to_string(adresseliste_[count]->Breitengrrad());
            strasse = adresseliste_[count]->Strasse();
            hausnummer = adresseliste_[count]->Hausnummer();
            plz = adresseliste_[count]->PLZ();
            gemeinde = adresseliste_[count]->Gemeinde();
            land = adresseliste_[count]->Land();
            ziel.write(id.c_str(),id.size());
            ziel.put(semicolon);
            ziel.write(typ.c_str(), typ.size());
            ziel.put(semicolon);
            ziel.write(name.c_str(), name.size());
            ziel.put(semicolon);
            ziel.write(laengengrad.c_str(), laengengrad.size());
            ziel.put(semicolon);
            ziel.write(breitengrad.c_str(), breitengrad.size());
            ziel.put(semicolon);
            ziel.write(strasse.c_str(), strasse.size());
            ziel.put(semicolon);
            ziel.write(hausnummer.c_str(), hausnummer.size());
            ziel.put(semicolon);
            ziel.write(plz.c_str(), plz.size());
            ziel.put(semicolon);
            ziel.write(gemeinde.c_str(), gemeinde.size());
            ziel.put(semicolon);
            ziel.write(land.c_str(), land.size());
            ziel.put(zeile);
            count++;
        }while(count < adresse_size);
    }
    else
    {
        ziel.write(adresse.c_str(), adresse.size());
        cout << "Es gibt keine Datei der Adresse, zu speichern." << endl;
    }
    if(poi_size != 0)
    {
        count = 0;
        ziel.write(poi.c_str(), poi.size());
        do{
            id = to_string(poiliste_[count]->PoiId());
            typ = poiliste_[count]->Typ();
            name = poiliste_[count]->Name();
            laengengrad = to_string(poiliste_[count]->Langengrad());
            breitengrad = to_string(poiliste_[count]->Breitengrrad());
            kategorie = poiliste_[count]->Kategorie();
            bemerkung = poiliste_[count]->Bemerkung();
            ziel.write(id.c_str(),id.size());
            ziel.put(semicolon);
            ziel.write(typ.c_str(), typ.size());
            ziel.put(semicolon);
            ziel.write(name.c_str(), name.size());
            ziel.put(semicolon);
            ziel.write(laengengrad.c_str(), laengengrad.size());
            ziel.put(semicolon);
            ziel.write(breitengrad.c_str(), breitengrad.size());
            ziel.put(semicolon);
            ziel.write(kategorie.c_str(), kategorie.size());
            ziel.put(semicolon);
            ziel.write(bemerkung.c_str(), bemerkung.size());
            ziel.put(zeile);
            count++;
        }while(count < poi_size);
    }
    else
    {
        ziel.write(poi.c_str(), poi.size());
        cout << "Es gibt keine Datei von Point Of Interest, zu speichern." << endl;
    }
}

void Navigationssystem::Karte_Importieren()
{
    ifstream karte;
    int flag = 0;
    int anzahl = 0;
    int semicolon = 0;
    int id;
    string land;
    string typ;
    double laengengrad;
    double breitengrad;
    string strasse;
    string hausnummer;
    string plz;
    string gemeinde;
    string kategorie;
    string bemerkung;
    string name;
    vector<char> TMP;
    char c;

    karte.open("karte.txt", ios::in);

    adresseliste_.clear();
    poiliste_.clear();

    do{
        karte.get(c);
        if(c != ';' && c != '\n')
        {
            TMP.push_back(c);
        }
        else if(c == '\n' && semicolon == 0 && flag == 0)
        {//ab jetzt Adresse
            flag++;
            TMP.clear();
        }
        else if(c == '\n' && semicolon == 0 && flag == 1)
        {//ab jetzt Point of Interest
            flag++;
            TMP.clear();
        }
        else if(c == ';' && semicolon == 0)
        {// bis hier ist eine ID
            string id_tmp = string(TMP.begin(), TMP.end());
            id = stoi(id_tmp);
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 1)
        {//bis hier typ
            typ = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 2)
        {// bis hier name
            name = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 3)
        {//bis hier ist Laengengrad
            string laengengrad_tmp = string(TMP.begin(), TMP.end());
            laengengrad = stod(laengengrad_tmp);
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 4)
        {//bis hier ist Breitengrad
            string breitengrad_tmp = string(TMP.begin(), TMP.end());
            breitengrad = stod(breitengrad_tmp);
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 5 && flag == 1)
        {//bis hier ist Strasse
            strasse = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 6 && flag == 1)
        {//bis hier ist Hausnummer
            hausnummer = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 7 && flag == 1)
        {//bis hier ist plz
            plz = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 8 && flag == 1)
        {//bis hier ist Gemeinde
            gemeinde = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == '\n' && semicolon == 9 && flag == 1)
        {// bis hier land
            land = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == ';' && semicolon == 5 && flag == 2)
        {//bis hier kategorie
            kategorie = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }
        else if(c == '\n' && semicolon == 6 && flag == 2)
        {//bis hier Bemerkung
            bemerkung = string(TMP.begin(), TMP.end());
            TMP.clear();
            semicolon++;
        }

        if(semicolon == 10 && flag == 1)
        {
            neuadresse_ = new Adresse(id, typ, laengengrad, breitengrad, strasse, hausnummer, plz, gemeinde, land, name);
            adresseliste_.push_back(neuadresse_);
            semicolon = 0;
            anzahl = (anzahl > id) ? anzahl : id;
        }
        else if(semicolon == 7 && flag == 2)
        {
            neupoi_ = new Point_Of_Interest(id, typ, laengengrad, breitengrad, kategorie, bemerkung, name);
            poiliste_.push_back(neupoi_);
            semicolon = 0;
            anzahl = (anzahl > id) ? anzahl : id;
        }
    }while(!karte.eof());

    this->id_ = anzahl;
    karte.close();
}

