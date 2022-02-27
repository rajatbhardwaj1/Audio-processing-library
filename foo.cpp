#include<iostream>
#include <cblas.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <chrono>
#include <algorithm>
 
void foo(void)
{
    puts("Hello, I am a shared library");
}   
void fullyconnected_openblas(float* a, float* b, float* c, int m, int n, int k)           //a = m*k ... b = k*n  ... c - m*n
{
    int lda , ldb , ldc;
    
    lda = m ;
    ldb = k ;
    ldc = m ;

    cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, 1, a, lda, b, ldb, 1, c, ldc);
        //         cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        //    m, n, k, alpha, A, k, B, n, beta, C, n);
}