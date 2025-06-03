/*
 * Name        : Lab 19
 * Author      : Amara Ihekwoeme
 * Description : Making class, private data members, public functions
 * Sources     : Luke Sathrum
 */
#ifndef lab_19_
#define lab_19_
#include "sl_node.h"
#include <string>
#include <iostream>
#include <cstddef>
#include <sstream>
using std::stringstream;
using std::string;

class SLList {
 public:
// Constructor
SLList();
// Destructor
~SLList();
/* Functions */
void InsertHead(int head_value);
void InsertTail(int tail_value);
void RemoveHead();
void RemoveTail();
int GetHead() const;
int GetTail() const;
void Clear();
unsigned int size() const;
string ToString() const;
 private:
// Points to first node
SLNode* head_;
// Points to last node
SLNode* tail_;
// # of nodes
unsigned int size_;
};
#endif /*lab_18_*/
