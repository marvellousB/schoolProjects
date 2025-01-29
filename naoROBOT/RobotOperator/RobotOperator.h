/**
*	@file RobotOperator.h
*	@brief Class for handling log in operations.
*
*	This class is responsible for checking user informations
*   while logging in to the robot control system.
*
*	@author [Suleyman Guler](mailto:suleymangulerogu@gmail.com)
*	@version 1.0
*	@date 2023-12-22
*/



#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class RobotOperator {


private:

	string name;///< Name of the user that trying to log in.
	int encryptedCode; ///< Encrypted code of the user.
	unsigned int accessCode; ///< User's code before being encrypted.
	



public:
	/**
	* @brief Constructor for RobotOperator class.
	*/
	RobotOperator();

	/**
	* @brief Chekcs access code 
	* Returns true if correct.
	* Returns false if not correct.
	*/
	bool checkAccessCode(int,string);




};