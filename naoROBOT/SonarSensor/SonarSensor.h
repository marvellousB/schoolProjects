/**
*	@file SonarSensor.h
*	@author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	@brief Class for represents a sonar sensor for obtaining distance values.
*
*	This class is provides functionality to interact with sonar sensors on a robot.
*
*/

#ifndef SONARSENSOR_H
#define SONARSENSOR_H

#include "NaoRobotAPI.h"

using namespace std;

class SonarSensor :public NaoRobotAPI {
private:
	double ranges[2];		///< Array to store range values for left and right sensors.
	NaoRobotAPI* robotAPI;	///< Pointer to the RobotAPI object for communication with the robot.

public:
	/**
	 * @brief Default constructor for SonarSensor.
	 * Initializes the SonarSensor object by obtaining sonar range values from the robotAPI.
	 */
	SonarSensor();

	/**
	 * @brief Gets the range value of the specified sensor.
	 * @param index The index of the sensor (0 for left, 1 for right).
	 * @return The range value of the specified sensor.
	 */
	double getRange(int)const;

	/**
	 * @brief Gets the maximum range value among all sensors and its corresponding index.
	 * @param index Reference to the variable to store the index of the sensor with the maximum range.
	 * @return The maximum range value among all sensors.
	 */
	double getMax(int&)const;

	/**
	 * @brief Gets the minimum range value among all sensors and its corresponding index.
	 * @param index Reference to the variable to store the index of the sensor with the minimum range.
	 * @return The minimum range value among all sensors.
	 */
	double getMin(int&)const;

	/**
	 * @brief Updates the sensor values by obtaining the latest sonar range values from the robotAPI.
	 */
	void updateSensor();

	/**
	 * @brief Overloaded subscript operator to access the range values using index.
	 * @param i The index of the sensor (0 for left, 1 for right).
	 * @return The range value of the specified sensor.
	 */
	double operator[](int);
};

#endif