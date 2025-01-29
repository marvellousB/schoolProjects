/**
*	@file Path.h
*	@brief Class for managing a sequence of nodes in a path.
*
*	Class that allows managing the route plan in linked list form.
*	Positions can be added to the list in Pose type.
*
*	@author [Mustafa Ozgur](mailto:mustafazgr99@gmail.com)
*	@version 1.0
*	@date 2023-12-28
*/

#ifndef PATH_H_
#define PATH_H

#include"Node.h"

class Path
{
private:
	Node* tail;	///< Pointer to the last node in the path.
	Node* head;	///< Pointer to the first node in the path.
	int number;	///< Number of nodes in the path.

public:
	/**
	* @brief Adds the given position to the end of the list.
	* @param pose Position to be added.
	*/
	void addPos(Pose pose);

	void print() const; ///< Prints the positions in the list to the screen.

	/**
	* @brief Returns position at the given index.
	* @param index Given index
	* @return Position at the index.
	*/
	Pose getPos(int index) const;

	/**
	* @brief Removes a position at the given index from the list.
	* @param index Given index.
	* @return True if successful.
	*/
	bool removePos(int index);

	/**
	* @brief Inserts a pose to the given index.
	* @param index The index at which insert the new pose.
	* @param pose The pose to insert.
	* @return True if successful.
	*/
	bool insertPost(int index, Pose pose);
};

#endif