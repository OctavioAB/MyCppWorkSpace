
CC = g++
CFLAGS = -std=c++11 -Wall -g
RM = rm -f

sumtox: Exercise2_3_7.o utils.o
	$(CC) $(CFLAGS) -o sumtox Exercise2_3_7.o utils.o

utils.o: ../utils.cpp
	$(CC) $(CFLAGS) -c ../utils.cpp

Exercise2_3_7.o: Exercise2_3_7.cpp ../utils.h
	$(CC) $(CFLAGS) -c Exercise2_3_7.cpp

clean:
	$(RM) Exercise2_3_7.o utils.o

cleanAll:
	$(RM) sumtox Exercise2_3_7.o utils.o

