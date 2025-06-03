// MODIFY
/*
 * Name        : Lab 24 cpp
 * Author      : Amara Ihekwoeme
 * Description : Introduction to Trees
 * Sources     : Luke Santhrum
 */

#include "bs_tree.h"
// Constructor
BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}
// Destructor
BSTree::~BSTree() {
  Clear();
}
// Calls private function Insert(int, root)
bool BSTree::Insert(int number) {
  return Insert(number, root_);
}
/* NEW */
bool BSTree::Remove(int number) {
  return Remove(number, root_);
}
/* NEW */
int BSTree::FindMin() {
  /* If the tree is empty return 0,
  else return the contents of the smallest node. */
  if (root_ == NULL) {
    return 0;
  } else {
    return FindMin(root_);
  }
}
// Call private function Clear(root)
void BSTree::Clear() {
  Clear(root_);
}
// Accessor
unsigned int BSTree::GetSize() const {
  return size_;
}
// Call private function InOrder(root)
string BSTree::InOrder() {
  return InOrder(root_);
}
bool BSTree::Insert(int number, BSTNode*& subroot) {
  if (subroot == NULL) {
    // create new node
    BSTNode *new_node = new BSTNode(number);
    // subroot = new node
    subroot = new_node;
    // incremeant size
    size_++;
    return true;
    // if value is smaller, root is now left node
  } else if (number < subroot->GetContents()) {
    return Insert(number, subroot->GetLeftChild());
    // if value is larger, root is now right node
  } else if (number > subroot->GetContents()) {
    return Insert(number, subroot->GetRightChild());
    // if value is the same, no need so return
  } else {
    return false;
  }
}
/* NEW */
bool BSTree::Remove(int number, BSTNode*& subroot) {
  /* Remove has 2 actions, find and delete */
  // If root = NULL, no value found
  if (subroot == NULL) {
    return false;
  }
  // If value is larger, go right
  if (number > subroot->GetContents() && subroot->GetRightChild()) {
    return Remove(number, subroot->GetRightChild());
  // If value is smaller, go left
  } else if (number < subroot->GetContents() &&
            subroot->GetLeftChild() != NULL) {
    return Remove(number, subroot->GetLeftChild());

  // If value is the same, found
  } else if (subroot->GetContents() == number) {
    // Once found; 3 cases
    // Case 1: Node has no children
    if (subroot->GetLeftChild() == NULL &&
        subroot->GetRightChild() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      return true;
    // Case 2: Node has one child, left or right
    // - left child, no right child
    } else if (subroot->GetRightChild() == NULL) {
      BSTNode *temp = subroot;
      subroot = subroot->GetLeftChild();
      delete temp;
      size_--;
      return true;
    // - right child, no left child
    } else if (subroot->GetLeftChild() == NULL) {
      BSTNode *temp = subroot;
      subroot = subroot->GetRightChild();
      delete temp;
      size_--;
      return true;
    // Node has 2 children
    // very ifffy
    } else {
      BSTNode* temp = subroot;
      temp->SetContents(FindMin(subroot->GetRightChild()));
      subroot->GetContents() = temp->GetContents();
      subroot->GetRightChild();
      Remove(temp->GetContents(), subroot->GetRightChild());
      return true;
    }
  } else {
    return false;
  }
}
/* NEW */
int BSTree::FindMin(BSTNode* subroot) const {
  if (subroot->GetLeftChild() != NULL) {
  return FindMin(subroot->GetLeftChild());
  } else {
    return subroot->GetContents();
  }
}
void BSTree::Clear(BSTNode*& subroot) {
  /* Clear in Post Order */
  if (subroot != NULL) {
    if (subroot->GetLeftChild() != NULL) {
      Clear(subroot->GetLeftChild());
    }
    if (subroot->GetLeftChild()) {
      Clear(subroot->GetRightChild());
    }
    delete subroot;
    subroot = NULL;
  }
  size_ = 0;
}
string BSTree::InOrder(BSTNode* subroot) {
  /* In Order: go left, visit, go right */
  if (subroot == NULL) {
    return "";
  }
  stringstream ss;
  ss << InOrder(subroot->GetLeftChild());
  ss << subroot->GetContents() << " ";
  ss << InOrder(subroot->GetRightChild());
  return ss.str();
}
