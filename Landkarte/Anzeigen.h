#ifndef ANZEIGEN_H
#define ANZEIGEN_H

#include <QWidget>
#include "Navigationssystem.h"
#include "Ort.h"
#include "Adresse.h"
#include "Point_Of_Interest.h"
#include <vector>

namespace Ui {
class Anzeigen;
}

class Anzeigen : public QDialog
{
    Q_OBJECT

public:
    explicit Anzeigen(vector<Point_Of_Interest*>&poi, vector<Adresse*>&adr, QWidget *parent = nullptr);
    ~Anzeigen();

private:
    Ui::Anzeigen *ui;
};

#endif // ANZEIGEN_H
