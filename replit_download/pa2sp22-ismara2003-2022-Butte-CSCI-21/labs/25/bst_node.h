/*
 * Name        : Lab 23 h file
 * Author      : Amara Ihekwoeme
 * Description : Introduction to Trees
 * Sources     : Luke Santhrum
 */
#ifndef lab_23_
#define lab_23_
#include <iostream>
#include <string>
#include <cstddef>
// using std::cout;
// using std::cin;
// using std::endl;
// using std::string;
class BSTNode {
 public:
// Constructor
BSTNode();
// Overloaded Constructor
BSTNode(int contents);
// Destructor
~BSTNode();
// Mutator
void SetContents(int contents);
// Accessor
int GetContents() const;
int& GetContents();
// Mutator
void SetLeftChild(BSTNode* left_child);
void SetRightChild(BSTNode* right_child);
// Accessors
BSTNode* GetLeftChild() const;
BSTNode*& GetLeftChild();
BSTNode* GetRightChild() const;
BSTNode*& GetRightChild();

 private:
BSTNode* left_child_;
BSTNode* right_child_;
int contents_;
};
#endif /*lab_23_*/
