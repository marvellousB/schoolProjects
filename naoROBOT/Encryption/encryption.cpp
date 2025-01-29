#include<iostream>
#include "encryption.h"

using namespace std;

int Encryption::encrypt(int code) {


    // Convert the number to an array of digits
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = code % 10;
        code /= 10;
    }

    // Replace each digit with the result of adding 7 to the third digit
    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 7) % 10;
    }

    // Swap the second digit with the fourth digit
    int temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;

    temp = digits[2];
    digits[2] = digits[0];
    digits[0] = temp;

    // Convert the array of digits back to an integer
    int encryptedNumber = 0;
    for (int i = 0; i < 4; ++i) {
        encryptedNumber = encryptedNumber * 10 + digits[i];
    }

    return encryptedNumber;

}



int Encryption::decrypt(int code){

    // Convert the number to an array of digits
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = code % 10;
        code /= 10;
    }

    // Swap the second digit with the fourth digit
    int temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;

    // Swap the first digit with the third digit (reverse of encryption)
    temp = digits[2];
    digits[2] = digits[0];
    digits[0] = temp;

    // Replace each digit with the result of subtracting 7 and taking the result modulo 10
    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10;
    }

    // Convert the array of digits back to an integer
    int decryptedNumber = 0;
    for (int i = 0; i < 4; ++i) {
        decryptedNumber = decryptedNumber * 10 + digits[i];
    }

    return decryptedNumber;

};