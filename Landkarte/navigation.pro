QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Adresse.cpp \
    Anlegen.cpp \
    Anzeigen.cpp \
    Entfernung.cpp \
    Navigationssystem.cpp \
    Ort.cpp \
    Point_Of_Interest.cpp \
    ergebnis.cpp \
    main.cpp \
    navigation.cpp

HEADERS += \
    Adresse.h \
    Anlegen.h \
    Anzeigen.h \
    Entfernung.h \
    Navigationssystem.h \
    Ort.h \
    Point_Of_Interest.h \
    ergebnis.h \
    navigation.h

FORMS += \
    Anlegen.ui \
    Anzeigen.ui \
    Entfernung.ui \
    Navigationssystem.ui \
    ergebnis.ui \
    navigation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    maps.qrc
