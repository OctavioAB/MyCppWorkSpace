
#include "myBinaryHeap.h"

class myMinHeap: public myBinaryHeap.cpp{
  private:

    void heapify(){
      if((this->type).compare("min")==0){
        for(int i=((this->heapSize)/2);i>0;i--){
          minHeapify(this->heap, heapSize, i);
        }
      }
    }

    int minHeapify(int* A, int heapSize, int i){ 
      int l = left_ify(i);
      int r = right_ify(i);
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

  public:
    myMinHeap() : myBinaryHeap() {}
    myMinHeap(int heapSpace) : myBinaryHeap(heapSpace) {}


}