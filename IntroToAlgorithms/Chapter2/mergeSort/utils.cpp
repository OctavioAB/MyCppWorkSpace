#include <functional>
#include <iostream>
#include <string>
#include <random>
#include "utils.h"
using namespace std;

int *createRandomArray(int length){

  std::mt19937 generator(time(0));
  std::uniform_int_distribution<int> distribution(1,100);

  int *newArray = (int*)malloc(sizeof(int)*length);

  for(int i = 0; i<length; i++){
    newArray[i] = distribution(generator);
    }

  return newArray;

}

void printMyArray(int* array, int arrayLength){
  int i = 0;
  while(i<arrayLength){
    cout << array[i] << ", ";
    i = i + 1;
  }
  cout << "\n";
}

