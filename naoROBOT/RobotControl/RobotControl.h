/**
*	@file RobotControl.h
*	@brief Class for handling robot control operations.
*
*	This class is responsible for operationg the robot,
*   moving it based on the input.
*
*	@author [Suleyman Guler](mailto:suleymangulerogu@gmail.com)
*	@version 1.0
*	@date 2023-12-22
*/



#pragma once
#include<iostream>
#include<list>
#include "NaoRobotAPI.h"
#include "SensorInterface.h"
#include "Pose.h"

using namespace std;

SensorInterface* sensorInterface;
NaoRobotAPI* nao;
Pose* pose;



class RobotControl {

public:

	/**
	* @brief Turns the robot to left.
	*/
	void turnLeft();  

	/**
	* @brief Turns the robot to right.
	*/
	void turnRight(); 

	/**
	* @brief Makes the robot go forward.
	*/
	void forward();	  

	/**
	* @brief Makes the robot go backward.
	*/
	void backward(); 

	/**
	* @brief Makes the robot move left.
	*/
 	void moveLeft();  

	/**
	* @brief Makes the robot move right.
	*/
	void moveRight(); 

	// part two  / / / / / / / /  / /

	void getPose(double,double,double);

	void stop();

	bool addToPath();

	void clearPath();

	bool recordPathToFile();

	bool openAccess(int);

	bool closeAccess(int);

	bool recordSensor(string type);

	void printSensor(string type);

	void addSensor(SensorInterface* sensor);


	


private:

	list<SensorInterface*> sensorList;

	double x, y, th;


	

};