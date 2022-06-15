#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H

#include <QWidget>
#include <QInputDialog>
#include <iostream>
#include "Ort.h"
#include "Point_Of_Interest.h"
#include "Adresse.h"
#include <vector>
#include "Anlegen.h"
#include "Anzeigen.h"
#include "navigation.h"
#include "Entfernung.h"

namespace Ui {
class Navigationssystem;
}

class Navigationssystem : public QWidget
{
    Q_OBJECT

public:
    explicit Navigationssystem(QWidget *parent = nullptr);
    ~Navigationssystem();
    void Entfernung_Berechnen();
public slots:
    void Orte_Anlegen();
    void Krte_Anzeigen();
    void Karte_Exportieren();
    void Karte_Importieren();
    void Map_Anzeigen();
private:
    Ui::Navigationssystem *ui;
    Adresse* neuadresse_;
    Point_Of_Interest* neupoi_;
    vector<Adresse*> adresseliste_;
    vector<Point_Of_Interest*> poiliste_;
    int id_;
};

#endif // NAVIGATIONSSYSTEM_H
