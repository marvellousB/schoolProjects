#include "ForceSensor.h"
#include <iostream>

ForceSensor::ForceSensor() : footForce(0.0) {} // Kurucu fonksiyon, baþlangýçta kuvvet deðerini boþ olarak tanýmlar


NaoRobotAPI* naoR;

// Robota ait güncel sensör deðerini güncelleyen fonksiyon
void ForceSensor::updateSensor() {
    footForce = naoR->getFootForce();
}

// Sensörün güncel kuvvet bilgisini döndüren fonksiyon
double ForceSensor::getForce() {
    footForce = naoR->getFootForce();
    return footForce;
}

// Robotun düþüp düþmediðini kontrol eden fonksiyon
bool ForceSensor::checkFall() {
    // Kuvvet deðeri 2'den düþükse true döndür
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