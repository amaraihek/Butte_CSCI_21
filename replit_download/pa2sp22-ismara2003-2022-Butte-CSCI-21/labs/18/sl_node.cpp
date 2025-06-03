/*
 * Name        : Lab 17
 * Author      : Amara Ihekwoeme
 * Description : Making class, private data members, public functions
 * Sources     : Luke Sathrum
 */

#include "sl_node.h"

// Constructor definition
SLNode::SLNode() {
  next_node_ = NULL;
  contents_ = 0;
}
SLNode::SLNode(int contents) {
  contents_ = contents;
  next_node_ = NULL;
}
SLNode::~SLNode() {
}
void SLNode::set_contents(int contents) {
  contents_ = contents;
}
void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}
int SLNode::contents() const {
  return contents_;
}
SLNode* SLNode::next_node() const {
  return next_node_;
}
