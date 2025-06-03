/*
 * Name        : Lab 23 cpp
 * Author      : Amara Ihekwoeme
 * Description : Introduction to Trees
 * Sources     : Luke Santhrum
 */

#include "bst_node.h"
// Constructor
BSTNode::BSTNode() {
  left_child_ = NULL;
  right_child_ = NULL;
  contents_ = 0;
}
// Overloaded Constructor
BSTNode::BSTNode(int contents) {
  left_child_ = NULL;
  right_child_ = NULL;
  contents_ = contents;
}
// Destructor
BSTNode::~BSTNode() {
  left_child_ = NULL;
  right_child_ = NULL;
}
// Mutator
void BSTNode::SetContents(int contents) {
  contents_ = contents;
}
// Accessor
int BSTNode::GetContents() const {
  return contents_;
}
int& BSTNode::GetContents() {
  return contents_;
}
// Mutator
void BSTNode::SetLeftChild(BSTNode* left_child) {
  left_child_ = left_child;
}
void BSTNode::SetRightChild(BSTNode* right_child) {
  right_child_ = right_child;
}
// Accessors
BSTNode* BSTNode::GetLeftChild() const {
  return left_child_;
}
BSTNode*& BSTNode::GetLeftChild() {
  return left_child_;
}
BSTNode* BSTNode::GetRightChild() const {
  return right_child_;
}
BSTNode*& BSTNode::GetRightChild() {
  return right_child_;
}
