#include <iostream>
#include "RobotOperator.h"
#include "encryption.h"

using namespace std;

Encryption encryption;

// Function to test the RobotOperator class
void testRobotOperator() {
    // Create an instance of RobotOperator
    RobotOperator robotOperator;

    // Test case 1: Correct access code and username
    int correctCode = 123;  // Replace with the actual correct access code
    string correctUsername = "admin";  // Replace with the actual correct username
    bool result1 = robotOperator.checkAccessCode(correctCode, correctUsername);
    cout << "Test Case 1 Result: " << (result1 ? "Access granted" : "Access denied") << endl;

    // Test case 2: Incorrect access code
    int incorrectCode = 456;  // Replace with an incorrect access code
    bool result2 = robotOperator.checkAccessCode(incorrectCode, correctUsername);
    cout << "Test Case 2 Result: " << (result2 ? "Access granted" : "Access denied") << endl;

    // Test case 3: Incorrect username
    string incorrectUsername = "user";  // Replace with an incorrect username
    bool result3 = robotOperator.checkAccessCode(correctCode, incorrectUsername);
    cout << "Test Case 3 Result: " << (result3 ? "Access granted" : "Access denied") << endl;
}

int main() {
    // Call the test function
    testRobotOperator();

    return 0;
}
