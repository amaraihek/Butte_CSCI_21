/*
 * Name        : Lab 18
 * Author      : Amara Ihekwoeme
 * Description : Making class, private data members, public functions
 * Sources     : Luke Sathrum
 */

#include "sl_list.h"
SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}
SLList::~SLList() {
  // Calls the Clear Function
  Clear();
}
void SLList::InsertHead(int head_value) {
  // Create a new node set to the head_value
  SLNode *new_node = new SLNode(head_value);
  size_++;
   // Point the new node to where head is pointing to
  new_node->set_next_node(head_);
  // Head needs to point to the new node
  head_ = new_node;
}
void SLList::RemoveHead() {
  if (head_ == NULL) {
    return;
  }
  // Hints: Needs Delete and Uses Iterator
  // Step 1: create a temporary pointer to where head is pointing to
  SLNode *temp;
  temp = head_;
  // Step 2: Point the head to the next node in the list
  // a) might need to point to null if only node in list
  head_ = head_->next_node();
  // Step 3: Remove the node temp is pointing to
  delete temp;
  size_--;
  //ARROWS IN A NODE NEED AN ARROW
}
void SLList::Clear() {
  // If list is empty do not remove
  if (head_ == NULL) {
    return;
  }
  // Create an Iterator Pointer
  // Point it to where head is pointing to
  SLNode *iterator = head_;
  // Loop while iterator isn't null
  while (iterator != NULL) {
    // head points to the next node
    head_ = head_->next_node();
    // delete what the iterator is pointing to
    delete iterator;
    // iterator points to next node
    iterator = head_;
  }
  size_ = 0;
}
unsigned int SLList::size() const {
  return size_;
}
string SLList::ToString() {
  SLNode *iterator = head_;
  stringstream ss;
  if (head_ == NULL) {
    return "";
  }
  while (iterator != NULL) {
    if (iterator->next_node() == NULL) {
      ss << iterator->contents();
    } else {
       ss << iterator->contents() << ", ";
    }
    iterator = iterator->next_node();
  }
  return ss.str();
}