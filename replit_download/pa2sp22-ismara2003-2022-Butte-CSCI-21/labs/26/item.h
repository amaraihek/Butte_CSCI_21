/*
 * Name        : Lab 26
 * Author      : Amara Ihekwoeme
 * Description : Inheritance
 * Sources     : Luke Sathrum
 */
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <sstream>
using std::ostringstream;
using std::string;
using std::ostream;
// using std::cout;
// using std::cin;
// using std::endl;
// using std::stringstream;

class Item {
 public:
  Item(string name = "item", unsigned int value = 0);
  // Destructor
  ~Item();
  // Accessor
  string name();
  unsigned int value();
  // Mutator
  void set_name(string name);
  void set_value(unsigned int value);
  // Functions
  string ToString();
 private:
  string name_;
  unsigned int value_;
};

#endif /* ITEM_H */
