#include <iostream>

using namespace std;

class sorting {
public:
  sorting();
  ~sorting();

  void readFile(string file);
  void bubbleSort(int myArray[]);
  void insertionSort(int myArray[]);
  int partition(int myArray[], int low, int high);
  void quickSort(int myArray[], int low, int high);
  void swap(int* a, int* b);
  void gnomeSort(int myArray[], int n);

  int *myArray;
  int numElements;
};
