/**
* @file BumperSensor.cpp
* @brief Class for handling bumper sensor data in a robot.
*
* This class is responsible for managing and interpreting the data from bumper sensors,
* allowing for detection of touches or collisions. It utilizes NaoRobotAPI for sensor interactions.
* It includes methods for updating sensor readings, checking for touches, and retrieving specific sensor states.
*
* @author [Mustafa Tekfidan](mailto:mustafatekfidan1@gmail.com)
* @version 1.5
* @date 2023-12-31
*/

#include <iostream>
#include "BumperSensor.h"
#include "NaoRobotAPI.h"
#include <webots/TouchSensor.hpp>
#include <webots/Robot.hpp>
using namespace std;

NaoRobotAPI* naoRobot;

BumperSensor::BumperSensor() {
	states[0] = false;
	states[1] = false;
	states[2] = false;
	states[3] = false;

}

void BumperSensor::updateSensor() {

	naoRobot->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);

	states[0] = leftFoot_left;
	states[1] = leftFoot_right;
	states[2] = rightFoot_left;
	states[3] = rightFoot_right;

}

bool BumperSensor::checkTouch() {
	
	updateSensor();
	if (states[0] == 1 || states[1] == 1 || states[2] == 1 || states[3] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BumperSensor::getState(int index) {
	updateSensor();
	if (states[index] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void BumperSensor::printSensorInfo() {
	cout << leftFoot_left << " " << leftFoot_right << " " << rightFoot_left << " " << rightFoot_right << " " << endl;
	Sleep(2500);
	return;
}


