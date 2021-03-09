 
CC = g++
CFLAGS = -std=c++11 -Wall -g
 
insertionSort: insertionSort.o randomArrays.o
	$(CC) $(CFLAGS) -o insertionSort insertionSort.o randomArrays.o 
 
insertionSort.o: insertionSort.cpp randomArrays.h
	$(CC) $(CFLAGS) -c insertionSort.cpp
 
clean:
	$(RM) randomArrays.o insertionSort.o randomArrays.h.gch

cleanAll:
	$(RM) insertionSort randomArrays.o insertionSort.o randomArrays.h.gch

