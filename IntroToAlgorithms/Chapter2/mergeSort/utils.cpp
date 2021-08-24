#include <functional>
#include <iostream>
#include <string>
#include <random>
#include "utils.h"
using namespace std;

int *createRandomArray(int length){

  int userSeed;

  cout << "Enter random seed: ";
  cin >> userSeed;

  std::mt19937 generator(userSeed);
  std::uniform_int_distribution<int> distribution(1,100);

  int *newArray = (int*)malloc(sizeof(int)*length);

  for(int i = 0; i<length; i++){
    newArray[i] = distribution(generator);
    }

  return newArray;

}

void insertionSort(int* array, int arrayLength){
  for(int j = 1; j<arrayLength; j++){
    int curr = array[j];
    int i = j - 1;
    while(i>=0 && array[i]>curr){
      array[i+1] = array[i];
      i = i -1;
      }
    array[i+1] = curr;
  }
}

void printMyArray(int* array, int arrayLength){
  int i = 0;
  while(i<arrayLength){
    cout << array[i] << ", ";
    i = i + 1;
  }
  cout << "\n";
}


