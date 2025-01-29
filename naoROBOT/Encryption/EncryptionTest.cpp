#include <iostream>
#include "encryption.h"

using namespace std;

// Function to test the Encryption class
void testEncryption() {
    // Create an instance of the Encryption class
    Encryption encryption;

    // Test case 1: Encrypt a code
    int originalCode = 1234;  // Replace with the actual code to be encrypted
    int encryptedCode = encryption.encrypt(originalCode);
    cout << "Test Case 1 - Original Code: " << originalCode << ", Encrypted Code: " << encryptedCode << endl;

    // Test case 2: Decrypt the encrypted code
    int decryptedCode = encryption.decrypt(encryptedCode);
    cout << "Test Case 2 - Encrypted Code: " << encryptedCode << ", Decrypted Code: " << decryptedCode << endl;

    // Test case 3: Attempt to decrypt an incorrect code
    int incorrectCode = 5678;  // Replace with an incorrect code
    int decryptedIncorrectCode = encryption.decrypt(incorrectCode);
    cout << "Test Case 3 - Incorrect Code: " << incorrectCode << ", Decrypted Incorrect Code: " << decryptedIncorrectCode << endl;
}

int main() {
    // Call the test function
    testEncryption();

    return 0;
}
