#ifndef ERGEBNIS_H
#define ERGEBNIS_H

#include <QWidget>
#include "Ort.h"
#include "Point_Of_Interest.h"
#include "navigation.h"
#include "Adresse.h"

namespace Ui {
class Ergebnis;
}

class Ergebnis : public QWidget
{
    Q_OBJECT

public:
    explicit Ergebnis(QVector<Point_Of_Interest*> &liste, QWidget *parent = nullptr);
    ~Ergebnis();

private:
    Ui::Ergebnis *ui;
};

#endif // ERGEBNIS_H
