/**
*	@file Encryption.h
*	@brief Class for handling encryption functions of Robot Operator class.
*
*	@author [Suleyman Guler](mailto:suleymangulerogu@gmail.com)
*	@version 1.0
*	@date 2023-12-22
*/



#pragma once
#include<iostream>

using namespace std;

class Encryption {


public:
    /**
    * @brief Encrypts the code.
    */
    int encrypt(int code);
    /**
    * @brief Decrypts the code.
    */
    int decrypt(int code);

};