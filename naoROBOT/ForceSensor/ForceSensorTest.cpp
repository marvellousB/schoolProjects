// ForceSensorTest.cpp

// ForceSensorTest.cpp

#include "ForceSensor.h"
#include <iostream>
using namespace std;

void assertEqual(double actual, double expected, const string& testName) {
    if (actual == expected) {
        cout << testName << " - Passed" << endl;
    }
    else {
        cout << testName << " - Failed" << endl;
    }
}

int main() {
    // Testler

    ForceSensor forceSensor;

    // Test 1: InitialFootForceIsZero
    assertEqual(forceSensor.getFootForce(), 0.0, "InitialFootForceIsZero");

    // Test 2: UpdateSensor
    forceSensor.updateSensor(3.5);
    assertEqual(forceSensor.getFootForce(), 3.5, "UpdateSensor");

    // Test 3: CheckFallTrue
    // Assuming Nao->getFootForce() returns a value less than 2.0
    assertEqual(forceSensor.checkFall(), true, "CheckFallTrue");

    // Test 4: CheckFallFalse
    // Assuming Nao->getFootForce() returns a value greater than or equal to 2.0
    assertEqual(forceSensor.checkFall(), false, "CheckFallFalse");

    return 0;
}