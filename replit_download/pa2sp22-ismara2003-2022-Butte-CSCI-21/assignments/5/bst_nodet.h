#ifndef BST_NODET_H
#define BST_NODET_H
#include <cstddef>
#include <string>

template <typename T>
class BSTNodeT {
 public:
  BSTNodeT() {
    contents_ = T();
    count_ = 0;
    left_child_ = NULL;
    right_child_ = NULL;
  }
  BSTNodeT(T contents) {
    contents_ = contents;
    count_ = 0;
    left_child_ = NULL;
    right_child_ = NULL;
  }
  ~BSTNodeT() {
    left_child_ = NULL;
    right_child_ = NULL;
  }
  void SetContents(T contents) {
    contents_ = contents;
  }
  void SetLeft(BSTNodeT* child) {
    left_child_ = child;
  }
  void SetRight(BSTNodeT* child) {
    right_child_ = child;
  }
  void IncrementCount() {
    count_++;
  }
  void DecrementCount() {
    count_--;
  }
  T GetContents() const {
    return contents_;
  }
  BSTNodeT*& GetLeft() {
    return left_child_;
  }
  BSTNodeT*& GetRight() {
    return right_child_;
  }
  unsigned int GetCount() const {
    return count_;
  }

 private:
  T contents_;
  unsigned int count_;
  BSTNodeT<T>* left_child_;
  BSTNodeT<T>* right_child_;
};
#endif
