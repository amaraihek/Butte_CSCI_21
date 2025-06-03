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
// New
/* 2 Main Steps:
  finding location and adding the node
  3 Possible Locations:
  Insert at Front (head)
  Insert at the End (Tail)
  Insert in the Middle*/
void SLList::Insert(int node) {
  // Insert Begining
  if (head_ == NULL && tail_ == NULL) {
    InsertHead(node);
  } else if (node <= head_->contents()) {
    InsertHead(node);
  // Insert Ending
  } else if (node >= tail_->contents()) {
    InsertTail(node);
  // Insert in middle
  } else {
    SLNode* iterator = head_;
    SLNode* trailer = head_;
    while (iterator->contents() < node) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
    SLNode *new_node = new SLNode(node);
    new_node->set_next_node(iterator);
    trailer->set_next_node(new_node);
    size_++;
  }
}
/* 2 Main Steps:
  Finding node location, then delet it
  4 Locations to Delete:
  Delete at Front
  Delete at the End
  Delete Somewhere in the middle
  Not Found, don't delete */
bool SLList::RemoveFirstOccurence(int node) {
  /* ??? Segmentation Fault in theis function,
  maybe line 75??? */
  // if list is empty
  if (head_ == NULL) {
    return false;
  } else {
    SLNode* iterator = head_;
    SLNode* trailer = head_;
    while (iterator != NULL && iterator->contents() != node) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
      // if value is not found
      if (iterator == NULL) {
        return false;
      // if value is in the beginning
      } else if (iterator == head_) {
        RemoveHead();
      // if value is at the end
      } else if (iterator == tail_) {
        RemoveTail();
      // if value is in the middle
      } else {
        // point the node trailer to iterators next node
        trailer->set_next_node(iterator->next_node());
        // delete node iterator is pointing to
        delete iterator;
        size_--;
      }
  }
  return true;
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
    // Point the new node to where tail is pointing to
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
