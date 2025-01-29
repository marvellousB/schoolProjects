#include "RobotControl.h"
#include "NaoRobotAPI.h"  // Include the necessary headers for your dependencies
#include "SonarSensor.h"
#include "ForceSensor.h"
#include <iostream>
#include <cstdlib>
#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>

using namespace std;

// Function to test the RobotControl class
void testRobotControl() {
    // Create an instance of NaoRobotAPI (replace with actual instantiation logic if needed)

    NaoRobotAPI* nao;

    // Create an instance of RobotControl
    RobotControl robotControl;

    // Perform some actions using RobotControl methods
    robotControl.turnLeft();
    cout << "Turned left." << endl;

    robotControl.turnRight();
    cout << "Turned right." << endl;

    robotControl.forward();
    cout << "Moved forward." << endl;

    robotControl.backward();
    cout << "Moved backward." << endl;

    robotControl.moveLeft();
    cout << "Moved left." << endl;

    robotControl.moveRight();
    cout << "Moved right." << endl;
}

int main() {
    // Call the test function
    testRobotControl();

    return 0;
}
