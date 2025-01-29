/**
*	@file Pose.h
*	@author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	@brief Class for representing a Pose in 3D space.
*
*	This class is encapsulates 3D position (X, Y) and orientation (theta),
*	serving as a fundamental tool in robotics and computer graphics.
*
*/

#ifndef POSE_H
#define POSE_H

#include<iostream>
#include <cmath>

using namespace std;

/**
* @brief Class representing a Pose in 3D space.
*/
class Pose {
private:
	double x;	/**< X-coordinate of the pose. */
	double y;	/**< Y-coordinate of the pose. */
	double th;	/**< Angle (theta) of the pose. */

public:
	/**
	* @brief Default constructor for Pose class.
	*
	* Initializes the pose with default values (0, 0, 0).
	*/
	Pose();

	/**
	* @brief Parameterized constructor for Pose class.
	*
	* Initializes the pose with the specified values.
	*
	* @param _x The X-coordinate of the pose.
	* @param _y The Y-coordinate of the pose.
	* @param _th The angle (theta) of the pose.
	*/
	Pose(double _x, double _y, double _th);

	/**
	 * @brief Get the X-coordinate of the pose.
	 * @return X-coordinate value.
	 */
	double getX() const { return x; }
	
	/**
	 * @brief Get the Y-coordinate of the pose.
	 * @return Y-coordinate value.
	 */
	double getY() const { return y; };

	/**
	 * @brief Get the angle (theta) of the pose.
	 * @return Angle value.
	 */
	double getTh() const { return th; };
	
	/**
	 * @brief Setter for the X-coordinate of the pose.
	 * @param _x New X-coordinate value.
	 */
	void setX(double);
	
	/**
	* @brief Setter for the Y-coordinate of the pose.
	* @param _y New Y-coordinate value.
	*/
	
	void setY(double);

	/**
	 * @brief Setter for the angle (theta) of the pose.
	 * @param _th New angle value.
	 */
	void setTh(double);

	/**
	 * @brief Equality comparison operator.
	 * @param other Another pose to compare with.
	 * @return True if the poses are equal, false otherwise.
	 */
	bool operator==(const Pose&);

	/**
	 * @brief Addition operator for poses.
	 * @param other Another pose to add.
	 * @return New pose resulting from the addition.
	 */
	Pose operator+(const Pose&);

	/**
	* @brief Subtraction operator for poses.
	* @param other Another pose to subtract.
	* @return New pose resulting from the subtraction.
	*/
	Pose operator-(const Pose&);

	/**
	 * @brief In-place addition operator for poses.
	 * @param other Another pose to add.
	 * @return Reference to the modified pose.
	 */
	Pose& operator+=(const Pose&);

	/**
	 * @brief In-place subtraction operator for poses.
	 * @param other Another pose to subtract.
	 * @return Reference to the modified pose.
	 */
	Pose& operator-=(const Pose&);

	/**
	 * @brief Less-than comparison operator based on Euclidean distance.
	 * @param other Another pose to compare with.
	 * @return True if the distance of this pose is less than the distance of the other pose, false otherwise.
	 */
	bool operator<(const Pose&);

	/**
	 * @brief Get the X, Y, and theta values of the pose.
	 * @param _x Reference to store the X-coordinate.
	 * @param _y Reference to store the Y-coordinate.
	 * @param _th Reference to store the angle (theta).
	 */
	void getPose(double& _x, double& _y, double& _th) const;

	/**
	 * @brief Set the X, Y, and theta values of the pose.
	 * @param _x New X-coordinate value.
	 * @param _y New Y-coordinate value.
	 * @param _th New angle (theta) value.
	 */
	void setPose(double, double, double);

	/**
	 * @brief Calculate the Euclidean distance between two poses.
	 * @param pos Another pose to calculate the distance to.
	 * @return Euclidean distance between this pose and the specified pose.
	 */
	double findDistanceTo(Pose);

	/**
	 * @brief Calculate the angle between two poses using the dot product.
	 * @param pos Another pose to calculate the angle to.
	 * @return Angle between this pose and the specified pose in radians.
	 */
	double findAngelTo(Pose);

};

#endif