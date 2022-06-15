#include "navigation.h"
#include "ui_navigation.h"
#include "Ort.h"
#include "Point_Of_Interest.h"
#include "Adresse.h"
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

//Navigation::Navigation(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::Navigation)
//{
//    ui->setupUi(this);
//    connect(ui->alleorte, &QPushButton::clicked, this, &Navigation::On_Alleorte_Clicked);
//}
Navigation::Navigation(vector<Point_Of_Interest*> &poi, vector<Adresse*> &adr, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Navigation)
{
    ui->setupUi(this);
    poi_ = &poi;
    adr_ = &adr;
    connect(ui->entfernung, &QPushButton::clicked, this, &Navigation::On_Entfernung_Clicked);
    connect(ui->information, &QPushButton::clicked, this, &Navigation::On_Information_Clicked);
    connect(ui->alleorte, &QPushButton::clicked, this, &Navigation::On_Alleorte_Clicked);
    connect(ui->berlin, &QRadioButton::pressed, this, &Navigation::On_Berlin_Clicked);
    connect(ui->bremen, &QRadioButton::pressed, this, &Navigation::On_Bremen_Clicked);
    connect(ui->dresden, &QRadioButton::pressed, this, &Navigation::On_Dresden_Clicked);
    connect(ui->hda, &QRadioButton::pressed, this, &Navigation::On_Hda_Clicked);
    connect(ui->muenchen, &QRadioButton::pressed, this, &Navigation::On_Muenchen_Clicked);
    connect(ui->nuernberg, &QRadioButton::pressed, this, &Navigation::On_Nuernberg_Clicked);
    connect(ui->saarbruecken, &QRadioButton::pressed, this, &Navigation::On_Saarbruecken_Clicked);
    connect(ui->stuttgart, &QRadioButton::pressed, this, &Navigation::On_Stuttgart_Clicked);
    clickedpoi_.clear();
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::On_Entfernung_Clicked()
{
    Entfernung* ent = new Entfernung(clickedpoi_);
    ent->show();
}
void Navigation::On_Information_Clicked()
{
    QVector<Point_Of_Interest*> list = QVector<Point_Of_Interest*>::fromStdVector(clickedpoi_);
    Ergebnis* liste = new Ergebnis(list);
    liste->show();
}
void Navigation::On_Alleorte_Clicked()
{
//    QVector<Point_Of_Interest*> list = QVector<Point_Of_Interest*>::fromStdVector(*poi_);
    Anzeigen* liste = new Anzeigen(*poi_, *adr_);
    liste->show();
}

void Navigation::On_Berlin_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->berlin->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Berlin")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            size = clickedpoi_.size();
            if(clickedpoi_[i]->Name() == "Berlin")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }

}

void Navigation::On_Nuernberg_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->nuernberg->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Nuernberg")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Nuernberg")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Saarbruecken_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->saarbruecken->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Saarbruecken")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Saarbruecken")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Hda_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->hda->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "H-da")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "H-da")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Dresden_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->dresden->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Dresden")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Dresden")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Muenchen_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->muenchen->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Muenchen")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Muenchen")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Stuttgart_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->stuttgart->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Stuttgart")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Stuttgart")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
void Navigation::On_Bremen_Clicked()
{
    int size = poi_->size();
    int index = -1;
    if(!ui->bremen->isChecked())
    {
        for(int i = 0; i < size; i++)
        {
            if(poi_->at(i)->Name() == "Bremen")
            {
                index = i;
                break;
            }
        }
        if(index != -1)
            clickedpoi_.push_back(poi_->at(index));
    }
    else
    {
        size = clickedpoi_.size();
        for(int i = 0; i < size; i++)
        {
            if(clickedpoi_[i]->Name() == "Bremen")
            {
                index = i;
                break;
            }
        }
        clickedpoi_.erase(clickedpoi_.begin() + index);
    }
}
