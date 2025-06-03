/*
 * Name        : Assignment 4
 * Author      : Amara Ihekwoeme
 * Description : Doubly Linked List
 * Sources     : Luke Sathrum
 */
#ifndef DL_LIST
#define DL_LIST
#include <iostream>
#include <string>
#include <sstream>
#include "dl_node.h"
// using std::cout;
// using std::cin;
// using std::endl;
using std::string;
using std::stringstream;
class DLList {
 public:
// Constructor
DLList();
// Destructor
// - Calls Clear
~DLList();
// Accessor
unsigned int GetSize() const;
/* Public Functions*/
// Creates DLNode with contents of parameter
// and adds to the front of list
void PushFront(int contents);
// Creates DLNode with contents of parameter
// and adds to the end of list
void PushBack(int contents);
// Outputs value at beginning of list
// Output "List Empty" to standard error
// if list is empty and return 0
int GetFront() const;
// Outputs value at end of list
// Output "List Empty" to standard error
// if list is empty and return 0
int GetBack() const;
// Removes first node
// Outputs "List Empty" to standard error output
// if empty
void PopFront();
// Removes last node
// Outputs "List Empty" to standard error output
// if empty
void PopBack();
// Find "first" value to match, if found remove node
// If not found,
// output "Not Found" to standard error output
void RemoveFirst(int number);
// Find all values to match, if found remove node
// If not found,
// output "Not Found" to standard error output
void RemoveAll(int number);
// Find integer
// If found return true, else return false
bool Exists(int number);
// Clears all nodes in list
// Resets size to 0
// head_ and tail_ to NULL
void Clear();
// Output contents comma seperated
// from first node to last node
// If empty, return empty string
// and output "List Empty" to standard error output
string ToStringForwards();
string ToStringBackwards();

 private:
unsigned int size_;
DLNode* head_;
DLNode* tail_;
};
#endif /*DL_LIST*/
