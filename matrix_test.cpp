// =================== Test File ====================
// Created by: Thai Pham
// Date: December 19, 2021
// File: Test file for Matrix Operation
// ==================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <sstream>
#include "matrix_operation.hpp"
using namespace std;

typedef void (*FnPtr)();

/*
 * using name assert for convenience - this is not the same as cassert's assert.
 * this function throws a logic error if the assertion is false.
 */
void assertTrue(bool test){
  	if (!test) throw logic_error("assertion failed");
}

/*
 * test matrix multiplication
 */
void test01(){
	lld** matA;
	matA = new lld*[3];
    	for (int i = 0; i < 3; i++)
        	matA[i] = new lld[2];
    	matA[0][0] = 1;
    	matA[0][1] = 5;
    	matA[1][0] = 3;
    	matA[1][1] = 5;
    	matA[2][0] = 4;
    	matA[2][1] = 7;
	
	cout << "here1" << endl;  
    	lld** matB;
    	matB = new lld*[2];
    	for (int i = 0; i < 2; i++)
        	matB[i] = new lld[4];
    	matB[0][0] = 2;
    	matB[0][1] = 4;
    	matB[0][2] = 9;
    	matB[0][3] = 10;
    	matB[1][0] = 12;
    	matB[1][1] = 7;
    	matB[1][2] = 7;
    	matB[1][3] = 5;
  
    	lld** matC = Strassen(matA, matB, 2, 3, 2);
	
	assertTrue(
		matC[0][0] == 62 &&	
		matC[0][1] == 39 &&
		matC[0][2] == 44 &&
		matC[0][3] == 35 &&
		matC[1][0] == 66 &&
		matC[1][1] == 47 &&
		matC[1][2] == 62 &&
		matC[1][3] == 55 &&
		matC[2][0] == 92 &&
		matC[2][1] == 65 &&
		matC[2][2] == 85 &&
		matC[2][3] == 75 
	);
}

/*
* test matrix tranposition
*/
void test02(){
	lld** matrix;
	matrix = new lld*[2];
	for (int i = 0; i < 2; i++) {
		matrix[i] = new lld[3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;

	lld** tranposedMatrix = tranpose(matrix, 2, 3);
	assertTrue(
		tranposedMatrix[0][0] == 1 &&
		tranposedMatrix[0][1] == 4 &&
		tranposedMatrix[1][0] == 2 &&
		tranposedMatrix[1][1] == 5 &&
		tranposedMatrix[2][0] == 3 &&
		tranposedMatrix[2][1] == 6
	);	
}

/*
 * run_test
 * INPUT: the name of a test, and a pointer to a test function
 * run the test. if it passes, return 0 - otherwise, return 1
 */
int run_test(string name, FnPtr fun){
  try{
    fun();
    return 0;
  }catch(logic_error &e){
    return 1;
  }catch(exception &e){
    return 1;
  }
  return 1;
}

int main(int argc, char **argv){
  /*
   * when you add a test case, add the name string (anything you like), paired
   * with the test case function name (needs to be exactly as above).
   * if you remove a test case from above, make sure to remove the line that
   * includes it below.
  */
  vector<std::pair<string, FnPtr>> tests_ordered = {
      {"Matrix multiplication", test01},
      {"Matrix tranposition", test02},
      
  };
  map<string, FnPtr> tests;
  for (const auto pair: tests_ordered){
      tests.insert(pair);
  }
  if (argc != 1){
    return run_test(argv[1], tests[argv[1]]);
  }else{
    for (const auto pair: tests_ordered){
      cerr << pair.first << endl;
    }
  }
  return 0;
}

