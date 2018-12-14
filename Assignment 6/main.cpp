#include <iostream>
#include <fstream>
#include "sorting.h"

using namespace std;

int main(int argc, char **argv)
{
  sorting sort;

  if (argc < 2) {
    cout << "Error, Please enter a valid input." << endl;
  }
  else {
    string file = argv[1];
    sort.readFile(file);
  }

  return 0;
}
