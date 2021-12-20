###########################################################################
# Created by: Thai Pham							  #
# Date: December 19, 20221						  #
# File: Makefile for Matrix						  #	
###########################################################################

CC = g++

CFLAGS = -std=c++11

default: result

matrix_test.o: matrix_test.cpp matrix_operation.hpp
	$(CC) $(CFLAGS) -c matrix_test.cpp -o matrix_test.o

result: matrix_test.o 
	$(CC) $(CFLAGS) matrix_test.o -o matrix_test
clean:
	-@rm -rf *.o matrix_test	
