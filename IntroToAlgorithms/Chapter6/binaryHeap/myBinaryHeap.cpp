/* Last Updated 2021 Mar 12
  Octavio E Anino Barber
  This file is meant to contain an implementation of binary heaps, such that it can be utulized as a tool for 
  other programs. ( Pretty much for personal use only for the moment...)
  The idea is to create a BinaryHeap object, which can be set to function as a min-heap, or max-heap.
  Both types of heaps would share many characteristics, and thus methods too. Hence their combined implemetation.

  */

#include "myBinaryHeap.h"

using namespace std;

/* The idea behind the constuctor is that you can build a heap object, given it's type, which can then be used
dynamically - meaning the heap will grow or shrink as the program runs.
*/
myBinaryHeap::myBinaryHeap()
{
  this->heapSize = 0;
  this->heapSpace = 1;
  int* newHeap = (int*)(malloc(1*sizeof(int)));
  this->heap = newHeap;
}

myBinaryHeap::myBinaryHeap(int space)
{
  this->heapSize = 0;
  this->heapSpace = space;
  int* newHeap = (int*)(malloc((this->heapSpace)*sizeof(int)));
  this->heap = newHeap;
}

myBinaryHeap::~myBinaryHeap()
{
  free(this->heap);
  free(type);
}

void push(int number){
  if((this->heapSize)==0){ // if the heap is empty, push 'number' into the root node
    (this->heap)[0] = number;
    (this->heapSize) = (this->heapSize)+1;
    return;
  } else if((this->heapSpace)>(this.heapSize)){ // if there is still room in the heap...
    // TO-DO
  } else {                                                        // if there is no more room in the heap...
    this->heapSpace = (this->heapSpace)*2+1;                      // add space for another level to the heap
    int* newHeap = (int*)(malloc((this->heapSpace)*sizeof(int))); // allocate space for the new heap
    for(int i =0;i< heap.size();i++){                             // copy old heap into new heap
      newHeap[i]=(this->heap)[i];
    }
    free(this->heap);                                             // free the space of the old heap
    this->heap = newHeap;                                         // set the newHeap to be the current heap
    (this->heap)[(this->heapSize)] = number;                      // place new element at the end of the heap array
    heapify();                                                    // call heapify
  }
}
int pop(int number){
  return 0;
}

void myBinaryHeap::makeMinHeap(int* array, int heapSize){
  return;
}
void myBinaryHeap::makeMaxHeap(int* array, int heapSize){
  return;
}




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
    minHeapify(A, heapSize, largest+1);
  }
  //cout<< "from within heapify:" << "\n";
  //printMyArray(A, heapSize);
  //cout<< "\n";
  return 1;
}

