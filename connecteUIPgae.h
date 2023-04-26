#ifndef CONNECTEUIPGAE_H
#define CONNECTEUIPGAE_H
#include "planntingtrip.h"
#include "loginpage.h"
#include "displaypage.h"
#include "dbmanager.h"
#include "maintenancepage.h"
#include "differentdistance.h"

class ConnecteUIPage{
public :
    void linkToLoginPage(){
        loginPage loginUI;
        loginUI.setModal(true);
        loginUI.exec();
    };

    void linkToDisplayPage(){
        DisplayPage displayUI;
        displayUI.setModal(true);
        displayUI.exec();
    };

    void linkToPlanTripPage(){
        PlanntingTrip planTripUI;
        planTripUI.setModal(true);
        planTripUI.exec();
    };

    void linkToMainrenancePage(){
        maintenancePage maintenaceUI;
        maintenaceUI.setModal(true);
        maintenaceUI.exec();
    };

    void linkToDifferentDistance(){
        DifferentDistance distanceUI;
        distanceUI.setModal(true);
        distanceUI.exec();
    }

};


#endif // CONNECTEUIPGAE_H
