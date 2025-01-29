#pragma once
// ForceSensor.h

#ifndef FORCE_SENSOR_H
#define FORCE_SENSOR_H

class NaoRobotAPI {
public:
    // NaoRobotAPI sýnýfýnýn burada tanýmlanmasý gerekiyor.
    // Örnek olarak þu þekilde düþünebilirsiniz:
    // double getFootForce();
};

class ForceSensor {
public:
    ForceSensor();
    void updateSensor(double newForce);
    float getFootForce() const;
    bool checkFall();

private:
    double footForce;
    NaoRobotAPI* Nao;
};

#endif // FORCE_SENSOR_H