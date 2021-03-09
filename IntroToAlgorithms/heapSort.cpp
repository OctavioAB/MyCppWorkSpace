/* Last edited on March 9, 2021
  Octavio E Anino Barber
A simple implementation of a Min-Binary Heap, based on the explanation given in 
the book Introduction To Algorithms, by Thomas H. Cormen et al.
*/


using namespace std;

int minHeapify(int[]* A, int i);
int left_ify(int i), right_ify(int i);

int main(){
  // TODO
}

int minHeapify(int[]* A, int A_len, int i){ // TEST!
  int l = left_ify(i);
  int r = right_ify(i);
  int smallest, temp;
  if(l <= A_len && A[l]<A[i]){
    smallest = l;
  } else {
    smallest = i;
  }
  if(r <= A_len && A[r]<A[i]){
    smallest = r;
  }
  if(smallest!=i){
    temp = A[i];
    A[i]=A[smallest];
    minHeapify(A, A_len, smallest);
  }
}

int left_ify(int i){
  return i<<1;
}

int right_ify(int i){
  return i<<1 + 1;
}