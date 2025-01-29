#include "ForceSensor.h"
#include <iostream>

ForceSensor::ForceSensor() : footForce(0.0) {} // Kurucu fonksiyon, ba�lang��ta kuvvet de�erini bo� olarak tan�mlar


NaoRobotAPI* naoR;

// Robota ait g�ncel sens�r de�erini g�ncelleyen fonksiyon
void ForceSensor::updateSensor() {
    footForce = naoR->getFootForce();
}

// Sens�r�n g�ncel kuvvet bilgisini d�nd�ren fonksiyon
double ForceSensor::getForce() {
    footForce = naoR->getFootForce();
    return footForce;
}

// Robotun d���p d��medi�ini kontrol eden fonksiyon
bool ForceSensor::checkFall() {
    // Kuvvet de�eri 2'den d���kse true d�nd�r
    //footForce = naoR->getFootForce();

    updateSensor();

    if (footForce < 2.0)
    {
        return true;
    }
    else
    {
        return false;
    }

}