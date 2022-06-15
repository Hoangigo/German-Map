#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "Ort.h"
#include "Point_Of_Interest.h"
#include "Navigationssystem.h"
#include "Adresse.h"
#include "ergebnis.h"
#include "Anzeigen.h"
#include "Entfernung.h"
#include <QVector>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Navigation; }
QT_END_NAMESPACE

class Navigation : public QMainWindow
{
    Q_OBJECT

public:
//    Navigation(QWidget *parent = nullptr);
    Navigation(vector<Point_Of_Interest*> &poi, vector<Adresse*> &adr, QWidget *parent = nullptr);
    ~Navigation();
    void Orte_Anlegen();
    void Krte_Anzeigen();
    void Entfernung_Berechnen();
    double Radian(double grad);
    void Karte_Exportieren();
    void Karte_Importieren();

private slots:
    void On_Entfernung_Clicked();
    void On_Information_Clicked();
    void On_Alleorte_Clicked();
    void On_Berlin_Clicked();
    void On_Nuernberg_Clicked();
    void On_Saarbruecken_Clicked();
    void On_Hda_Clicked();
    void On_Dresden_Clicked();
    void On_Muenchen_Clicked();
    void On_Stuttgart_Clicked();
    void On_Bremen_Clicked();

private:
    Ui::Navigation *ui;
    Adresse* neuadresse_;
    Point_Of_Interest* neupoi_;
    vector<Adresse*> *adr_;
    vector<Point_Of_Interest*> *poi_;
    vector<Point_Of_Interest*> clickedpoi_;
};
#endif // NAVIGATION_H
