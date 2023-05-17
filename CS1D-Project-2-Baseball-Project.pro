QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    displaypage.cpp \
    graph.cpp \
    intputdata.cpp \
    loginpage.cpp \
    main.cpp \
    maintenancepage.cpp \
    mainwindow.cpp \
    planntingtrip.cpp \
    souveniredit.cpp \
    souvenirshop.cpp \
    stadiumedit.cpp

HEADERS += \
    connecteUIPgae.h \
    dbmanager.h \
    displaypage.h \
    graph.h \
    intputdata.h \
    loginpage.h \
    maintenancepage.h \
    mainwindow.h \
    planntingtrip.h \
    souveniredit.h \
    souvenirshop.h \
    stadiumedit.h


FORMS += \
    displaypage.ui \
    intputdata.ui \
    loginpage.ui \
    maintenancepage.ui \
    mainwindow.ui \
    planntingtrip.ui \
    souveniredit.ui \
    souvenirshop.ui \
    stadiumedit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ss.qrc
