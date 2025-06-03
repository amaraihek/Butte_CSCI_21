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
