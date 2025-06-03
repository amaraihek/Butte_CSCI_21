/*
 * Name        : Lab 26
 * Author      : Amara Ihekwoeme
 * Description : Inheritance
 * Sources     : Luke Sathrum
 */
#include "food_item.h"
// Constructor
FoodItem::FoodItem(string name, int value,
                    unsigned int calories,
                    string unit_of_measure, double units) :
                    Item(name, value) {
  Item(name, value);
  calories_ = calories;
  unit_of_measure_ = unit_of_measure;
  units_ = units;
  }
  // Destructor
FoodItem::~FoodItem() {}
  // Accessors
  unsigned int FoodItem::calories() {
    return calories_;
}
string FoodItem::unit_of_measure() {
  return unit_of_measure_;
}
double FoodItem::units() {
  return units_;
}
// Mutators
void FoodItem::set_calories(unsigned int calories) {
  calories_ = calories;
}
void FoodItem::set_unit_of_measure(string unit_of_measure) {
  unit_of_measure_ = unit_of_measure;
}
void FoodItem::set_units(double units) {
  units_ = units;
}
/* Functions */
string FoodItem::ToString() {
  ostringstream ss;
  ss << Item::ToString() << ", " << std::setprecision(2) << std::fixed << units_
  << " " << unit_of_measure_ << ", " << calories_ << " calories";
  return ss.str();
}
