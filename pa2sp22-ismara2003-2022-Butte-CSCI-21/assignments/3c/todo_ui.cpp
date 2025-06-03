/*
 * Name        : Assignment 3c .cpp
 * Author      : Amara Ihekwoeme
 * Description : Using Pointers
                 Manage memory
                 Work with arrays
 * Sources     : Luke Sathrum
 */
#include "todo_ui.h"
// Constructor
TodoUI::TodoUI() {
  list_ = new TodoList;
}
// Destructor
TodoUI::~TodoUI() {
  delete list_;
}
// Member Functiom
void TodoUI::Menu() {
  cout << "Hello, you have reached your list" << endl;
  cout << "What would you like to do?" << endl;
int value = 0;
CinReader reader;
  /* Choices */
  // Create New Item
  while (value != 6) {
  cout << "Press 1 if you would like to add an item" << endl;
  if (list_->GetSize() != 0) {
  cout << "Press 2 if you would like to edit an item" << endl;
  cout << "Press 3 if you would like to view all items" << endl;
  cout << "Press 4 if you would like to view a specific item" << endl;
  cout << "Press 5 if you would like to delete all items on a list" << endl;
  }
  cout << "Press 6 if you would like to end the call" << endl;
  value = reader.readInt();
  if (value == 1) {
    cout << "You have chosen to add an item" << endl;
    cout << "What is the decription of the item you would like to add" << endl;
    string description = reader.readString();
    //
    cout << "What do you rate the priority from 1 - 5" << endl;
    int priority = reader.readInt(1, 5);
    //
    cout << "Is this item completed?" << endl;
    cout << "Type in false if incomplete" << endl;
    cout << "Type in true if completed" << endl;
    bool completed = reader.readBool();
    // Call AddItem
    list_->AddItem(new TodoItem(description, priority, completed));
  }
  // Edit an Item
  if (value == 2) {
    cout << "You have chosen to edit an item" << endl;
    cout << "Which number on the list would you like to edit?" << endl;
    unsigned int number = reader.readInt(1, list_->GetSize());
    // Get a pointer to the item to edit
    TodoItem *item = list_->GetItem(number);
    cout << "Which attribute would you like to edit" << endl;
    cout << "Press 1 if you would like to edit the description" << endl;
    cout << "Press 2 if you would like to edit the priority" << endl;
    cout << "Press 3 if you would like to edit the completion status" << endl;
    int attribute = reader.readInt(1, 3);
    if (attribute == 1) {
      cout << "You have chosen to edit the description" << endl;
      cout << "Type the description" << endl;
      string description = reader.readString();
      // call the function to change the description
      item->set_description(description);
    } else if (attribute == 2) {
      cout << "You have chosen to edit the priority" << endl;
      cout << "Type the priority" << endl;
      int priority = reader.readInt(1, 5);
      // call the function
      item->set_priority(priority);
    } else {
      cout << "You have chosen to change the completion status" << endl;
      cout << "If completed, type false" << endl;
      cout << "If incomplete, press true" << endl;
      // if they put a decimal... uh oh
      bool completed = reader.readBool();
      // call the function
      item->set_completed(completed);
    }
  }
  // View All Items
  if (value == 3) {
    cout << "You have chosen to view all your items" << endl;
    cout << "These are your items: " << endl;
    cout << *list_ << endl;
  }
  // View Specific Item
  if (value == 4) {
    cout << "You have chosen to view a specific item" << endl;
    cout << "Which number on the list would you like to see?" << endl;
    unsigned int number = reader.readInt(1, list_->GetSize());
    cout << "This is your item" << endl;
    // Use GetItem
    // Static Cast?
    cout << list_->GetItem(number)->description() << " ";
    cout << list_->GetItem(number)->priority() << " ";
    if (list_->GetItem(number)->completed()) {
    cout << "completed" << endl;
    } else {
      cout << "incompleted" << endl;
    }
  }
  // Delete All Items
  if (value == 5) {
    cout << "You have chosen to delete all items in the list" << endl;
    // Call Delete
    delete list_;
    list_ = new TodoList;
  }
  // Quit Program
  if (value == 6) {
    cout << "Thank you for calling" << endl;
    return;
  }
}
}
