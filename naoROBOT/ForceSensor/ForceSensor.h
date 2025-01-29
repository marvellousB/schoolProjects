ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "NaoRobotAPI.h"
#include <iostream>
#include <time.h> 
#include <stdlib.h>

class ForceSensor :public NaoRobotAPI {
private:
    double footForce;  // Ayak tabanýndaki kuvvet deðerini saklamak için özel bir deðiþken

public:
    // Kurucu fonksiyon, baþlangýçta kuvvet deðerini boþ olarak tanýmlar
    ForceSensor();

    // Robota ait güncel sensör deðerini güncelleyen fonksiyon
    void updateSensor();
    // Sensörün güncel kuvvet bilgisini döndüren fonksiyon
    double getForce();

    // Robotun düþüp düþmediðini kontrol eden fonksiyon
    bool checkFall();

};

#endif