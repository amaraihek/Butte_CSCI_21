/*
 * Name        : Lab 17
 * Author      : Amara Ihekwoeme
 * Description : Making class, private data members, public functions
 * Sources     : Luke Sathrum
 */

#ifndef lab_17_
#define lab_17_
#include <iostream>
#include <string>
#include <cstddef>
// using std::cout;
// using std::cin;
// using std::endl;
using std::string;

class SLNode {
 public:
// Constructor
SLNode();
// Overloaded constructor
SLNode(int contents);
// Destructor
~SLNode();
// Mutator
void set_contents(int contents);
void set_next_node(SLNode* next_node);
// Accessors
int contents() const;
SLNode* next_node() const;
 private:
  SLNode* next_node_;
  int contents_;
};
#endif /*lab_17_*/
