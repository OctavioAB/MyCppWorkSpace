/* Last edited on March 9, 2021
  Octavio E Anino Barber
A simple implementation of a Min-Binary Heap, based on the explanation given in 
the book Introduction To Algorithms, by Thomas H. Cormen et al.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "utils.h"

using namespace std;

int minHeapify(int* A, int A_len, int i);
int left_ify(int i), right_ify(int i);
int buildMinHeap(int* A, int A_len);
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
  test(400);
  test(401);

  // int arrayLength = 5;
  // int array_1 [5] = {40, 42 ,26 ,19, 92};
  // printMyArray(array_1, arrayLength);
  // buildMinHeap(array_1, arrayLength);
  // printMyArray(array_1, arrayLength);
  // cout << "\n";
}

  //36, 65, 7, 26, 13, 

/* Function: minHeapify
   Inputs: Pointer to Array 'A', Integer Size of Heap 'heapSize', Integer position of "parent" node 'i'(!).
   Purpose: Given an array of integers 'A' and an integer 'i', rearrange the elements so that the min heap property
   holds for parent A[i], and leaves A[i*2], and A[i*2+1]. 

   (!) The integer for the position of theparent node 'i' is considered to be in respect to an array were the first 
   element is at A[1], so to access the "correct" parent - and the leaves too for that matter - one must use "A[i-1]"
   - or the equivalent for the corresponding leaves.
*/

int minHeapify(int* A, int heapSize, int i){ 
  int l = left_ify(i);
  //cout<< "l: " << l << "\n";
  int r = right_ify(i);
  //cout<< "r: " << r << "\n";
  int smallest, temp;
  if(l <= heapSize && A[l-1]<A[i-1]){
    smallest = l-1;
  } else {
    smallest = i-1;
  }
  if(r <= heapSize && A[r-1]<A[smallest]){
    smallest = r-1;
  }
  if(smallest!=i-1){
    temp = A[i-1];
    A[i-1]=A[smallest];
    A[smallest]=temp;
    minHeapify(A, heapSize, smallest+1);
  }
  //cout<< "from within heapify:" << "\n";
  //printMyArray(A, heapSize);
  //cout<< "\n";
  return 1;
}

int buildMinHeap(int* A, int A_len){
  int heapSize = A_len;
  if(A_len<2) return 1;
  for(int i=(A_len/2);i>0;i--){
    minHeapify(A, heapSize, i);
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
  buildMinHeap(array_1, arrayLength);
  printMyArray(array_1, arrayLength);
  free(array_1);
  cout << "\n";
}