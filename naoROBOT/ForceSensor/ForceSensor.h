ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "NaoRobotAPI.h"
#include <iostream>
#include <time.h> 
#include <stdlib.h>

class ForceSensor :public NaoRobotAPI {
private:
    double footForce;  // Ayak taban�ndaki kuvvet de�erini saklamak i�in �zel bir de�i�ken

public:
    // Kurucu fonksiyon, ba�lang��ta kuvvet de�erini bo� olarak tan�mlar
    ForceSensor();

    // Robota ait g�ncel sens�r de�erini g�ncelleyen fonksiyon
    void updateSensor();
    // Sens�r�n g�ncel kuvvet bilgisini d�nd�ren fonksiyon
    double getForce();

    // Robotun d���p d��medi�ini kontrol eden fonksiyon
    bool checkFall();

};

#endif