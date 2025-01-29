#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H
#include <string>

using namespace std;

class SensorInterface  {
private:
string sensorType;
	
public:
	//SensorInterface() ;
	SensorInterface(string type) :sensorType(type) {};
	virtual void updateSensor()=0;
	string getSensorType()  { return sensorType; }
	virtual string getSensorValue() = 0;
	
};

#endif