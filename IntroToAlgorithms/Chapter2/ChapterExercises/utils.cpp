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
  cout << "Thank You \n";
}

void printMyArray(int* array, int arrayLength){
  int i = 0;
  while(i<arrayLength){
    cout << array[i] << ", ";
    i = i + 1;
  }
  cout << "\n";
}

void myMerge(int* array, int leftArrayB, int leftArrayE, int rightArrayE){
  int leftSize = leftArrayE-leftArrayB+1; 
  int rightSize = rightArrayE-leftArrayE;
  int *leftArray = (int*)malloc(sizeof(int)*(leftSize));
  int *rightArray = (int*)malloc(sizeof(int)*(rightSize));
  int i = 0;
  while(i<leftSize){
    leftArray[i]=array[leftArrayB+i];
    i++;
  }
  int j = 0;
  while(j<rightSize){
    rightArray[j]=array[leftArrayE+j+1];
    j++;
  }
  i = 0;
  j = 0;
  for(int k = leftArrayB; k<rightArrayE+1;k++){
    if(i<leftSize && j<rightSize){
      if(leftArray[i]<=rightArray[j]){
        array[k] = leftArray[i];
        i++;
      } else {
        array[k] = rightArray[j];
        j++;
      }
    } else if(i>=leftSize && j<rightSize){
      array[k] = rightArray[j];
      j++;
    } else {
      array[k] = leftArray[i];
      i++;
    }
  }
  free(leftArray);
  free(rightArray);
}

void myMergeSort(int* array, int p, int r){
  if(p<r){
    int mid = (p+r)/2;
    myMergeSort(array, p, mid); // Sort "left half" of array
    myMergeSort(array, mid+1, r); // Sort "right half" of array
    myMerge(array, p, mid, r); // Combine the already sorted "left" and  "right" sides of the array
  }
}




