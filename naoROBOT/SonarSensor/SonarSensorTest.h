/**
 * @file SonarSensorTest.h
 * @brief The SonarSensorTest class is responsible for testing the SonarSensor class functionality.
 * 
 * @author Berivan Korlaelci (bkorlaelci1234@gmail.com)
 * @date December, 2023
 * 
 * This class contains a set of test functions to verify the correct behavior of the SonarSensor class.
 * 
 */

#ifndef SONARSENSORTEST_H
#define SONARSENSORTEST_H

#include "SonarSensor.h"
#include <cassert>

class SonarSensorTest {
public:
    /**
     * @brief Runs the tests for the SonarSensor class.
     */
    void runTests();

private:
    /**
     * @brief Tests the initialization of SonarSensor.
     *
     * This function checks if the SonarSensor is properly initialized after construction.
     */
    void testInitialization();

    /**
     * @brief Tests the updateSensor function of SonarSensor.
     *
     * This function checks if the updateSensor method updates the sensor values correctly.
     */
    void testUpdateSensor();

    /**
     * @brief Tests the getRange function of SonarSensor.
     *
     * This function checks if the getRange method returns valid distance values.
     */
    void testGetRange();

    /**
     * @brief Tests the getMax function of SonarSensor.
     *
     * This function checks if the getMax method returns the maximum distance value and index correctly.
     */
    void testGetMax();

    /**
     * @brief Tests the getMin function of SonarSensor.
     *
     * This function checks if the getMin method returns the minimum distance value and index correctly.
     */
    void testGetMin();

};

#endif
