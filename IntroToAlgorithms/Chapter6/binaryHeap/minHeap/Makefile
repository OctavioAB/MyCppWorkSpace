# Last Updated 2021 Mar 10 
CC = g++
CFLAGS = -std=c++11 -Wall -g

minHeap: minHeap.o utils.o
	$(CC) $(CFLAGS) -o minHeap minHeap.o utils.o

minHeap.o: minHeap.cpp utils.h
	$(CC) $(CFLAGS) -c minHeap.cpp

clean:
	$(RM) minHeap.o utils.o

cleanAll:
	$(RM) minHeap.o minHeap utils.o