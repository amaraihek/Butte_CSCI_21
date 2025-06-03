/*
 * Name        : Assignment 5
 * Author      : Amara Ihekwoeme
 * Description : Tree and Templates
 * Sources     : Luke Sathrum
 */
#include "bst_nodet.h"
#include <iostream>
#include <string>
#include <sstream>
using std::stringstream;
using std::string;
#ifndef BS_TREET_H
#define BS_TREET_H

template<typename T>
class BSTreeT {
 public:
// Constructor
BSTreeT() {
  root_ = NULL;
  size_ = 0;
}
// Destructor
~BSTreeT() {
  Clear();
}
/* Member Functions */
int GetSize() const {
  return size_;
}
void Clear() {
  return Clear(root_);
}
int Insert(T value) {
  return Insert(value, root_);
}
bool Exists(T contents) {
  return Exists(contents, root_);
}
int Remove(T contents) {
  return Remove(contents, root_);
}
BSTNodeT<T>* Get(T contents) {
  return Get(contents, root_);
}
string ToStringForwards() {
  return ToStringForwards(root_);
}
string ToStringBackwards() {
  return ToStringBackwards(root_);
}

 private:
/* Private Data Members*/
BSTNodeT<T> *root_;
unsigned int size_;
/* Private Member Function */
void Clear(BSTNodeT<T>*& subroot) {
  if (subroot != NULL) {
    if (subroot->GetLeft() != NULL) {
      Clear(subroot->GetLeft());
    }
    if (subroot->GetLeft()) {
      Clear(subroot->GetRight());
    }
    delete subroot;
    subroot = NULL;
  }
  size_ = 0;
}
int Insert(T contents, BSTNodeT<T>*& subroot) {
  if (subroot == NULL) {
    BSTNodeT<T> *new_node = new BSTNodeT<T>(contents);
    subroot = new_node;
    size_ += 1;
    subroot->IncrementCount();
    return subroot->GetCount();
  } else if (contents < subroot->GetContents()) {
    return Insert(contents, subroot->GetLeft());
  } else if (contents > subroot->GetContents()) {
    return Insert(contents, subroot->GetRight());
  } else {
    subroot->IncrementCount();
    return subroot->GetCount();
  }
}
bool Exists(T contents, BSTNodeT<T>*& subroot) {
  if (subroot == NULL) {
    return false;
  } else if (contents == subroot->GetContents()) {
    return true;
  } else if (contents < subroot->GetContents()) {
    return Exists(contents, subroot->GetLeft());
  } else {
    return Exists(contents, subroot->GetRight());
  }
}
int Remove(T contents, BSTNodeT<T>*& subroot) {
  if (subroot == NULL) {
    return -1;
  } else if (contents < subroot->GetContents()) {
    return Remove(contents, subroot->GetLeft());
  } else if (contents > subroot->GetContents()) {
    return Remove(contents, subroot->GetRight());
  }
  if (subroot->GetCount() > 1) {
    subroot->DecrementCount();
    return subroot->GetCount();
  // No children
  } else if (subroot->GetLeft() == NULL &&
            subroot->GetRight() == NULL ) {
    delete subroot;
    subroot = NULL;
    size_--;
    return 0;
  // 2 child
  } else if (subroot->GetLeft() != NULL && subroot->GetRight() != NULL) {
    BSTNodeT<T> *iterator = subroot;
    subroot = subroot->GetLeft();
    delete iterator;
    size_--;
    return 0;
  } else if (subroot->GetLeft() != NULL || subroot->GetRight() != NULL) {
    BSTNodeT<T> *iterator = subroot;
    if (subroot->GetLeft() != NULL) {
      subroot = subroot->GetLeft();
    } else {
      subroot = subroot->GetRight();
    }
    delete iterator;
    size_--;
    return 0;
  } else {
    T minimum = FindMin(subroot->GetRight());
    subroot->SetContents(minimum);
    return Remove(minimum, subroot->GetRight());
  }
  return -1;
}
BSTNodeT<T>* Get(T contents, BSTNodeT<T>*& subroot) {
  if (subroot == NULL) {
    return NULL;
  } else if (contents == subroot->GetContents()) {
    return subroot;
  } else if (contents < subroot->GetContents()) {
    return Get(contents, subroot->GetLeft());
  } else {
    return Get(contents, subroot->GetRight());
  }
}
string ToStringForwards(BSTNodeT<T>*& subroot) {
  stringstream ss;
  if (subroot == NULL) {
    return ss.str();
  }
  if (subroot->GetLeft() != NULL) {
    ss << ToStringForwards(subroot->GetLeft()) << ", ";
  }
  ss << subroot->GetContents();
  if (subroot->GetRight() != NULL) {
    ss << ", " << ToStringForwards(subroot->GetRight());
  }
  return ss.str();
}
string ToStringBackwards(BSTNodeT<T>*& subroot) {
  stringstream ss;
  if (subroot == NULL) {
    return ss.str();
  }
  if (subroot->GetRight() != NULL) {
    ss << ToStringBackwards(subroot->GetRight()) << ", ";
  }
  ss << subroot->GetContents();
  if (subroot->GetLeft() != NULL) {
    ss << ", " << ToStringBackwards(subroot->GetLeft());
  }
  return ss.str();
}
T FindMin(BSTNodeT <T> *subroot) const {
  if (subroot == NULL) {
    return 0;
  } else if (subroot->GetLeft() == NULL) {
    return subroot->GetContents();
  }
  return FindMin(subroot->GetLeft());
}
};

#endif /* BS_TREET_H */
