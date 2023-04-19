QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    displaypage.cpp \
    loginpage.cpp \
    main.cpp \
    maintenancepage.cpp \
    mainwindow.cpp \
    planntingtrip.cpp

HEADERS += \
    displaypage.h \
    loginpage.h \
    maintenancepage.h \
    mainwindow.h \
    planntingtrip.h

FORMS += \
    displaypage.ui \
    loginpage.ui \
    maintenancepage.ui \
    mainwindow.ui \
    planntingtrip.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
