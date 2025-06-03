/*
 * Name        : Assignment 3a
 * Author      : Amara Ihekwoeme
 * Description : To do List part 2
                 Class
 * Sources     : Luke Sathrum
 */

#ifndef TODO_LIST
#define TODO_LIST

#include <iostream>
#include <string>
#include "todo_item.h"
#include <sstream>
using std::cout;
// using std::cin;
// using std::endl;
using std::string;
using std::stringstream;
using std::ostream;

class TodoList {
 public:
  // Constructor
  TodoList();
  // Destructor
  ~TodoList();
  // Functions
  /* similiar to lab 11
  friend ostream& operator <<(ostream &out, const Money  &amount); */
  friend ostream& operator <<(ostream &out, TodoList &list);
  // Mutator
  void AddItem(TodoItem* item);
  void DeleteItem(unsigned int delete_location);
  // Accessor
  TodoItem* GetItem(int retrieve_location);
  unsigned int GetSize();
  unsigned int GetCapacity();
  // functions
  void Sort();
  string ToFile();

 private:
  // Private Data Members
  // TodoItem* item;
  TodoItem** list;
  unsigned int capacity_;
  unsigned int size_;
  void increase_cap();
  void SwapValues(TodoItem* &value_1, TodoItem* &value_2);
};
#endif
