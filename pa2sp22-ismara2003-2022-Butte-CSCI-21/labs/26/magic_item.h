/*
 * Name        : Lab 26
 * Author      : Amara Ihekwoeme
 * Description : Inheritance
 * Sources     : Luke Sathrum
 */
#ifndef MAGIC_ITEM_H
#define MAGIC_ITEM_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "item.h"
using std::ostringstream;
using std::string;
using std::ostream;
// using std::cout;
// using std::cin;
// using std::endl;
// using std::stringstream;
class MagicItem : public Item {
 public:
MagicItem(string name = "magicitem", int value = 0,
          string description = "no description",
          unsigned int mana_required = 0);
~MagicItem();
// Accessor
string description();
unsigned int mana_required();
// Mutator
void set_description(string description);
void set_mana_required(unsigned int mana_required);
string ToString();

 private:
string description_;
unsigned int mana_required_;
};
#endif
