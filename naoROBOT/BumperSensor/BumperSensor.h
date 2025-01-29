#pragma once

/**
* @file BumperSensor.h
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


#ifndef BUMPERSENSOR_H
#define BUMPERSENSOR_H
#include <webots/DistanceSensor.hpp>
#include <webots/TouchSensor.hpp>
#include <webots/Robot.hpp>
#include <iostream>
#include "NaoRobotAPI.h"

class BumperSensor :public NaoRobotAPI {

public:
	/**
	* @brief Constructor for BumperSensor.
	*
	* Initializes the state of all four bumper sensors to false.
	*/
	BumperSensor();

	// Private deðerleri çekmek için kullanacaðým fonksiyon
	void setStates(bool leftFoot_left1,bool leftFoot_right1,bool rightFoot_left1,bool rightFoot_right1) {
		leftFoot_left = leftFoot_left1;
		leftFoot_right = leftFoot_right1;
		rightFoot_left = rightFoot_left1;
		rightFoot_right = rightFoot_right1;
	}


	/**
    * @brief Updates the sensor states from the NaoRobotAPI.
    *
	* Retrieves the state of each foot bumper and updates the sensor states accordingly.
	*/
	void updateSensor();

	/**
	* @brief Gets the state of a specific bumper sensor.
	*
	* @param index Index of the bumper sensor.
	* @return true if the specified sensor is touched; otherwise false.
	*/
	bool getState(int);

	/**
	* @brief Checks if any bumper sensor is touched.
	*
	* @return true if any sensor is touched; otherwise false.
	*/
	bool checkTouch();

	/**
	* @brief Prints the current states of all bumper sensors.
	*
	* Outputs the state of each bumper to the console and then waits for a short period.
	*/
	void printSensorInfo();

private:
	bool states[4] = { leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right };

	bool leftFoot_left;
	bool leftFoot_right;
	bool rightFoot_left;
	bool rightFoot_right;
};

#endif //BumperSensor.h

