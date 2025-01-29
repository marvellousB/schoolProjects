/**
 * @file PoseTest.h
 * @brief Class for testing the Pose class.
 * @author Berivan Korlaelci (bkorlaelci1234@gmail.com)
 * @date December, 2023
 */

#ifndef POSETEST_H
#define POSETEST_H

class PoseTest {
public:
    /**
     * @brief Runs all the tests.
     */
    static void runTests();

private:
    /**
     * @brief Test for checking equality of Poses.
     */
    static void testEquality();

    /**
     * @brief Test for addition of Poses.
     */
    static void testAddition();

    /**
     * @brief Test for subtraction of Poses.
     */
    static void testSubtraction();

    /**
     * @brief Test for Pose increment.
     */
    static void testIncrement();

    /**
     * @brief Test for Pose decrement.
     */
    static void testDecrement();

    /**
     * @brief Test for Pose comparison.
     */
    static void testComparison();

    /**
     * @brief Test for calculating distance between Poses.
     */
    static void testDistance();

    /**
     * @brief Test for calculating angle between Poses.
     */
    static void testAngle();
};

#endif