#include "money.h"

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE

/*
 * Overload of binary - operator. This is a friend function.
 * @param Money amount1 - The object to subtract from
 * @param Money amount2 - The object to be subtracted
 * @return Money - The result of the subtraction
 */
const Money operator -(const Money& amount1, const Money& amount2) {
  // Luke: Very similar to + overloaded operator ^^^^^^^
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Subtract all the cents 1 from all cents 2
  int sub_all_cents = all_cents1 - all_cents2;
  // Cents to dollars
  int final_dollars = sub_all_cents / 100;
  // The rest kept as cents
  int final_cents = sub_all_cents % 100;
  return Money(final_dollars, final_cents);
}

/*
 * Overload of == operator. This is a friend function.
 * @param Money amount1 - The first object to compare
 * @param Money amount2 - The second object to compare
 * @return bool - True if the objects have the same values, otherwise false
 */
bool operator ==(const Money &amount1,
                  const Money &amount2) {
  /* compare amount1.dollars_ to amount2.dollars_            
  AND amount1.cents_ TO amount2.cents_ */
  if (amount1.dollars_ == amount2.dollars_ && amount1.cents_
    == amount2.cents_) {
    return true;
  } else {
    return false;
  }
}

/*
 * Overload of unary - operator. This is a friend function.
 * @param Money amount - The object to negate
 * @return Money - The result of the negation of the two member variables
 */
const Money operator -(const Money &amount) {
  // Negate amount.dollars_ and Negate amount.cents_
  int negated_dollars = amount.dollars_ * -1;
  int negated_cents = amount.cents_ * -1;
  return Money(negated_dollars, negated_cents);
}

/*
 * Overload of << operator.
 * Outputs the money values to the output stream.
 * Should be in the form $x.xx
 * @uses setw()
 * @uses setfill()
 * @param ostream &out - The ostream object to output to
 * @param Money amount - The Money object to output from.
 * @return ostream& - The ostream object to allow for chaining of <<
 */
ostream& operator <<(ostream &out, const Money &amount) {
  // not sure how to get the negative out of it
  // and forgot the function that puts it in 2 places
  out << "$";
  if (amount.dollars_ == 0 && amount.cents_ < 0) {
    out << "-";
  }
  out << amount.dollars_ << "." << setw(2) << setfill('0')
      << abs(amount.cents_);
  return out;
}

