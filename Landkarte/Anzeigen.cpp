#include "Anzeigen.h"
#include "ui_Anzeigen.h"

Anzeigen::Anzeigen(vector<Point_Of_Interest*>&poi, vector<Adresse*>&adr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Anzeigen)
{
    ui->setupUi(this);
    int sizeadr = adr.size();
    int sizepoi = poi.size();
    QString id;
    QString typ;
    QString laeng;
    QString breit;
    QString strasse;
    QString hausnummer;
    QString plz;
    QString gemeinde;
    QString name;
    QString land;
    QString kategorie;
    QString bemerkung;
    if(sizeadr != 0)
    {
        for (int i=0; i < sizeadr; i++){
            id = QString::number(adr[i]->AdresseId());
            name = QString::fromStdString(adr[i]->Name());
            typ = QString::fromStdString(adr[i]->Typ());
            laeng = QString::number(adr[i]->Langengrad());
            breit = QString::number(adr[i]->Breitengrrad());
            strasse = QString::fromStdString(adr[i]->Strasse());
            hausnummer = QString::fromStdString(adr[i]->Hausnummer());
            plz = QString::fromStdString(adr[i]->PLZ() );
            gemeinde = QString::fromStdString(adr[i]->Gemeinde());
            land = QString::fromStdString(adr[i]->Land());
            ui->listWidget->addItem(id);
            ui->listWidget->addItem(typ);
            ui->listWidget->addItem(name);
            ui->listWidget->addItem(laeng);
            ui->listWidget->addItem(breit);
            ui->listWidget->addItem(strasse);
            ui->listWidget->addItem(hausnummer);
            ui->listWidget->addItem(plz);
            ui->listWidget->addItem(gemeinde);
            ui->listWidget->addItem(land);
        }
    }
    if(sizepoi != 0)
    {
        for (int i=0; i < sizepoi; i++){
            id = QString::number(poi[i]->PoiId());
            typ = QString::fromStdString(poi[i]->Typ());
            name = QString::fromStdString(poi[i]->Name());
            laeng = QString::number(poi[i]->Langengrad());
            breit = QString::number(poi[i]->Breitengrrad());
            kategorie = QString::fromStdString(poi[i]->Kategorie());
            bemerkung = QString::fromStdString(poi[i]->Bemerkung());
            ui->listWidget->addItem(id);
            ui->listWidget->addItem(typ);
            ui->listWidget->addItem(name);
            ui->listWidget->addItem(laeng);
            ui->listWidget->addItem(breit);
            ui->listWidget->addItem(kategorie);
            ui->listWidget->addItem(bemerkung);
        }
    }
}

Anzeigen::~Anzeigen()
{
    delete ui;
}
