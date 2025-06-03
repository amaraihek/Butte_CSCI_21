/*
 * Name        : new_cat.cpp
 * Author      : Amara Ihekwoeme
 * Description : replicating the cat function
 */
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


int main(int argc, char *argv[]) {
  // declaring streams
  ifstream fin;
  // declare a string
  string line;
  // if one file, just say again what they have typed
  if (argc == 1) {
    while (!cin.eof()) {
      getline(cin, line);
      cout << line << endl;
    }
  // if there is a file, output file
  } else if (argc >= 2) {
    // Loop to make sure ALL of the files exist
    for (int i = 1; i < argc; i++) {
      // Open the current command line argument filename
      fin.open(argv[i]);
      // Make sure it exsits
      if (!fin) {
        // Doesn't Exist
        cerr << "File doesn't exist\n";
        return 1;
      }
      fin.close();
    }
    // All files exist, open each of them, spit out the contents and close them
    for (int i = 1; i < argc; i++) {
      fin.open(argv[i]);
      while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
      }
      fin.close();
    }
  }
  return 0;
}
