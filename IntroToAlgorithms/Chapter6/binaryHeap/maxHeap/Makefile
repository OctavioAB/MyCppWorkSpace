# Last Updated 2021 Mar 10
CC = g++
CFLAGS = -std=c++11 -Wall -g

maxHeap: maxHeap.o utils.o
	$(CC) $(CFLAGS) -o maxHeap maxHeap.o utils.o

maxHeap.o: maxHeap.cpp utils.h
	$(CC) $(CFLAGS) -c maxHeap.cpp

clean:
	$(RM) maxHeap.o utils.o

cleanAll:
	$(RM) maxHeap.o maxHeap utils.o