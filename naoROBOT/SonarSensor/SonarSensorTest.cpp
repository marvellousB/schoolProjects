/**
* 
*	@file SonarSensorTest.cpp
*   @brief This file implements the SonarSensorTest class.
*	
*   @author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	
*   This class includes the following functions to test the functionality of the SonarSensor 
*   class testInitialization, testUpdateSensor, testGetRange, testGetMax, and testGetMin.
*
*/

#include "SonarSensorTest.h"
#include <iostream>
#include <cassert>

using namespace std;

void SonarSensorTest::runTests() {
    testInitialization();
    testUpdateSensor();
    testGetRange();
    testGetMax();
    testGetMin();
}

void SonarSensorTest::testInitialization() {
    SonarSensor sonarSensor; 
    cout << "Initialization Test: " << (sonarSensor.getRange(0) == 0.0 ? "Passed" : "Failed") << "\n";
}

void SonarSensorTest::testUpdateSensor() {
    SonarSensor sonarSensor; 
    sonarSensor.updateSensor();
    cout << "Update Sensor Test: " << (sonarSensor.getRange(0) != 0.0 ? "Passed" : "Failed") << "\n";
}

void SonarSensorTest::testGetRange() {
    SonarSensor sonarSensor; 
    double range = sonarSensor.getRange(0);
    assert(range >= 0.0 && "Range should be non-negative");
    cout << "Get Range Test: " << (range >= 0.0 ? "Passed" : "Failed") << "\n";
}

void SonarSensorTest::testGetMax() {
    SonarSensor sonarSensor; 
    int maxIndex;
    double maxVal = sonarSensor.getMax(maxIndex);
    assert(maxVal >= 0.0 && maxIndex >= 0 && "Invalid max value or index");
    cout << "Get Max Test: " << (maxVal >= 0.0 && maxIndex >= 0 ? "Passed" : "Failed") << "\n";
}

void SonarSensorTest::testGetMin() {
    SonarSensor sonarSensor; 
    int minIndex;
    double minVal = sonarSensor.getMin(minIndex);
    assert(minVal >= 0.0 && minIndex >= 0 && "Invalid min value or index");
    cout << "Get Min Test: " << (minVal >= 0.0 && minIndex >= 0 ? "Passed" : "Failed") << "\n";
}
