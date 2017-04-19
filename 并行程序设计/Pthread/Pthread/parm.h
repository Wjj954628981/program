#ifndef PARM_H_INCLUDED
#define PARM_H_INCLUDED

//数据划分Pthread的传参结构体
typedef struct
{
    int thread;
    int k;
    int N;
    int quotient;
    int remainder;
    float **Matrix;
    float **Matrix1;
} threadParm_t;

//循环划分Pthread的传参结构体
typedef struct
{
    int thread;
    int k;
    int N;
    int quotient;
    int remainder;
    int thread_count;
    float **Matrix;
    float **Matrix1;
} threadParm_t2;

#endif // PARM_H_INCLUDED
