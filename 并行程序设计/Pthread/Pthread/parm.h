#ifndef PARM_H_INCLUDED
#define PARM_H_INCLUDED

//���ݻ���Pthread�Ĵ��νṹ��
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

//ѭ������Pthread�Ĵ��νṹ��
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
