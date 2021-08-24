/*
  Finished on Sat, 26 Dec 2020
  Implementation of merge sort of Introduction To Agorithms, Chapter 2.3 .
 
*/
#include <string>
#include <iostream>
#include <random>
#include <functional>
#include "utils.h"

using namespace std;

void mergeSort(int* array, int leftArrayB, int rightArrayE);

int main(){
  int numbers1Length = 16;
  int* numbers1 = createRandomArray(numbers1Length);
  printMyArray(numbers1, numbers1Length);
  mergeSort(numbers1, 0, numbers1Length-1);
  printMyArray(numbers1, numbers1Length);
  cout << "\n\n";

  int numbers2Length = 32;
  int* numbers2 = createRandomArray(numbers2Length);
  printMyArray(numbers2, numbers2Length);
  mergeSort(numbers2, 0, numbers2Length-1);
  printMyArray(numbers2, numbers2Length);
  cout << "\n\n";

  int numbers3Length = 30;
  int* numbers3 = createRandomArray(numbers3Length);
  printMyArray(numbers3, numbers3Length);
  mergeSort(numbers3, 0, numbers3Length-1);
  printMyArray(numbers3, numbers3Length);
  cout << "\n\n";

  int numbers4Length = 5;
  int* numbers4 = createRandomArray(numbers4Length);
  printMyArray(numbers4, numbers4Length);
  mergeSort(numbers4, 0, numbers4Length-1);
  printMyArray(numbers4, numbers4Length);
  cout << "\n\n";

  free(numbers1);
  free(numbers2);
  free(numbers3);
}

void merge(int* array, int leftArrayB, int leftArrayE, int rightArrayE){
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

void mergeSort(int* array, int p, int r){
  if(p<r){
    int mid = (p+r)/2;
    mergeSort(array, p, mid); // Sort "left half" of array
    mergeSort(array, mid+1, r); // Sort "right half" of array
    merge(array, p, mid, r); // Combine the already sorted "left" and  "right" sides of the array
  }
}



