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

void merge(int* array, int leftArrayB, int leftArrayE, int rightArrayE);
void mergeSort(int* array, int leftArrayB, int rightArrayE);
void modifiedMergeSort(int* array, int p, int r, int k);
void test(int arrayLength);
void test2(int arrayLength);

int main(){
  // test(10);
  // test(20);
  // test(30);
  test2(30);
  test2(30);
  test2(30);
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

void modifiedMergeSort(int* array, int p, int r, int k){
  if(p<r){
    if(r-p+1>k){
        int mid = (p+r)/2;
        modifiedMergeSort(array, p, mid, k); // Sort "left half" of array
        modifiedMergeSort(array, mid+1, r, k); // Sort "right half" of array
        merge(array, p, mid, r); // Combine the already sorted "left" and  "right" sides of the array
    } else {
      cout << "using insertion sort!" << endl;
      insertionSort(&array[p], r-p+1);
    }
  }
}

/**
 * 
 * Tests merge sort on an array of size arrayLength
 * 
 */
void test(int arrayLength){
  int* numbers1 = createRandomArray(arrayLength);
  printMyArray(numbers1, arrayLength);
  mergeSort(numbers1, 0, arrayLength-1);
  printMyArray(numbers1, arrayLength);
  cout << "\n\n";

  free(numbers1);
}

/**
 * 
 * Tests the modified version of merge sort on an array of size arrayLength
 * 
 */
void test2(int arrayLength){
  int* numbers1 = createRandomArray(arrayLength);
  printMyArray(numbers1, arrayLength);
  double log = log2(arrayLength);
  int k = int(log);
  modifiedMergeSort(numbers1, 0, arrayLength-1, k);
  printMyArray(numbers1, arrayLength);
  cout << "\n\n";
}