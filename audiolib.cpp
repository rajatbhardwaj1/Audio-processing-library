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
using namespace std;
//creating struct pred_t
typedef struct {
    int label;
    float prob;
}pred_t;
//softmax function
void softmax(float* a, int m, int  n)
{
    float sum = 0;
    for (int i = 0; i < m * n; i++)
    {
        sum += exp(a[i]);
    }
    for (int i = 0; i < m * n; i++)
    {
        a[i] = exp(a[i]) / sum;
    }

}
//relu function
void Relu(float* a, int m, int n)
{
    int i = 0;
    while (i < m * n) {
        if (a[i] < 0) {
            a[i] = 0;
        }
        else {
            a[i] = a[i];
        }
        i += 1;
    }
}

//function that returns c = a * b + c where a , b ,  c are matrices . uses openblas library
void fullyconnected_openblas(float* a, float* b, float* c, int m, int n, int k)           //a = m*k ... b = k*n  ... c - m*n
{

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        m, n, k, 1.0, a, k, b, n, 1.0, c, n);

}

//function to return labels and probability of top 3 sounds 
//takes into input array of size 12 having probabilities of label in corresponding indices (a) and pred (struct of pred_t,
//in which the labels and probabilities are stored
void topred(float* a, pred_t* pred) {
    int i = 0;
    //initialising the labels and probabilities.
    pred[0].label = 0;
    pred[0].prob =0 ;
    pred[1].label = 0;
    pred[1].prob =0;
    pred[2].label = 0;
    pred[2].prob = 0;
    while (i < 3) { //after the ith iteration the ith largest probability and its label is stored in pred[i]

    int j = 0;

        while (j < 12) { // going through all the values of a and storing the maximum in pred
            float p = pred[i].prob - a[j];  

            if (p < 0) {
                pred[i].prob = a[j];
                pred[i].label = j;
            }
            j += 1;
        }
        a[(pred[i].label)] = 0; // after the largest value is stored in pred we make a[label] = 0 so that the next largest value becomes 
                                //the largest int the next iteration and we can find it in the next iteration
        i += 1;
    }
}
//the main function of the library which can be used by our main file

//it returns the sounds with the top 3 probabilities into pred and also returns pred 
pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred)
{
    
    ifstream t;
    t.open(audiofeatures);

    float a[250];
    for (int i = 0; i < 250; i++)t >> a[i];

    //initialising the weights 
    float w1[] = IP1_WT;
    float w2[] = IP2_WT;
    float w3[] = IP3_WT;
    float w4[] = IP4_WT;

    //inititalising the bias matrices
    float b1[] = IP1_BIAS;
    float b2[] = IP2_BIAS;
    float b3[] = IP3_BIAS;
    float b4[] = IP4_BIAS;

    //applying fullyconnexted function , relu and softmax in the given sequence

    fullyconnected_openblas(a, w1, b1, 1, 144, 250); //returns b1 = a*w1 +b1 
    Relu(b1, 1, 144);

    fullyconnected_openblas(b1, w2, b2, 1, 144, 144); //returns b2 = b1*w2 +b2 
    Relu(b2, 1, 144);

    fullyconnected_openblas(b2, w3, b3, 1, 144, 144); //returns b3 = b2*w3 + b3 
    Relu(b3, 1, 144);

    fullyconnected_openblas(b3, w4, b4, 1, 12, 144);    //returns b4 = b3*w4 + b4
    
    softmax(b4, 1, 12);

    topred(b4 , pred);


    return pred;

}
