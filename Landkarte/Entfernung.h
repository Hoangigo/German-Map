#ifndef ENTFERNUNG_H
#define ENTFERNUNG_H

#include <QWidget>
#include "Ort.h"
#include "Adresse.h"
#include "Point_Of_Interest.h"
#include "Navigationssystem.h"
#include "navigation.h"
#include <vector>
#include <cmath>

namespace Ui {
class Entfernung;
}

class Entfernung : public QWidget
{
    Q_OBJECT

public:
    explicit Entfernung(vector<Point_Of_Interest*> &poi, vector<Adresse*> &adr, QWidget *parent = nullptr);
    explicit Entfernung(vector<Point_Of_Interest*> &clickedpoi,QWidget *parent = nullptr);
    ~Entfernung();
    double Clicked_Enrfernung();
    double Entfernung_Berechnen();

private:
    Ui::Entfernung *ui;
    vector<Point_Of_Interest*> *poi_;
    vector<Adresse*> *adr_;
    vector<Point_Of_Interest*> *clickedpoi_;
};

#endif // ENTFERNUNG_H
