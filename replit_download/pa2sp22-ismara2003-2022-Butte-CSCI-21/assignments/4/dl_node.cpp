/*
 * Name        : Assignment 4
 * Author      : Amara Ihekwoeme
 * Description : Doubly Linked List
 * Sources     : Luke Sathrum
 */
#include "dl_node.h"
// Constructor
DLNode::DLNode() {
  contents_ = 0;
  previous_node_ = NULL;
  next_node_ = NULL;
}
DLNode::~DLNode() {
}
/* Mutators */
void DLNode::SetContents(int contents) {
  contents_ = contents;
}
void DLNode::SetNext(DLNode* next_node) {
  next_node_ = next_node;
}
void DLNode::SetPrevious(DLNode* previous_node) {
  previous_node_ = previous_node;
}
/* Accessors */
int DLNode::GetContents() {
  return contents_;
}
DLNode* DLNode::GetNext() const {
  return next_node_;
}
DLNode* DLNode::GetPrevious() const {
  return previous_node_;
}
