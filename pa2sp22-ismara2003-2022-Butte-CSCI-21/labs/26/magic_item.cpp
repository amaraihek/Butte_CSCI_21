/*
 * Name        : Lab 26
 * Author      : Amara Ihekwoeme
 * Description : Inheritance
 * Sources     : Luke Sathrum
 */
#include "magic_item.h"
// Constructor
MagicItem::MagicItem(string name, int value,
                    string description,
                    unsigned int mana_required) :
                    Item(name, value) {
  Item(name, value);
  description_ = description;
  mana_required_= mana_required;
}
// Destructor
MagicItem::~MagicItem() {}
// Accessors
string MagicItem::description() {
  return description_;
}
unsigned int MagicItem::mana_required() {
  return mana_required_;
}
// Mutator
void MagicItem::set_description(string
    description) {
  description_ = description;
}
void MagicItem::set_mana_required(unsigned int mana_required) {
  mana_required_ = mana_required;
}
string MagicItem::ToString() {
  ostringstream ss;
  ss << Item::ToString() << ", " << description_ << ", requires " <<
  mana_required_ <<  " mana";
  return ss.str();
}

