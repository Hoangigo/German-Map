#include "Point_Of_Interest.h"

Point_Of_Interest::Point_Of_Interest()
{

}

Point_Of_Interest::~Point_Of_Interest()
{

}

Point_Of_Interest::Point_Of_Interest(int id, string typ, double x, double y, string kategorie, string bemerkung, string name) : Ort(x, y, typ, name)
{
    this->kategorie_ = kategorie;
    this->bemerkung_ = bemerkung;
    this->poiid_ = id;
}
string Point_Of_Interest::Kategorie()
{
    return this->kategorie_;
}

string Point_Of_Interest::Bemerkung()
{
    return this->bemerkung_;
}

int Point_Of_Interest::PoiId()
{
    return this->poiid_;
}
