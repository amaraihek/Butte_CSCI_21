/*
 * Name        : Assignment 1
 * Author      : Amara Ihekwoeme
 * Description : Working on functions
 * Sources     : 
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <string>
using namespace std;
// Declare Function Prototypes Here (What goes above main)
bool CheckAlphabetic(const string &word);
/*This function will check to make sure all characters in a given string 
are alphabetic. It returns true if the string is all alphabetic, 
otherwise it returns false. An empty string should also return false. 
 */
bool EncryptString(string &word, int shifts);
/*this function will perform a Caesar Cipher shift. If the string contains 
any non-alpha characters do not perform the encryption and return 
false. Otherwise perform the encryption and return true. */
bool DecryptString(string &code, int shifts);
/*This function decrypts a Caesar Cipher shift. If the string contains 
any non-alpha characters do not perform the decryption and return 
false. Otherwise perform the encryption and return true.*/
double ComputeAverage(double array[], unsigned int size);
/*This function will compute the mean average of the values in the 
array. The array will always be at least of size 1.*/
double FindMinValue(double array[], unsigned int size);
/*This function will find and return the smallest value in an array. The 
array will always be at least of size 1.*/
double FindMaxValue(double array[], unsigned int size);
/*This function will find and return the largest value in an array. The 
array will always be at least of size 1.*/
#endif /* ASSIGNMENT_1_H */
