/* Last updated 2021 Mar 12
  Octavio E Anino Barber
  This header file is meant to lay out the basis for the BinaryHeap object, which will be used to implement 
  min- and max-heaps. 
*/

#ifndef MYBINARYHEAP_H 
#define MYBINARYHEAP_H


class myBinaryHeap {
  protected:
    int heapSize;
    int heapSpace;
    int* heap;

    void setHeapSize(int i);
    virtual void heapify();

    myBinaryHeap();
    myBinaryHeap(int heapSpace);
    ~myBinaryHeap();

    void push(int number);
    int pop(int number);

    int getHeapSize();
    string getHeapType();

    void setHeapType(string type);

    public:
    void makeMinHeap(int* array, int heapSize);
    void makeMaxHeap(int* array, int heapSize);
    
}

#endif 
