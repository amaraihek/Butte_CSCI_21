/*
 * Name        : Assignment 3a
 * Author      : Amara Ihekwoeme
 * Description : To do List part 1
                 Class
 * Sources     : Luke Sathrum
 */

#include "todo_item.h"

// Constructor
TodoItem::TodoItem(string description, int priority, bool completed) {
  set_description(description);
  set_priority(priority);
  set_completed(completed);
}


// Accessor function
string TodoItem::description() {
  return description_;
}
int TodoItem::priority() {
  return priority_;
}
bool TodoItem::completed() {
  return completed_;
}

// Mutator Function
void TodoItem::set_description(string description) {
  description_ = description;
}
void TodoItem::set_priority(int priority) {
  if (priority >= 1 && priority <= 5) {
  priority_ = priority;
  } else {
    priority_ = 5;
  }
}
void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}
// Scrub function
string TodoItem::Scrub(string description) {
  for (unsigned int i = 0; i < description.length(); i++) {
    if (description.at(i) == '@') {
      description.at(i) = '`';
    }
  }
  return description;
}
// To file function
string TodoItem::ToFile() {
  stringstream list;
  // how do i make the variables into strings???
  list << Scrub(description_) << "@" << priority_ << "@" << completed_;
  return list.str();
}
