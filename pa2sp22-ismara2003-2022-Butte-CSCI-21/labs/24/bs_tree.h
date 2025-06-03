/*
 * Name        : Lab 24 h file
 * Author      : Amara Ihekwoeme
 * Description : Introduction to Trees
 * Sources     : Luke Santhrum
 */
#ifndef lab_24_
#define lab_24_
#include <iostream>
#include <string>
#include <cstddef>
#include <sstream>
#include "bst_node.h"
using std::string;
using std::stringstream;
class BSTree {
 public:
// Constructor
BSTree();
// Destructor
~BSTree();
/* Functions */
bool Insert(int number);
void Clear();
unsigned int GetSize() const;
string InOrder();
 private:
// points to root node
BSTNode* root_;
// Holds number of nodes in tree
unsigned int size_;
bool Insert(int number, BSTNode*& subroot);
void Clear(BSTNode*& subroot);
string InOrder(BSTNode* subroot);
};
#endif /*lab_24_*/
