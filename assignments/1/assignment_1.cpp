/*
 * Name        : Assignment 1
 * Author      : Amara Ihekwoeme
 * Description : Working with functions
 * Sources     : n/a
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const string &word) {
  int check = 0;
  if (word.empty()) {
    return false;
  }
  for (unsigned int i = 0; i < word.length(); i++) {
    if (!isalpha(word.at(i))) {
      check += 1;
    }
  }
  if (check >= 1) {
      return false;
    } else {
      return true;
    }
}

bool EncryptString(string &word, int shifts) {
  // shifts letters of a character in a word
  // only problem is that if it shift too much it will go out of alphabet range
  // u need to account for it with if statestments for capital A and Z & a and z
  // alphabet end
  int check = 0;
  if (word.empty()) {
    return false;
  }
  for (unsigned int i = 0; i < word.length(); i++) {
    if (!isalpha(word.at(i))) {
      check += 1;
    }
  }
  if (check >= 1) {
      return false;
  }
  // alphabet end
  shifts %= 26;
  for (unsigned int i = 0; i < word.length(); i++) {
    if (isupper(word.at(i))) {
      word.at(i) = word.at(i) + shifts;
      if (word.at(i) > 'Z') {
        word.at(i) -= 26;
      } else if (word.at(i) < 'A') {
        word.at(i) += 26;
      }
    } else if (islower(word.at(i))) {
      word.at(i) = word.at(i) + shifts;
      if (word.at(i) > 'z' || word.at(i) < 0) {
        word.at(i) -= 26;
        } else if (word.at(i) < 'a') {
          word.at(i) += 26;
        }
    }
  }
  return true;
}

bool DecryptString(string &code, int shifts) {
  return EncryptString(code, -shifts);
}

double ComputeAverage(double array[], unsigned int size) {
  double sum = 0;
  double average = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += array[i];
    average = sum/size;
  }
  return average;
}

double FindMinValue(double array[], unsigned int size) {
  double compare = array[0];
  for (unsigned int i = 0; i < size; i++) {
    /*if (!isdigit(array[i])) {
      return 0.0;*/
    if (compare > array[i]) {
      compare = array[i];
    }
  }
  return compare;
}

double FindMaxValue(double array[], unsigned int size) {
  double compare = array[0];
  for (unsigned int i = 0; i < size; i++) {
    /*if (!isdigit(array[i])) {
      return 0.0;*/
    if (compare < array[i]) {
      compare = array[i];
    }
  }
  return compare;
}
