/*
 * Name        : Assignment 3c .h
 * Author      : Amara Ihekwoeme
 * Description : Using Pointers
                 Manage memory
                 Work with arrays
 * Sources     : Luke Sathrum
 */
#include <iostream>
#include <string>
#include <sstream>
#include "CinReader.h"
#include "todo_list.h"
using std::stringstream;
// using std::cout;
// using std::cin;
// using std::endl;
// using std::string;

class TodoUI {
 public:
// Constructor
TodoUI();
// Destructor
~TodoUI();
// Member Functiom
void Menu();
 private:
// Instance of CinReader
CinReader Reader_;
// Dynamic Instance of TodoList (new?)
TodoList* list_;
};
