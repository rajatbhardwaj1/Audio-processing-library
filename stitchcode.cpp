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
#include "dnn_weights.h"

using namespace std ; 


void take_matrix_input(float* &a, ifstream& t1, int &r, int &c) {
    int row , column ;

    t1 >> column;
    t1 >> row;
    r = row ;
    c = column;
    
    if (!t1)
    {
        cerr << "The files are empty! Please add valid text to the files";
        return;
    }
    a = (float*)malloc(r * c * sizeof(float));
    for (int i = 0; i < (r * c); i++) {
        float inp;
        t1 >> inp;

        a[i] = inp;
    }



}
void fullyconnected_openblas(float* a, float* b, float* c, int m, int n, int k)           //a = m*k ... b = k*n  ... c - m*n
{
    int N , M , K ,lda , ldb , ldc;
    M = 2 ;
    K = 3 ;
    N = 2 ;
    lda = m ;
    ldb = k ;
    ldc = m ;

     float * ook; cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, 1, a, lda, b, ldb, 1, c, ldc);
        //         cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        //    m, n, k, alpha, A, k, B, n, beta, C, n);
}

typedef struct{
    int label;
    float prob;
}pred_t;

pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred) 
{
    
    
    return 0 ;

}
int main()
{   
    
    

    


}