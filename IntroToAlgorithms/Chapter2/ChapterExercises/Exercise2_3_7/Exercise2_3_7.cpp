
/**
  Exercise 23-7
  Describe a O(n•lg(n)) algorithm that, given a set S of n integers and another integer x, determines whether or not there exists
  two elements in S whose sum is exactly x.

*/

#include <string>
#include <iostream>
#include <random>
#include <functional>
#include "../utils.h"

using namespace std;

/**
 * Small custom structure used exclusively as a return type for the functions myBinarySearch and myBSUtil
 * Fields:
 * - bool found
 * - int positions
 */
struct SearchResult {
  bool found;
  int position;
};

int* sumtox(int* array, int i, int lastIndex);
SearchResult* myBinarySearch(int target, int* array, int arrayLength);
SearchResult* myBSUtil(int target, int* array, int first, int arrayLength);
void testBS( int* arrayS, int* arrayFind, int lengthForArrays);
void binarySearchTest();


int main(){

  // binarySearchTest();

  int arrayLength = 30;

  int* randomArray = createRandomArray(arrayLength);
  printMyArray(randomArray, arrayLength);

  int* result = sumtox(randomArray, 50, arrayLength);

  if(result[0] == -1){
    cout << "No number in the aray sums to  " << 50 << ".\n";
  } else {
    cout << "The number " << 50 << " is the product of the sum of the sum\nof the numbers";
    cout << " at positions " << result[0] << " and " << result[1] << " in the array.\n";
  }
  
}

void binarySearchTest(){

  int lengthForArrays = 8;

  int *arrayS = createRandomArray(lengthForArrays);
  int *arrayFind = createRandomArray(lengthForArrays);
  printMyArray(arrayS, lengthForArrays);
  cout << "Find these: ";
  printMyArray(arrayFind, lengthForArrays);
  cout << "Sorting array: ";
  myMergeSort(arrayS, 0, lengthForArrays-1);
  printMyArray(arrayS, lengthForArrays);


  
  testBS(arrayS, arrayFind, lengthForArrays);
}

/**
 * This is an auxilliary function meant to help test the functionality of the binary search defined in this same file.
 * Inputs:
 * - int* arrayS
 * - int* arrayFind
 * - int lengthForArrays
 * Outputs:
 * - nonw
 */
void testBS( int* arrayS, int* arrayFind, int lengthForArrays){
  for(int i=0; i<lengthForArrays;i++){
    int find;
    if(i%2==0){
      find = arrayFind[i];
    } else {
      find = arrayS[i];
    }

    SearchResult *result = myBinarySearch( find, arrayS, lengthForArrays);
  
    if(result->found){
      cout << "Number " << find << " found in position " << result->position << ".\n";
    } else {
      cout << "Number " << find << " not found.\n";
    }
    free(result);
  }
  printMyArray(arrayS,lengthForArrays);
}


/**
 * This function takes an array of integers (array), its length (arrayLength), and an integer "x" (x), and determines whether there exist two
 * elements in the array of integers that add up to x or not. It returns an ordered pair within an array of length two. If such two numbers
 * that add up to x exist, the returned array will contain the indexes of the items which sum up to x. Otherwise, the order pair will be
 * (-1,-1)
 * Inputs: 
 * - int* array
 * - int x
 * - int arrayLength
 * Outputs:
 * - int* orderedPair 
 */
int* sumtox(int* array, int x, int arrayLength){
  myMergeSort(array, 0, arrayLength-1);
  printMyArray(array, arrayLength);
  int i = 0;
  while(i<arrayLength && array[i]<=x){
    SearchResult* search = myBinarySearch(x-(array[i]),array, arrayLength);
    if(search->found){
      int* pair = (int*)(malloc(sizeof(int)*2));
      pair[0]=i;
      pair[1]=search->position;
      free(search);
      return pair;
    } else {
      i++;
    }
  }
  int* fail = (int*)(malloc(sizeof(int)*2));
  fail[0] = -1;
  fail[1] = -1;
  return fail;
}

/**
 *
 * 
 * 
 */
SearchResult* myBinarySearch(int target, int* array, int arrayLength){
  if (arrayLength>1){
    return myBSUtil(target, array, 0, arrayLength);
  }

}

SearchResult* myBSUtil(int target, int* array, int first, int arrayEnd){
  if(first==arrayEnd-1){
    SearchResult *result = (SearchResult*)(malloc(sizeof(SearchResult)));
    result-> found = false;
    result-> position = INT_MAX;
    return result;
  };
  int mid = (first+arrayEnd)/2;
  if(array[mid]==target){
    SearchResult *result = (SearchResult*)(malloc(sizeof(SearchResult)));
    result-> found = true;
    result-> position = mid;
    return result;
  } else {
    if(array[mid]>target){
      return myBSUtil(target, array, first, mid);
    } else {
      return myBSUtil(target, array, mid, arrayEnd);
    }
  }
}
