/* Last edited on 2021 Mar 10
  Octavio E Anino Barber
  A simple implementation of a Max-Binary Heap, based on the explanation given in 
the book Introduction To Algorithms, by Thomas H. Cormen et al.
  As of 2021 Mar 10, this is pretty much a slightly-altered carbon copy of ../minHeap/minHeap.cpp 

  (!) NTS: Consider grouping with  minHeap.cpp ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "utils.h"

using namespace std;

int maxHeapify(int* A, int A_len, int i);
int left_ify(int i), right_ify(int i);
int buildMaxHeap(int* A, int A_len);
void printArray(int* arr, int a_len);
void test(int i);

int main(){
  test(1);
  test(3);
  test(5);
  test(2);
  test(4);
  test(6);

  test(40);
  // test(400);
  // test(401);

  // int arrayLength = 5;
  // int array_1 [5] = {40, 42 ,26 ,19, 92};
  // printMyArray(array_1, arrayLength);
  // buildMaxHeap(array_1, arrayLength);
  // printMyArray(array_1, arrayLength);
  // cout << "\n";
}

  //36, 65, 7, 26, 13, 

/* Function: maxHeapify
   Inputs: Pointer to Array 'A', Integer Size of Heap 'heapSize', Integer position of "parent" node 'i'(!).
   Purpose: Given an array of integers 'A' and an integer 'i', rearrange the elements so that the max heap property
   holds for parent A[i], and leaves A[i*2], and A[i*2+1]. 

   (!) The integer for the position of theparent node 'i' is considered to be in respect to an array were the first 
   element is at A[1], so to access the "correct" parent - and the leaves too for that matter - one must use "A[i-1]"
   - or the equivalent for the corresponding leaves.
*/

int maxHeapify(int* A, int heapSize, int i){ 
  int l = left_ify(i);
  //cout<< "l: " << l << "\n";
  int r = right_ify(i);
  //cout<< "r: " << r << "\n";
  int largest, temp;
  if(l <= heapSize && A[l-1]>A[i-1]){
    largest = l-1;
  } else {
    largest = i-1;
  }
  if(r <= heapSize && A[r-1]>A[largest]){
    largest = r-1;
  }
  if(largest!=i-1){
    temp = A[i-1];
    A[i-1]=A[largest];
    A[largest]=temp;
    maxHeapify(A, heapSize, largest+1);
  }
  //cout<< "from within heapify:" << "\n";
  //printMyArray(A, heapSize);
  //cout<< "\n";
  return 1;
}

int buildMaxHeap(int* A, int A_len){
  int heapSize = A_len;
  if(A_len<2) return 1;
  for(int i=(A_len/2);i>0;i--){
    maxHeapify(A, heapSize, i);
  }
  return 1;
}

int left_ify(int i){
  if(i==0) return 1;
  return (i<<1);
}

int right_ify(int i){
  if(i==0) return 2;
  return (i<<1)+1;
}

void test(int i){
  int arrayLength = i;
  int* array_1 = createRandomArray(arrayLength);
  printMyArray(array_1, arrayLength);
  buildMaxHeap(array_1, arrayLength);
  printMyArray(array_1, arrayLength);
  free(array_1);
  cout << "\n";
}