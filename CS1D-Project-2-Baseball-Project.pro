QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customtrip.cpp \
    dbmanager.cpp \
    differentdistance.cpp \
    displaypage.cpp \
    dodgerstadiumtrip.cpp \
    intputdata.cpp \
    loginpage.cpp \
    main.cpp \
    maintenancepage.cpp \
    mainwindow.cpp \
    marlinstrip.cpp \
    planntingtrip.cpp \
    receiptpage.cpp \
    souveniredit.cpp \
    shortcustomtrip.cpp \
    souvenirshop.cpp \
    stadiumedit.cpp

HEADERS += \
    connecteUIPgae.h \
    customtrip.h \
    dbmanager.h \
    differentdistance.h \
    displaypage.h \
    graph.h \
    dodgerstadiumtrip.h \
    intputdata.h \
    loginpage.h \
    maintenancepage.h \
    mainwindow.h \
    marlinstrip.h \
    planntingtrip.h \
    receiptpage.h \
    souveniredit.h \
    shortcustomtrip.h \
    souvenirshop.h \
    stadiumedit.h


FORMS += \
    customtrip.ui \
    differentdistance.ui \
    displaypage.ui \
    dodgerstadiumtrip.ui \
    intputdata.ui \
    loginpage.ui \
    maintenancepage.ui \
    mainwindow.ui \
    marlinstrip.ui \
    planntingtrip.ui \
    receiptpage.ui \
    souveniredit.ui \
    shortcustomtrip.ui \
    souvenirshop.ui \
    stadiumedit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ss.qrc

