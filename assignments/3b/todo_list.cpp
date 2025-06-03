/*
 * Name        : Assignment 3a
 * Author      : Amara Ihekwoeme
 * Description : To do List part 2
                 Class
 * Sources     : Luke Sathrum
 */

#include "todo_list.h"

// Constructor
TodoList::TodoList() {
  // Create an array of 25 pointers to TodoItems
  list = new TodoItem*[25];
  // Sets capacity to 25
  capacity_ = 25;
  // Sets size to 0
  size_ = 0;
  // Set all of the pointers in the Array to NULL
  for (unsigned int i = 0; i < GetCapacity(); i++) {
    list[i] = NULL;
  }
}
// Destructor
TodoList::~TodoList() {
  // clears list
  // first arrows then array?
  for (unsigned int i = 0; i < GetSize(); i++) {
    delete list[i];
  }
  delete[] list;
}
// Friend Function
ostream& operator <<(ostream &out, TodoList &list) {
  for (unsigned int i = 0; i < list.GetSize(); i++) {
    out << list.list[i]->description() << ' '
        << list.list[i]->priority() << ' '
        << list.list[i]->completed();
  }
  return out;
}

void TodoList::AddItem(TodoItem* item) {
  // Add item if space
  if (GetSize() < GetCapacity()) {
    list[GetSize()] = item;
    size_++;
  } else if (GetSize() == GetCapacity()) {
    increase_cap();
    list[GetSize()] = item;
    size_++;
  }
}
void TodoList::DeleteItem(unsigned int delete_location) {
  // delete location
  if (delete_location <= GetSize() && delete_location != 0) {
    delete list[delete_location - 1];
    // compacting array
    for (unsigned int i = delete_location - 1; i < GetSize() - 1; i++) {
      list[i] = list[i+1];
      if (i == GetSize() - 1) {
        list[i] = NULL;
      }
    }
    size_--;
  }
}
TodoItem* TodoList::GetItem(int retrieve_location) {
  // Get location if viable
  if (retrieve_location > 0
      && retrieve_location <= static_cast<int>(GetSize())) {
    return list[retrieve_location - 1];
  }
  return NULL;
}
unsigned int TodoList::GetSize() {
  return size_;
}
unsigned int TodoList::GetCapacity() {
  return capacity_;
}
void TodoList::Sort() {
  // Bubble Sort
  bool swapped;
  for (unsigned int i = size_- 1; i >= 1; i--) {
    swapped = false;
    for (unsigned int j = 0; j <= i -1; j++) {
      // Biggest priority comes before, if not swap
      if (list[j]->priority() > list[j+1]->priority()) {
        SwapValues(list[j], list[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
}

string TodoList::ToFile() {
  stringstream ss;
  // looping thru list and outputting contents
  for (unsigned int i = 0; i < size_; i++) {
    ss << list[i]->ToFile() << std::endl;
  }
  return ss.str();
}

void TodoList::increase_cap() {
  // Creating an array
  TodoItem** new_array = new TodoItem*[capacity_ + 10];
  // looping thru and copying the elements
  for (unsigned int i = 0; i < size_; i++) {
    new_array[i] = list[i];
  }
  // What is the new capacity?
  capacity_ = capacity_ + 10;
  // Get rid of the old array
  delete[] list;
  // Assign the new array to list_
  list = new_array;
}

void TodoList::SwapValues(TodoItem* &value_1, TodoItem* &value_2) {
  TodoItem* value_3;
  value_3 = value_1;
  value_1 = value_2;
  value_2 = value_3;
}
