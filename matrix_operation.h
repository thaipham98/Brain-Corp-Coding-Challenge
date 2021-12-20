// =================== Support Code =================
// Matrix Operation.
//
// - Header file for Matrix Operation, which includes
//	1. Matrix Multiplication with Strassens algorithm
//	2. Matrix Tranposition with SIMD intrinsics
// ==================================================
#ifndef MATRIXOPERATION_H
#define MATRIXOPERATION_H

typedef long long lld;

lld** Strassen(lld** a, lld**b, int n, int l, int m);

void TransposeBlockSSE(float *A, float *B, const int n, const int m, const int lda, const int ldb ,const int block_size);



#endif

