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
void Relu(float*a, int m, int n)
{
    int i = 0;
    while (i<m*n){
        if (a[i]<0){
            a[i] = 0;
        }else{
            a[i] = a[i];
        }
        i+=1;
    }
}
void foo(void)
{
    puts("Hello, I am a shared library");
}   
void fullyconnected_openblas(float* a, float* b, float* c, int m, int n, int k)           //a = m*k ... b = k*n  ... c - m*n
{
    
    cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, 1, a, k, b, n, 1, c, n);
        //         cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        //    m, n, k, alpha, A, k, B, n, beta, C, n);
}
