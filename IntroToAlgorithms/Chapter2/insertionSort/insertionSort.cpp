/* 
Started around 20 December 2020, an implementation of Insertion Sort based of the Intro to Algorithms book i used for my CS101 class.
Also contains other functions, as utility functions, or otherwise pertinent to the Chapter of the book in question.

Functions:
  - Create Array with Random Values
  - Insertion Sort
  - Insertion Sort (Decreasing value)
  - Selection Sort
  - Linear Search
  - Find Value in Array (using linear search)
  - Print Array
*/

#include <string>
#include <iostream>
#include <random>
#include <functional>
#include "randomArrays.h"

using namespace std;


void insertionSort(int* array, int arrayLength);
void insertionSortDecreasing(int* array, int arrayLength);
void recursiveInsertionSort(int* array, int arrayLength);
void selectionSort(int* array, int arrayLength);
void recursiveSort(int* array, int n);
int linearSearch(int* array, int arrayLength, int value);
void findIn(int* array, int arrayLength, int value);
void printMyArray(int* array, int arrayLength);
void test(int* array, int arrayLength);

int main(){
  
  int numbersLength = 20;
  int *numbers = createRandomArray(numbersLength);
  printMyArray(numbers, numbersLength);
  test(numbers, numbersLength);
  //
  cout << "\n\n";
  insertionSort(numbers, numbersLength);
  printMyArray(numbers, numbersLength);
  test(numbers, numbersLength);
  //
  cout << "\n\n";
  int numbers2Length = 30;
  int *numbers2 = createRandomArray(numbers2Length);
  printMyArray(numbers2, numbers2Length);
  test(numbers2, numbers2Length);
  //
  cout << "\n\n";
  insertionSortDecreasing(numbers2, numbers2Length);
  printMyArray(numbers2, numbers2Length);
  test(numbers2, numbers2Length);
  //
  cout << "\n\n";
  int numbers3Length = 40;
  int* numbers3 = createRandomArray(numbers3Length);
  printMyArray(numbers3, numbers3Length);
  test(numbers3, numbers3Length);
  //
  cout << "\n\n";
  selectionSort(numbers3,numbers3Length);
  printMyArray(numbers3, numbers3Length);
  test(numbers3, numbers3Length);
  //
  cout << "\n\n";
  int numbers4Length = 30;
  int* numbers4 = createRandomArray(numbers4Length);
  printMyArray(numbers4, numbers4Length);
  cout<<"\n";
  recursiveInsertionSort(numbers4,numbers4Length);
  printMyArray(numbers4, numbers4Length);
  test(numbers4, numbers4Length);

  free(numbers);
  free(numbers2);
  free(numbers3);
  free(numbers4);
}


void insertionSort(int* array, int arrayLength){
  for(int j = 1; j<=arrayLength; j++){
    int curr = array[j];
    int i = j - 1;
    while(i>=0 && array[i]>curr){
      array[i+1] = array[i];
      i = i -1;
      }
    array[i+1] = curr;
  }
}

void insertionSortDecreasing(int* array, int arrayLength){
  for(int j = 1; j<arrayLength; j++){
    int curr = array[j];
    int i = j-1;
    while(i>=0 && array[i]<curr){
      array[i+1] = array[i];
      i = i -1;
    }
    array[i+1] = curr;
  }
}

void recursiveInsertionSort(int* array, int arrayLength){
  int n = arrayLength-1;
  recursiveSort(array, n);
}

void recursiveSort(int* array, int n){
  if(n!=0){
    int toInsert = array[n];
    recursiveSort(array, n-1);
    int i = n;
    while(i>0 && array[i-1]>=toInsert){
      array[i] = array[i-1];
      i--;
    }
    array[i] = toInsert;
  }
}

void selectionSort(int* array, int arrayLength){
  int i = 0;
  while( i<arrayLength-1){
    int current = array[i];
    int j = i;
    int pos = i;
    int min = array[i];
    while(j<arrayLength){
      if(array[j]<min){
        min = array[j];
        pos = j;
      }
      j++;
    }
    if(min<array[i]){
      array[pos] = current;
      array[i] = min;
    }
    i++;
  }
}

int linearSearch(int* array, int arrayLength, int value){
  int i = 0;
  while(i<arrayLength && array[i]!=value){
    i++;
  }
  if(i == arrayLength) {
    return -1;
  } else {
    return i;
  }
}

void findIn(int* array, int arrayLength, int value){
  int position = linearSearch( array, arrayLength, value);
  cout << "Looking for value " << value << " in array...\n";
  if(position==-1){
    cout << "Number was not found in array\n";
  } else {
    cout << "Value " << value << " found in position " << position << " in array\n";
  }
  cout << "\n";
}

void printMyArray(int* array, int arrayLength){
  int i = 0;
  while(i<arrayLength){
    cout << array[i] << ", ";
    i = i + 1;
  }
  cout << "\n";
}

void test(int* array, int arrayLength){
  findIn(array, arrayLength, 1);
  findIn(array, arrayLength, 5);
  findIn(array, arrayLength, 10);
  findIn(array, arrayLength, 20);
  findIn(array, arrayLength, 40);
  findIn(array, arrayLength, 60);
  findIn(array, arrayLength, 80);
  findIn(array, arrayLength, 100);
}
