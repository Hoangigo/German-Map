#ifndef POINT_OF_INTEREST_H
#define POINT_OF_INTEREST_H
#include <iostream>
#include "Ort.h"

using namespace std;

class Point_Of_Interest : public Ort
{
public:
    Point_Of_Interest();
    ~Point_Of_Interest();
    Point_Of_Interest(int poiid, string typ, double x, double y, string kategorie, string bemerkung, string name);
    string Kategorie();
    string Bemerkung();
    int PoiId();
private:
    string kategorie_;
    string bemerkung_;
    int poiid_;
};

#endif // POINT_OF_INTEREST_H
