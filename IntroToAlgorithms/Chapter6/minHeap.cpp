/* Last edited on March 9, 2021
  Octavio E Anino Barber
A simple implementation of a Min-Binary Heap, based on the explanation given in 
the book Introduction To Algorithms, by Thomas H. Cormen et al.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int minHeapify(int* A, int A_len, int i);
int left_ify(int i), right_ify(int i);
int buildMinHeap(int* A, int A_len);
void printArray(int* arr, int a_len);

int main(){
  int arrayLength = 10;
  int* array_1 = (int*)(calloc(arrayLength,sizeof(int)));
  printArray(array_1,arrayLength);
  free(array_1);
}

int minHeapify(int* A, int heapSize, int i){ // TEST!
  int l = left_ify(i);
  int r = right_ify(i);
  int smallest, temp;
  if(l <= heapSize && A[l]<A[i]){
    smallest = l;
  } else {
    smallest = i;
  }
  if(r <= heapSize && A[r]<A[smallest]){
    smallest = r;
  }
  if(smallest!=i){
    temp = A[i];
    A[i]=A[smallest];
    A[smallest]=temp;
    minHeapify(A, heapSize, smallest);
  }
  return 1;
}

int buildMinHeap(int* A, int A_len){
  int heapSize = A_len;
  for(int i=(A_len/2)-1;i>=0;i--){
    minHeapify(A, heapSize, i);
  }
  return 1;
}

int left_ify(int i){
  if(i==0) return 1;
  return i<<1;
}

int right_ify(int i){
  if(i==0) return 2;
  return (i<<1) + 1;
}

void printArray(int* arr, int a_len){
  for(int i=0;i<a_len;i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}