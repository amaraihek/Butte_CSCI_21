/*
 * Name        : Assignment 4
 * Author      : Amara Ihekwoeme
 * Description : Doubly Linked List
 * Sources     : Luke Sathrum
 */
#ifndef DL_NODE
#define DL_NODE
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
// using std::cout;
// using std::cin;
// using std::endl;
class DLNode {
 public:
// Constructor
DLNode();
// Destructor
~DLNode();
/* Mutators */
void SetContents(int contents);
void SetNext(DLNode* next_node);
void SetPrevious(DLNode* previous_node);
/* Accessors */
int GetContents();
DLNode* GetNext() const;
DLNode* GetPrevious() const;
 private:
int contents_;
DLNode* previous_node_;
DLNode* next_node_;
};
#endif /*DL_NODE*/
