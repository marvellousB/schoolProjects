/**
*	@file Record.h
*	@brief Class for handling file records.
*
*	This class is responsible for opening, reading from, writing to,
*	and closing files using file streams.
*
*	@author [Mustafa Ozgur](mailto:mustafazgr99@gmail.com)
*	@version 1.0
*	@date 2023-12-22
*/

#ifndef RECORD_H_
#define RECORD_H_

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Record
{
	/**
	* @brief Overload the output stream operator for Record Objects.
	* 
	* Allows Record objects to be output to standart streams (like cout).
	* Typically used for printing or logging object states.
	* 
	* @param out Reference to the output stream.
	* @param record Constant reference to the Record object to output.
	* @return Reference to the output stream
	*/
	friend ostream& operator<<(ostream&, const Record&);

	/**
	* @brief Overload the input stream operator for Record Objects.
	*
	* Allows Record objects to be populated from standart streams (like cin).
	* Typically used for initializing or modifying object states.
	*
	* @param in Reference to the input stream.
	* @param record Reference to the Record object to populate.
	* @return Reference to the input stream
	*/
	friend istream& operator>>(istream&, Record&);

private:
	string fileName;	///< Name of the file to be handled.
	mutable fstream file;	///< File stream object for I/O operations.					

public:
	/**
	* @brief Open the file with fileName.
	* @return true if successful.
	*/
	bool openFile();

	/**
	* @brief Close the file.
	* @return true if successful.
	*/
	bool closeFile();

	/**
	* @brief Set the file name to the provided name.
	* @param fileName New name for the file.
	*/
	void setFileName(const string &fileNname);

	/**
	* @brief Read a line from the file.
	* @return the line.
	*/
	string readLine() const;

	/**
	* @brief Write a line to the file.
	* @param str The string to write to the file.
	* @return true if successful.
	*/
	bool writeLine(const string &str);
};

#endif