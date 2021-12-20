###########################################################################
# Created by: Thai Pham							  #
# Date: December 19, 20221						  #
# File: Makefile for Matrix						  #	
###########################################################################

CC = g++

CFLAGS = -fPIC -std=c++11

all: matrix_test.o matrix_test

matrix_test: matrix_test.o
	$(CC) $(CFLAGS) $(LDFLAGS) matrix_test.o -o matrix_test

matrix_test.o: matrix_test.cpp matrix_operation.hpp
	$(CC) $(CFLAGS) -c matrix_test.cpp -o matrix_test.o

clean:
	rm -rf *.o  matrix_test
