/*
 * Name        : Lab 26
 * Author      : Amara Ihekwoeme
 * Description : Inheritance
 * Sources     : Luke Sathrum
 */
#include "item.h"

Item::Item(string name, unsigned int value) {
  name_ = name;
  value_ = value;
}
// Destructor
Item::~Item() {}
// Accessor
string Item::name() {
  return name_;
}
unsigned int Item::value() {
  return value_;
}
void Item::set_name(std::string name) {
  name_ = name;
}
void Item::set_value(unsigned int value) {
  value_ = value;
}
// Functions
string Item::ToString() {
  ostringstream ss;
  ss << name_ << ", $" << value_;
  return ss.str();
}
