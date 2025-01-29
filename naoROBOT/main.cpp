
//---------------------------------------------------------------------------------
//  Description:  Example controller program for Nao robot.
//                This demonstrates how to use NaoRobotAPI
//---------------------------------------------------------------------------------

#include "NaoRobotAPI.h"
#include "RobotControl.h"
#include "RobotOperator.h"
#include "BumperSensor.h"
#include "SonarSensor.h"
#include "Path.h"
#include "Pose.h"
#include "Record.h"
#include "ForceSensor.h"
#include <iostream>
#include <cstdlib>
#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>


using namespace std;

NaoRobotAPI* naoBot;
RobotControl robotControl;
RobotOperator robotOperator;
BumperSensor bumperSensor;
SonarSensor sonarSensor;
ForceSensor forceSensor;
Path path;
Pose pose;

int menuIndex;
void printMenu();
void Quit();
void writeToFile();


int distMin;
int distMax;
double x, y, th;

//void print() {
//
//	//Read sonar range values
//	double sonarLeft, sonarRight;
//	naoBot->getSonarRange(sonarLeft, sonarRight);
//
//	//Read foot bumper values
//	bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
//	naoBot->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
//
//	cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
//	cout << "POSE         : (X) " << naoBot->getX() << " meters, "
//		<< "(Y) " << naoBot->getY() << " meters, "
//		<< "(Th) " << naoBot->getTh() << " degrees" << endl << endl;
//	cout << "SONAR RANGES : (LEFT) " << sonarLeft
//		<< " meters, (RIGHT) " << sonarRight << " meters" << endl << endl;
//	cout << "FOOT FORCE   : " << naoBot->getFootForce() << " kg.f" << endl;
//	cout << "----------------------------------------------------------------------" << endl;
//
//}


void sensorMenu() {



	system("cls");

	cout << "1. Get bumper sensor info" << endl;
	cout << "2. Get maximum and minimum distance " << endl;
	cout << "3. Get robot's status" << endl;
	cout << "4. Get robot's position" << endl;
	cout << "5. Back" << endl;

	cin >> menuIndex;

	if (menuIndex == 1) {
		cout << "      Left Foot       " << "      Right Foot       " << endl;
		cout << "  ------------------- " << "  --------------------  " << endl;
		cout << " / " << bumperSensor.getState(0) << "               " << bumperSensor.getState(1) << " \\ " << "/ " << bumperSensor.getState(2) << "                " << bumperSensor.getState(3) << " \\ " << endl;
	    
		Sleep(4500);
		sensorMenu();
	}
	else if (menuIndex == 2) {
		
		sonarSensor.updateSensor();
		cout << "Max value of sensors is :  " << sonarSensor.getMax(distMax) << " and it stored in index: " << distMax << endl;
		cout << "Min value of sensors is :  " << sonarSensor.getMin(distMin) << " and it stored in index: " << distMin << endl;
	
		Sleep(4000);
		sensorMenu();
	}
	else if (menuIndex == 3) {
		
		if (forceSensor.checkFall()==true)
		{
			cout << "Robot has fallen! " << endl;
		}
		else if(forceSensor.checkFall()==false)
		{
			cout << "Robot has not fallen. " << endl;
		}
	

		Sleep(3000);
		sensorMenu();

	}
	else if (menuIndex == 4) {
		
		 x = naoBot->getX();
		 y = naoBot->getY();
		 th = naoBot->getTh();
		 
		 cout << "Robot's position's values: " << endl
			 << "X: " << x << endl
			 << "Y: " << y << endl
			 << "Angle: "<< th << endl;


		 Sleep(5000);
		 sensorMenu();
	}
	else if (menuIndex == 5) {
		printMenu();
	}
	

}

void connectionMenu() {

	//Printing connection menu

	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "          Connection Menu          " << endl;
	cout << "-----------------------------------" << endl;

	cout << "1.Connect" << endl;
	cout << "2.Disconnect" << endl;
	cout << "3.Back" << endl;


	cout << "Choose one: " << endl;
	cin >> menuIndex;

	// Connection handling

	if (menuIndex == 1) {
		cout << "Nao robot connecting..." << endl;
		naoBot->connect();
		cout << "Nao has connected..." << endl;
		Sleep(1000);
		printMenu();
	}
	else if (menuIndex == 2) {
		cout << "Nao robot disconnecting..." << endl;
		naoBot->disconnect();
		cout << "Nao robot has disconnected..." << endl;
		Sleep(1000);
		printMenu();
	}
	else if (menuIndex) {
		printMenu();
	}

}

void motionMenu() {

	//Printing motion menu

	system("cls");


	cout << "-----------------------------------" << endl;
	cout << "            Motion Menu            " << endl;
	cout << "-----------------------------------" << endl;

	cout << "1. Move Forward" << endl;
	cout << "2. Move Backward" << endl;
	cout << "3. Move Left" << endl;
	cout << "4. Move Right" << endl;
	cout << "5. Turn Left" << endl;
	cout << "6. Turn Right" << endl;
	cout << "7. Back" << endl;
	cout << "Choose one: " << endl;

	cin >> menuIndex;

	//Motion handling


	if (menuIndex == 1) {
		robotControl.forward();
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 2) {
		robotControl.backward();
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 3) {
		robotControl.moveLeft();
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 4) {
		robotControl.moveRight();
		Sleep(4000);
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 5) {
		robotControl.turnLeft();
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 6) {
		robotControl.turnRight();
		writeToFile();
		motionMenu();
	}
	else if (menuIndex == 7) {

		printMenu();
	}

	printMenu();
}

void printMenu() {

	// Printing main menu


	system("cls");

	cout << "-----------------------------------" << endl;
	cout << "             Main Menu             " << endl;
	cout << "-----------------------------------" << endl;

	cout << "1. Connection" << endl;
	cout << "2. Motion" << endl;
	cout << "3. Sensor" << endl;
	cout << "4. Quit" << endl;

	cout << "Choose one: " << endl;
	cin >> menuIndex;


	//Main menu handling

	if (menuIndex == 1) {
		connectionMenu();
	}
	else if (menuIndex == 2) {
		motionMenu();
	}
	else if (menuIndex == 3) {
		sensorMenu();
	}
	else if (menuIndex == 4) {
		Quit();
	}
	else
	{
		cout << "Non-valid input. Try again in 2 seconds..." << endl;
		Sleep(2000);
		printMenu();
	}
}


void logIn() {
	
	system("cls");

	string username;
	int code;
	
	cout << "Username:";
	cin >> username;

	cout << "Code: " ;
	cin >> code;

	if (robotOperator.checkAccessCode(code,username) == true) {
		cout << "Log in successful..." << endl;
		Sleep(1000);
		printMenu();
	}
	else
	{
		cout << "Wrong username or code." << endl;
		Sleep(2999);
		logIn();
	}
}

void Quit() {

	writeToFile();
	system("exit");

}

void writeToFile() {
	Record record;
	record.setFileName("RobotData.txt"); // Output file name.

	if (record.openFile()) {
		double x, y, th; // Position variables
		double sonarLeft, sonarRight; // Sonar variables
		bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right; // Bumper variables

		// Veri toplama
		naoBot->getSonarRange(sonarLeft, sonarRight);
		naoBot->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
		x = naoBot->getX();
		y = naoBot->getY();
		th = naoBot->getTh();

		// Veriyi yazdırma
		record.writeLine("Robot Position and Sensor Data:");
		record.writeLine("Position - X: " + to_string(x) + " Y: " + to_string(y) + " Th: " + to_string(th));
		record.writeLine("Sonar - Left: " + to_string(sonarLeft) + " Right: " + to_string(sonarRight));
		record.writeLine("Bumpers - LeftFoot Left: " + to_string(leftFoot_left) +
			" LeftFoot Right: " + to_string(leftFoot_right) +
			" RightFoot Left: " + to_string(rightFoot_left) +
			" RightFoot Right: " + to_string(rightFoot_right));
			record.writeLine( "---------------------------------------------------------------------");

		record.closeFile();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}


int main() {

	
	logIn();

	

	return 0;
}
