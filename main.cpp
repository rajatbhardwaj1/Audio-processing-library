#include<iostream>
#include <cblas.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string.h>

#include <algorithm>
#include "foo.h"


int main(void)
{   
    
    foo();
    for (int i = 1; i <= 15; i++)
    {
        //sizes will be i*10 
        int m = 5 * i;
        int  n = 5 * i;
        int  k = 5 * i;
        float* p, * q, * r;
        p = (float*)malloc(25 * i * i * sizeof(float));
        q = (float*)malloc(25 * i * i * sizeof(float));
        r = (float*)malloc(25 * i * i * sizeof(float));
        for (int j = 0; j < 25 * i * i; j++)
        {
            p[j] = (float)rand() / (float)rand();

            q[j] = (float)rand() / (float)rand();
            r[j] = (float)rand() / (float)rand();
        }
        for (int p1 = 0; p1 < 10000; p1++) {

            fullyconnected_openblas(p, q, r, m, n, k);

               
        }
    }
        return 0;
    }