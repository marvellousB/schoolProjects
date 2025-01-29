#include "Record.h"
#include <cassert>
#include <iostream>

int main() {

    Record myRecord;    ///< Create a Record object.


    myRecord.setFileName("testFile.txt");    ///< Set file name.

    ///< Open the file.
    assert(myRecord.openFile() == true);
    std::cout << "File opened successfully." << std::endl;

    ///< Write to the file.
    assert(myRecord.writeLine("This is a test line.") == true);
    std::cout << "Line written successfully." << std::endl;

    ///< Close and re-open the file to read.
    assert(myRecord.closeFile() == true);
    assert(myRecord.openFile() == true);

    ///< Read from the file.
    std::string line = myRecord.readLine();
    assert(line == "This is a test line.");
    std::cout << "Line read successfully: " << line << std::endl;

    ///< Close the file.
    assert(myRecord.closeFile() == true);
    std::cout << "File closed successfully." << std::endl;

    return 0;
}