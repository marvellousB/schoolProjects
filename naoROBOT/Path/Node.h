#ifndef NODE_H_
#define NODE_H_

#include "Pose.h"

/**
*	@file Node.h
*	@brief Structure of node.
*
*	This structure represents a node which can be used in linked lists.
*
*	@author [Mustafa Ozgur](mailto:mustafazgr99@gmail.com)
*	@version 1.0
*	@date 2023-12-28
*/

struct Node
{
	Node* next; ///< Pointer to the next node in the list.
	Pose pose;	///< The pose date stored in this node.
};

#endif