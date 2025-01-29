/**
*
*	@file PoseTest.cpp
*	@author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	@brief Implementation of PoseTest class.
*
*	This file implements tests for the PoseTest class, which represents a addition operator, 
*   subtraction operator, equality operator, distance calculation(findDistanceTo), 
*   and angle calculation (findAngelTo).
*
*/

#include "PoseTest.h"
#include "Pose.h"
#include <iostream>
#include <cmath>

using namespace std;

void PoseTest::runTests() {
    testEquality();
    testAddition();
    testSubtraction();
    testIncrement();
    testDecrement();
    testComparison();
    testDistance();
    testAngle();
}

void PoseTest::testEquality() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(1.0, 2.0, 0.5);

    if (pose1 == pose2) {
        cout << "Test 1: Pose 1 and Pose 2 are equal.\n";
    }
    else {
        cout << "Test 1: Pose 1 and Pose 2 are not equal.\n";
    }
}

void PoseTest::testAddition() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(2.0, 3.0, 1.0);

    Pose sum = pose1 + pose2;

    if (sum == Pose(3.0, 5.0, 1.5)) {
        cout << "Test 2: Addition test passed.\n";
    }
    else {
        cout << "Test 2: Addition test failed.\n";
    }
}

void PoseTest::testSubtraction() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(2.0, 1.0, 0.5);

    Pose diff = pose1 - pose2;

    if (diff == Pose(-1.0, 1.0, 0.0)) {
        cout << "Test 3: Subtraction test passed.\n";
    }
    else {
        cout << "Test 3: Subtraction test failed.\n";
    }
}

void PoseTest::testIncrement() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(2.0, 3.0, 1.0);

    pose1 += pose2;

    if (pose1 == Pose(3.0, 5.0, 1.5)) {
        cout << "Test 4: Increment test passed.\n";
    }
    else {
        cout << "Test 4: Increment test failed.\n";
    }
}

void PoseTest::testDecrement() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(2.0, 1.0, 0.5);

    pose1 -= pose2;

    if (pose1 == Pose(-1.0, 1.0, 0.0)) {
        cout << "Test 5: Decrement test passed.\n";
    }
    else {
        cout << "Test 5: Decrement test failed.\n";
    }
}

void PoseTest::testComparison() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(2.0, 3.0, 1.0);

    if (pose1 < pose2) {
        cout << "Test 6: Comparison test passed.\n";
    }
    else {
        cout << "Test 6: Comparison test failed.\n";
    }
}

void PoseTest::testDistance() {
    Pose pose1(1.0, 2.0, 0.5);
    Pose pose2(4.0, 6.0, 1.5);

    double distance = pose1.findDistanceTo(pose2);

    if (std::abs(distance - 5.0) < 1e-6) {
        cout << "Test 7: Distance test passed.\n";
    }
    else {
        cout << "Test 7: Distance test failed.\n";
    }
}

void PoseTest::testAngle() {
    Pose pose1(1.0, 0.0, 0.0);
    Pose pose2(0.0, 1.0, 0.0);

    double angle = pose1.findAngelTo(pose2);

    if (std::abs(angle - acos(-1.0) / 2) < 1e-6) {
        cout << "Test 8: Angle test passed.\n";
    }
    else {
        cout << "Test 8: Angle test failed.\n";
    }
}
