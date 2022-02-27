#ifndef foo_h__
#define foo_h__
 
extern void foo(void);
extern void fullyconnected_openblas(float* a, float* b, float* c, int m, int n, int k);           //a = m*k ... b = k*n  ... c - m*n
#endif  // foo_h__