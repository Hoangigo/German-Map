#include "Anlegen.h"
#include "ui_Anlegen.h"

Anlegen::Anlegen(int &id, vector<Point_Of_Interest*>&poi, vector<Adresse*>&adr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Anlegen)
{
    ui->setupUi(this);
    id_ = &id;
    this->poi_ = &poi;
    this->adr_ = &adr;

}

Anlegen::~Anlegen()
{
    delete ui;
}
void Anlegen::on_buttonBox_accepted()
{
    laengengrad_ = QInputDialog::getText(this,"Laengengrad", "Laengengrad");
    breitengrad_ = QInputDialog::getText(this,"Breitengrad", "Breitengrad");
    double lang = laengengrad_.toDouble();
    double breit = breitengrad_.toDouble();
    if (ui->Adresse->isChecked()){
        string str;
        string haus;
        string plz;
        string gemeinde;
        string land;
        string name;
        string typ = "Adr";
        strasse_ =  QInputDialog::getText(this,"Strasse", "Strasse");
        str = strasse_.toStdString();
        hausnummer_ = QInputDialog::getText(this,"Hausnummer", "Hausnummer");
        haus = hausnummer_.toStdString();
        postleitzahl_ = QInputDialog::getText(this,"Postleitenzahl", "Postleitenzahl");
        plz = postleitzahl_.toStdString();
        gemeinde_ = QInputDialog::getText(this,"Gemeinde", "Gemeinde");
        gemeinde = gemeinde_.toStdString();
        land_ = QInputDialog::getText(this,"Land", "Land");
        land = land_.toStdString();
        nameAdr_ = QInputDialog::getText(this,"Name", "Name");
        name = nameAdr_.toStdString();
        *id_ = *id_ + 1;
        neuadresse_ = new Adresse(*id_, typ ,lang, breit, str, haus, plz, gemeinde, land, name );
        adr_->push_back(neuadresse_);
    }

    else if (ui->POI->isChecked()){
        string kategoire;
        string bemerkung;
        string name;
        string typ = "Poi";
        kategorie_ =  QInputDialog::getText(this,"Kategorie", "Kategorie");
        kategoire = kategorie_.toStdString();
        bemerkung_ = QInputDialog::getText(this,"Bemerkung", "Bemerkung");
        bemerkung = hausnummer_.toStdString();
        namePoi_ = QInputDialog::getText(this,"Name", "Name");
        name = namePoi_.toStdString();
        *id_ = *id_ + 1;
        neupoi_ = new Point_Of_Interest(*id_, typ ,lang, breit, kategoire, bemerkung, name );
        poi_->push_back(neupoi_);
    }

}


