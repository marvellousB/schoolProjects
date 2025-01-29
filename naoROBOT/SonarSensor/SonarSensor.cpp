/**
*
*	@file SonarSensor.h
*	@author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	@brief Implementation of Sonar class.
*
*	This file implements the functionality declared in Pose.h.
*	It allows retrieving distance values from left and right sensors, finding the maximum and
*	minimum values among sensors, and updating sensor values from the robot's API.
*
*/


#include "SonarSensor.h"
#include<iostream>
using namespace std;

SonarSensor::SonarSensor() {
	robotAPI->getSonarRange(ranges[0], ranges[1]);
}

double SonarSensor::getRange(int index) const {
	return ranges[index];
}

double SonarSensor::getMax(int& index) const {
	double maxVal = ranges[0];

	for (int i = 0; i < 2; i++) {
		if (ranges[i] > maxVal) {
			maxVal = ranges[i];
			index = i;
		}
	}

	return maxVal;
}

double SonarSensor::getMin(int& index) const {
	double minVal = ranges[0];

	for (int i = 0; i < 2; i++) {
		if (ranges[i] < minVal) {
			minVal = ranges[i];
			index = i;
		}
	}

	return minVal;
}

void SonarSensor::updateSensor() {
	robotAPI->getSonarRange(ranges[0], ranges[1]);
	return;
}

double SonarSensor::operator[](int i) {
	return ranges[i];
}