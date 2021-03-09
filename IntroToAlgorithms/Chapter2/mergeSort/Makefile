 
CC = g++
CFLAGS = -std=c++11 -Wall -g
 
mergeSort: mergeSort.o utils.o
	$(CC) $(CFLAGS) -o mergeSort mergeSort.o utils.o 
 
mergeSort.o: mergeSort.cpp utils.h
	$(CC) $(CFLAGS) -c mergeSort.cpp
 
clean:
	$(RM) utils.o mergeSort.o utils.h.gch

cleanAll:
	$(RM) mergeSort utils.o mergeSort.o utils.h.gch

