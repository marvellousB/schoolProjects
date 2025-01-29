/**
* @file Record.cpp
* @brief Implementation of Record class.
*
* Provides the functionality declared in Record.h. This includes opening, reading from,
* writing to, and closing files using file streams, as well as overloading the input and
* output stream operators for Record objects.
*
* @author Mustafa Ozgur
* @version 1.0
* @date 2023-12-22
*/


#include "Record.h"

bool Record::openFile()
{
	file.open(fileName, ios::in | ios::out | ios::app);
	return file.is_open();
}

bool Record::closeFile()
{
	if (file.is_open())
	{
		file.close();
		return true;
	}
	
	return false;
}

void Record::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

string Record::readLine() const
{
	string line;
	if (getline(file, line))
	{
		return line;
	}

	return "failed to read.";
}

bool Record::writeLine(const string& str)
{
	if (file << str << endl)
	{
		return true;
	}

	return false;
}

ostream& operator<<(ostream& out, const Record& record)
{
	out << record.readLine();
	return out;
}

istream& operator>>(istream& in, Record& record)
{
	string input;
	if (getline(in, input))
	{
		record.writeLine(input);
	}
	return in;
}