/*
 * Name        : Assignment 4
 * Author      : Amara Ihekwoeme
 * Description : Doubly Linked List
 * Sources     : Luke Sathrum
 */

#include "dl_list.h"
// Constructor
DLList::DLList() {
  size_ = 0;
  head_ = NULL;
  tail_ = NULL;
}
// Destructor
// - Calls Clear
DLList::~DLList() {
  Clear();
}
// Accessor
unsigned int DLList::GetSize() const {
  return size_;
}
/* Public Functions*/
// Creates DLNode with contents of parameter
// and adds to the front of list
void DLList::PushFront(int contents) {
  DLNode *new_node = new DLNode();
  size_++;
  new_node->SetContents(contents);
  new_node->SetNext(head_);
  if (tail_ == NULL) {
    tail_ = new_node;
  } else {
    head_->SetPrevious(new_node);
  }
  head_ = new_node;
}
// Creates DLNode with contents of parameter
// and adds to the end of list
void DLList::PushBack(int contents) {
  if (head_ == NULL) {
    PushFront(contents);
  } else {
    DLNode *new_node = new DLNode();
    size_++;
    new_node->SetContents(contents);
    new_node->SetPrevious(tail_);
    tail_->SetNext(new_node);
    tail_ = new_node;
  }
}
// Outputs value at beginning of list
// Output "List Empty" to standard error
// if list is empty and return 0
int DLList::GetFront() const {
  if (size_ == 0) {
    std::cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}
// Outputs value at end of list
// Output "List Empty" to standard error
// if list is empty and return 0
int DLList::GetBack() const {
  if (size_ == 0) {
    std::cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}
// Removes first node
// Outputs "List Empty" to standard error output
// if empty
void DLList::PopFront() {
  if (size_ == 0) {
    std::cerr << "List Empty";
  } else {
    DLNode *temp = head_;
    head_ = head_->GetNext();
    delete temp;
    if (head_ == NULL) {
      tail_ = NULL;
    } else {
      head_->SetPrevious(NULL);
    }
    size_--;
  }
}
// Removes last node
// Outputs "List Empty" to standard error output
// if empty
void DLList::PopBack() {
  if (size_ == 0) {
    std::cerr << "List Empty";
  } else if (size_ == 1) {
    PopFront();
  } else {
    DLNode *temp = tail_;
    tail_ = tail_->GetPrevious();
    delete temp;
    tail_->SetNext(NULL);
    size_--;
  }
}
// Find "first" value to match, if found remove node
// If not found,
// output "Not Found" to standard error output
void DLList::RemoveFirst(int number) {
  if (head_ == NULL) {
    std::cerr << "Not Found";
  } else {
    DLNode *iterator = head_;
    while (iterator != NULL && iterator->GetContents() != number) {
      iterator = iterator->GetNext();
    }
    if (iterator == NULL) {
      std::cerr << "Not Found";
      // else it equals number
    } else if (iterator == head_) {
      PopFront();
    } else if (iterator == tail_) {
      PopBack();
    } else {
      DLNode *trailer = iterator->GetPrevious();
      DLNode *back = iterator->GetNext();
      back->SetPrevious(trailer);
      trailer->SetNext(iterator->GetNext());
      delete iterator;
      size_--;
    }
  }
}
// Find all values to match, if found remove node
// If not found,
// output "Not Found" to standard error output
void DLList::RemoveAll(int number) {
  if (head_ == NULL) {
    std::cerr << "Not Found";
  } else {
    DLNode *iterator = head_;
    while (iterator != NULL) {
      // iterator = iterator->GetNext();
      if (number == iterator->GetContents()) {
        if (iterator == head_) {
          PopFront();
          iterator = head_;
        } else if (iterator == tail_) {
          PopBack();
          iterator = NULL;
        } else {
          DLNode *trailer = iterator->GetPrevious();
          DLNode *back = iterator->GetNext();
          back->SetPrevious(trailer);
          trailer->SetNext(iterator->GetNext());
          delete iterator;
          iterator = trailer;
          size_--;
        }
      } else {
        iterator = iterator->GetNext();
      }
    }
    std::cerr << "Not Found";
  }
}
// Find integer
// If found return true, else return false
bool DLList::Exists(int number) {
  if (head_ == NULL) {
    return false;
  } else {
    DLNode *iterator = head_;
    while (iterator != NULL && iterator->GetContents() != number) {
      iterator = iterator->GetNext();
    }
    if (iterator == NULL) {
      return false;
    }
  }
  return true;
}
// Clears all nodes in list
// Resets size to 0
// head_ and tail_ to NULL
void DLList::Clear() {
  DLNode *iterator = head_;
  while (iterator != NULL) {
    head_ = head_->GetNext();
    delete iterator;
    iterator = head_;
  }
  tail_ = NULL;
  head_ = NULL;
  size_ = 0;
}
// Output contents comma seperated
// from first node to last node
// If empty, return empty string
// and output "List Empty" to standard error output
string DLList::ToStringForwards() {
  if (size_ == 0) {
    std::cerr << "List Empty";
  return "";
  }
  stringstream ss;
  DLNode *iterator = head_;
  while (iterator != tail_) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetNext();
  }
  ss << iterator->GetContents();
  return ss.str();
}
string DLList::ToStringBackwards() {
  if (size_ == 0) {
    std::cerr << "List Empty";
    return "";
  }
  stringstream ss;
  DLNode *iterator = tail_;
  while (iterator != head_) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetPrevious();
  }
  ss << iterator->GetContents();
  return ss.str();
}
