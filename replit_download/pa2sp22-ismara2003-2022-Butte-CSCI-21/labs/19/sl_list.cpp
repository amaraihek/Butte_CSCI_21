/*
 * Name        : Lab 19
 * Author      : Amara Ihekwoeme
 * Description : Making class, private data members, public functions
 * Sources     : Luke Sathrum
 */

#include "sl_list.h"
SLList::SLList() {
  head_ = NULL;
  tail_ =  NULL;
  size_ = 0;
}
SLList::~SLList() {
  Clear();
}

void SLList::InsertHead(int head_value) {
  // Create a new node set to the head_value
  SLNode *new_node = new SLNode(head_value);
  size_++;
  // Point the new node to where head is pointing to
  new_node->set_next_node(head_);
  head_ = new_node;
  // ...
  if (head_->next_node() == NULL) {
    tail_ = head_;
  }
}
void SLList::InsertTail(int tail_value) {
  if (head_ == NULL) {
    InsertHead(tail_value);
  } else {
    SLNode *new_node = new SLNode(tail_value);
    // ...
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_++;
  }
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
  if (head_ == NULL) {
    tail_ = NULL;
  }
}

void SLList::RemoveTail() {
  if (head_ != NULL) {
    // if one node in the list, just call removehead
    if (head_ != NULL && head_ == tail_) {
      RemoveHead();
    } else {
    SLNode* iterator = head_;
    while (iterator->next_node() != tail_) {
      iterator = iterator->next_node();
    }
    iterator->set_next_node(NULL);
    delete tail_;
    tail_ = iterator;
    size_--;
    }
  }
}
int SLList::GetHead() const {
  if (head_ == NULL) {
    return 0;
  }
  return head_->contents();
}
int SLList::GetTail() const {
  if (tail_ == NULL) {
    return 0;
  }
  return tail_->contents();
}
void SLList::Clear() {
  // if list is empty, do not remove
  if (head_ == NULL && tail_ == NULL)
    return;
  // Create iterator pointer
  SLNode *iterator;
  // Point to where head is pointing to
  iterator = head_;
  while (iterator != NULL) {
  // Head points to next node
  head_ = head_->next_node();
  // Delete what the iterator poinying to
  delete iterator;
  // Iterator points to next node
  // aka what head is pointing to
  iterator = head_;
  }
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}
unsigned int SLList::size() const {
  return size_;
}

string SLList::ToString() const {
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
