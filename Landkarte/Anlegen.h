#ifndef ANLEGEN_H
#define ANLEGEN_H

#include <QDialog>
#include <QInputDialog>
#include "Navigationssystem.h"
#include "Ort.h"
#include "Adresse.h"
#include "Point_Of_Interest.h"

namespace Ui {
class Anlegen;
}

class Anlegen : public QDialog
{
    Q_OBJECT

public:
    explicit Anlegen(int &id, vector<Point_Of_Interest*>&poi, vector<Adresse*>&adr, QWidget *parent = nullptr);
    ~Anlegen();

public slots:
    void on_buttonBox_accepted();

private:
    Ui::Anlegen *ui;
    vector<Point_Of_Interest*> *poi_;
    vector<Adresse*> *adr_;
    int *id_;
    Adresse* neuadresse_;
    Point_Of_Interest* neupoi_;
    QString laengengrad_;
    QString breitengrad_;
    QString strasse_;
    QString hausnummer_;
    QString postleitzahl_;
    QString gemeinde_;
    QString land_;
    QString kategorie_;
    QString bemerkung_;
    QString nameAdr_;
    QString namePoi_;
};

#endif // ANLEGEN_H
