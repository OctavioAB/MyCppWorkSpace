CC = g++
CFLAGS = -std=c++11 -Wall -g

minHeap: minHeap.o utils.o
	$(CC) $(CFLAGS) -o minHeap minHeap.o utils.o

minHeap.o: minHeap.cpp utils.h
	$(CC) $(CFLAGS) -c minHeap.cpp

clean:
	$(RM) minHeap.o minHeap utils.h.gch