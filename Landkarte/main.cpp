#include "navigation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Navigationssystem w;
    w.show();
    return a.exec();
}
