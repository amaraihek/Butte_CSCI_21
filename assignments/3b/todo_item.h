/*
 * Name        : Assignment 3a
 * Author      : Amara Ihekwoeme
 * Description : To do List part 1
 * Sources     : Luke Sathrum
 */

#ifndef TODO_ITEM
#define TODO_ITEM

#include <iostream>
#include <string>
#include <sstream>
// using std::cout;
// using std::cin;
// using std::endl;
using std::string;
using std::stringstream;
class TodoItem {
 public:
// Member Function
string ToFile();
// Constructor
TodoItem(string description = "", int priority = 1, bool completed = false);
// Accessors
string description();
int priority();
bool completed();
// Mutators
void set_description(string description);
void set_priority(int priority);
void set_completed(bool completed);

 private:
string description_;
int priority_;
bool completed_;
string Scrub(string description);
};
#endif
