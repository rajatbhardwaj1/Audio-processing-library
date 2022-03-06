#ifndef audiolib_h__
#define audiolib_h__
 typedef struct{
    int label;
    float prob;
} pred_t;

extern pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred);
#endif  // audiolib_h__