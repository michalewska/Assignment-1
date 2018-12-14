//quickSort, insertionSort, bubbleSort, and your choice
#include <iostream>
#include <fstream>
#include "sorting.h"

using namespace std;

sorting::sorting()
{
  int numElements = 0;
}

sorting::~sorting()
{

}

void sorting::readFile(string file)
{

  // string line;
  //
  // ifstream inFile;
  // inFile.open(file.c_str());
  //
  // getline(inFile, line);
  // numElements = atoi(line.c_str());
  //
  // for(int i = 0; i < numElements; i++)
  // {
  //   cout << "in loop" << i << endl;
  //   lineNum++;
  //   getline(inFile, line);
  //   cout << myArray[i] << " ";
  // }
  //
  // inFile.close();

  ifstream infile;
  infile.open(file.c_str());
  if (infile.is_open()) {
    while (true) {
      int x;
      infile >> x;
      if (infile.eof()) {
        break;
      }
      myArray[numElements++] = x;
    }
    for (int i = 0; i < numElements; ++i) {
      cout << myArray[i] << ", ";
    }
    cout << endl;
    infile.close();
  }

  else {
    cout << "Unable to open file." << endl;
  }
}

void sorting::bubbleSort(int myArray[])
{
  for (int i = 0; i < numElements; ++i) {
    int temp = 0;
    for (int j = i; j < 9; ++j) {
      if (myArray[j] > myArray[j + 1]) {
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void sorting::insertionSort(int myArray[])
{
  for (int i = 1; i < numElements; ++i) {
    int temp = myArray[i];
    int j = i;
    while (j > 0 && myArray[j - 1] >= temp) {
      myArray[j] = myArray[j - 1];
      --j;
    }
    myArray[j] = temp;
  }
  cout << "Content after bubble sort: \n" << myArray;

}

int sorting::partition(int myArray[], int low, int high)
{
  int pivot = myArray[high];
  int i = (low - 1);
  for (int j = low; j <= high -1; j++)
  {
    if (myArray[j] <= pivot) {
      i++;
      swap(&myArray[i], &myArray[j]);
    }
  }
  swap (&myArray[i + 1], &myArray[high]);
  return (i + 1);
}

void sorting::quickSort(int myArray[], int low, int high)
{
    if (low < high) {
      int pi = partition(myArray, low, high);
      quickSort(myArray, low, pi - 1);
      quickSort(myArray, pi +1, high);
    }
}

void sorting::swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void sorting::gnomeSort(int myArray[], int n)
{
  int index = 0;
  while (index < n) {
    if (index == 0) index++;
    if (myArray[index] >= myArray[index - 1]) index++;
    else {
      swap(&myArray[index], &myArray[index - 1]);
      index--;
    }
  }
}
