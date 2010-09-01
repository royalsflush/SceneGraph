CC = g++
LIBS = -lm
DBG = -g

.PHONY: matTest

matTest: matTest.o
	$(CC) matTest.o $(DBG) -o out

matTest.cpp: matrix.h
	$(CC) matTest.cpp -c $(DBG)
