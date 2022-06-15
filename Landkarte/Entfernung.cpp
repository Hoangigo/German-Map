#include "Entfernung.h"
#include "ui_Entfernung.h"

Entfernung::Entfernung( vector<Point_Of_Interest*> &poi, vector<Adresse*> &adr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Entfernung)
{
    ui->setupUi(this);
    poi_ = &poi;
    adr_ = &adr;
    double ent;
    ent = Entfernung_Berechnen();
    if(ent < 0)
    {
        QString err = "Ungueltige Wert eingegeben.";
        ui->listWidget->addItem(err);
    }
    else
    {
        QString result = QString::number(ent);
        result = result + "Km";
        ui->listWidget->addItem(result);
    }
}
Entfernung::Entfernung(vector<Point_Of_Interest*> &poi, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Entfernung)
{
    ui->setupUi(this);
    clickedpoi_ = &poi;
    int clicked = poi.size();
    double ent;
    if(clicked != 2)
    {
        QString err = "Sie muessen nur 2 Positionen waehlen.";
        ui->listWidget->addItem(err);
    }
    else
    {
        ent = Clicked_Enrfernung();
        QString result = QString::number(ent);
        result = result + "Km";
        ui->listWidget->addItem(result);
    }
}

Entfernung::~Entfernung()
{
    delete ui;
}

double Entfernung::Entfernung_Berechnen()
{
    int adressesize = this->adr_->size();
    int poisize = this->poi_->size();
    QString start, ende;
    bool existort = false;
    double lon1 = -1, lon2 = -1, lat1 = -1, lat2 = -1;
    double entfernung;
    const double kilo = 6371.01;
    const double R = 0.01745327;
    start = QInputDialog::getText(this,"StartID", "StartID");
    ende = QInputDialog::getText(this,"EndeID", "EndeID");
        for(int i = 0; i < adressesize; i++)
        {
            if(start.toInt() == adr_->at(i)->AdresseId())
            {
                lon1 = adr_->at(i)->Langengrad();
                lat1 = adr_->at(i)->Breitengrrad();
                existort = true;
            }
            else if(ende.toInt() == adr_->at(i)->AdresseId())
            {
                lon2 = adr_->at(i)->Langengrad();
                lat2 = adr_->at(i)->Breitengrrad();
                existort = true;
            }
        }
        for(int i = 0; i < poisize; i++)
        {
            if(start.toInt() == poi_->at(i)->PoiId())
            {
                lon1 = poi_->at(i)->Langengrad();
                lat1 = poi_->at(i)->Breitengrrad();
                existort = true;
            }
            else if(ende.toInt() == poi_->at(i)->PoiId())
            {
                lon2 = poi_->at(i)->Langengrad();
                lat2 = poi_->at(i)->Breitengrrad();
                existort = true;
            }
        }
        if(existort)
        {
            lon1 = lon1*R;
            lon2 = lon2*R;
            lat1 = lat1*R;
            lat2 = lat2*R;
            entfernung = kilo * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(lon1 - lon2)));
            return entfernung;
        }
        else
        {
            return -1;
        }
}

double Entfernung::Clicked_Enrfernung()
{
    double lon1 = -1, lon2 = -1, lat1 = -1, lat2 = -1;
    double entfernung;
    const double kilo = 6371.01;
    const double R = 0.01745327;

    lon1 = clickedpoi_->at(0)->Langengrad();
    lat1 = clickedpoi_->at(0)->Breitengrrad();
    lon2 = clickedpoi_->at(1)->Langengrad();
    lat2 = clickedpoi_->at(1)->Breitengrrad();
    lon1 = lon1*R;
    lon2 = lon2*R;
    lat1 = lat1*R;
    lat2 = lat2*R;
    entfernung = kilo * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(lon1 - lon2)));
    return entfernung;
}
