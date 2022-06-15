#include "ergebnis.h"
#include "ui_ergebnis.h"

Ergebnis::Ergebnis(QVector<Point_Of_Interest*> &liste, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ergebnis)
{
    ui->setupUi(this);
    for (int i = 0; i < liste.size(); i++){
        QString Kategorie = QString::fromStdString(liste[i]->Kategorie());
        QString Bemerkung = QString::fromStdString(liste[i]->Bemerkung());
        QString Name = QString::fromStdString(liste[i]->Name());
        int id = liste[i]->PoiId();
        double x = liste[i]->Langengrad();
        double y = liste[i]->Breitengrrad();
        ui->info->addItem(QString::number(id));
        ui->info->addItem(Name);
        ui->info->addItem(QString::number(x));
        ui->info->addItem(QString::number(y));
        ui->info->addItem(Kategorie);
        ui->info->addItem(Bemerkung);
    }
}

Ergebnis::~Ergebnis()
{
    delete ui;
}
