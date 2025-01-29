#include "RobotControl.h"
#include "SonarSensor.h"
#include "ForceSensor.h"
#include <iostream>
#include <cstdlib>
#include<webots/Robot.hpp>
#include<webots/PositionSensor.hpp>



void RobotControl::turnLeft() {
	nao->turnRobot(LEFT);
	Sleep(4000);
	return;

}
void RobotControl::turnRight() {
	nao->turnRobot(RIGHT);
	Sleep(4000);
	return;

}
void RobotControl::forward() {
	nao->moveRobot(FORWARD);
	Sleep(6000);
	return;

}
void RobotControl::backward() {
	nao->moveRobot(BACKWARD);
	Sleep(4000);
	return;

}
void RobotControl::moveLeft() {
	nao->moveRobot(LEFT);
	Sleep(4000);
	return;

}
void RobotControl::moveRight() {
	nao->moveRobot(RIGHT);
	Sleep(4000);
	return;

}

// part two

void RobotControl::getPose(double x,double y,double th) {
	pose->getPose(x, y, th);
}

void RobotControl::stop() {
	nao->stopRobot();
}

bool RobotControl::addToPath() {

}

void RobotControl::clearPath() {

}

bool RobotControl::recordPathToFile(){

}

bool RobotControl::openAccess(int code) {

}

bool RobotControl::closeAccess(int code){

}

bool RobotControl::recordSensor(string type) {

}

void RobotControl::printSensor(string type) {

}

void RobotControl::addSensor(SensorInterface* sensor) {

}








