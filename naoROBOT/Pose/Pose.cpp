/**
* 
*	@file Pose.cpp
*	@author Berivan Korlaelci (bkorlaelci1234@gmail.com)
*	@date December, 2023
*	@brief Implementation of Pose class.
*
*	This file implements the functionality declared in Pose.h. The Pose class
*	represents a 3D position and orientation. It includes methods for setting
*	and getting coordinates, as well as various operators for pose manipulation,
*	such as addition, subtraction, and comparison based on Euclidean distance.
*
*/

#include "Pose.h"

double d1, d2;

Pose::Pose() : x(0.0), y(0.0), th(0.0) {}

Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

void Pose::setX(double _x) {
	this->x = _x;
	return;
}
void Pose::setY(double _y) {
	this->y = _y;
	return;
}
void Pose::setTh(double _th) {
	this->th = _th;
	return;
}
bool Pose::operator==(const Pose& other) {
	if (x == other.x) {
		if (y == other.y) {
			if (th == other.th)
				return true;
		}
	}
	return false;
}
Pose Pose::operator+(const Pose& other) {
	Pose *p1 = new Pose;
	p1->x = x + other.x;
	p1->y = y + other.y;
	p1->th = th + other.th;
	return *p1;
}
Pose Pose::operator-(const Pose& other) {
	Pose* p1 = new Pose;
	p1->x = x - other.x;
	p1->y = y - other.y;
	p1->th = th - other.th;
	return *p1;
}
Pose& Pose::operator+=(const Pose& other) {
	x = x + other.x;
	y = y + other.y;
	th = th + other.th;
	return *this;
}
Pose& Pose::operator-=(const Pose& other) {
	x = x - other.x;
	y = y - other.y;
	th = th - other.th;
	return *this;
}
bool Pose::operator<(const Pose& other) {
	d1 = sqrt((x * x) + (y * y) + (th * th));
	d2 = sqrt((other.x * other.x) + (other.y * other.y) + (other.th * other.th));
	if (d1 < d2)
		return true;
	else
		return false;
}
void Pose::getPose(double& _x, double& _y, double& _th) const {
	_x = x;
	_y = y;
	_th = th;
	return;
}
void Pose::setPose(double _x, double _y, double _th) {
	x = _x;
	y = _y;
	th = _th;
	return;
}
double Pose::findDistanceTo(Pose pos) {
	return sqrt(pow((x - pos.x),2) + pow((y - pos.y),2) + pow((th - pos.th),2));
}
double Pose::findAngelTo(Pose pos) {
	return acos((x * pos.x) + (y * pos.y) + (th * pos.th) / sqrt((x + y + th) * (pos.x * pos.y * pos.th)));
}