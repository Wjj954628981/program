#include <windows.h>
#include <stdio.h>
#include <pthread.h>
#include "parm.h"
#include "function.h"

//创建随机矩阵
float **MakeMatrix(int N)
{
    srand((unsigned int)time(0));
    float **Matrix;
    Matrix=(float**)malloc(N*sizeof(float*));
    for(int i=0; i<N; i++)
    {
        Matrix[i] = (float*)malloc(N*sizeof(float));
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            Matrix[i][j] = (float)((rand()%(100)))+(float)(rand()%101)/101;
        }
    }
    return Matrix;
}

//串行算法
float **LUAlgorithm(float **Matrix, int N)
{
    float **Matrix1;
    Matrix1=(float**)malloc(N*sizeof(float*));
    for(int i=0; i<N; i++)
    {
        Matrix1[i] = (float*)malloc(N*sizeof(float));
    }
    //LU
    for(int k=0; k<N; k++)
    {
        for(int j=k+1; j<N; j++)
        {
            Matrix1[k][j] = Matrix[k][j]/Matrix[k][k];
        }
        Matrix1[k][k] = 1;
        for(int i=k+1; i<N; i++)
        {
            for(int j=k+1; j<N; j++)
            {
                Matrix1[i][j] = Matrix[i][j] - Matrix[i][k]*Matrix[k][j];
            }
            Matrix1[i][k] = 0;
        }
    }
    return Matrix1;
}

//SSE并行
float ** LUAlgorithmSSE(float **Matrix, int N)
{
    float **Matrix1;
    Matrix1=(float**)malloc(N*sizeof(float*));
    for(int i=0; i<N; i++)
    {
        Matrix1[i] = (float*)malloc(N*sizeof(float));
    }
    //use SSE
    //LU
    __m128 a,a1,a2;
    __m128 x;

    for(int k=0;k<N;k++){
        int quotient = (N-k-1)/4;
        int remainder = (N-k-1)%4;
        float tmp1[4] = {Matrix[k][k], Matrix[k][k], Matrix[k][k], Matrix[k][k]};
        x = _mm_loadu_ps(tmp1);
        for(int j=k+1;j<N-remainder;j=j+4){
            a = _mm_loadu_ps(Matrix[k]+j);
            a1 = _mm_div_ps(a,x);
            _mm_storeu_ps(Matrix1[k]+j,a1);
        }
        for(int j=k+1+4*quotient;j<N;j++){
            Matrix1[k][j] = Matrix[k][j]/tmp1[0];
        }
        Matrix1[k][k] = 1;

        for(int i=k+1;i<N;i++){
            float tmp2[4] = {Matrix[i][k], Matrix[i][k], Matrix[i][k], Matrix[i][k]};
            x = _mm_loadu_ps(tmp2);
            for(int j=k+1;j<N-remainder;j=j+4){
                a = _mm_loadu_ps(Matrix[i]+j);
                a1 = _mm_loadu_ps(Matrix[k]+j);
                a2 = _mm_sub_ps(a, _mm_mul_ps(x, a1));
                _mm_storeu_ps(Matrix1[i]+j, a2);
            }
            for(int j=k+1+4*quotient;j<N;j++){
                Matrix1[i][j] = Matrix[i][j] - tmp2[0]*Matrix[k][j];
            }
            Matrix1[i][k] = 0;
        }
    }
    return Matrix1;
}

//数据划分的线程方法
void *calculate(void *parm)
{
    threadParm_t *p = (threadParm_t *)parm;
    int k = p->k;
    int N = p->N;
    int quotient = p->quotient;
    int remainder = p->remainder;
    int thread = p->thread;
    float **Matrix = p->Matrix;
    float **Matrix1 = p->Matrix1;

    int i = k+1+thread;

    __m128 a,a1,a2;
    __m128 x;

    float tmp2[4] = {Matrix[i][k], Matrix[i][k], Matrix[i][k], Matrix[i][k]};
    x = _mm_loadu_ps(tmp2);
    for(int j=k+1; j<N-remainder; j=j+4)
    {
        a = _mm_loadu_ps(Matrix[i]+j);
        a1 = _mm_loadu_ps(Matrix[k]+j);
        a2 = _mm_sub_ps(a, _mm_mul_ps(x, a1));
        _mm_storeu_ps(Matrix1[i]+j, a2);
    }
    for(int j=k+1+4*quotient; j<N; j++)
    {
        Matrix1[i][j] = Matrix[i][j] - tmp2[0]*Matrix[k][j];
    }
    Matrix1[i][k] = 0;
}

//数据划分Pthread的LU算法
float ** LUAlgorithmSSEandPthread(float **Matrix, int N)
{
    float **Matrix1;
    Matrix1=(float**)malloc(N*sizeof(float*));
    for(int i=0; i<N; i++)
    {
        Matrix1[i] = (float*)malloc(N*sizeof(float));
    }
    //use SSE
    //LU
    __m128 a,a1,a2;
    __m128 x;

    for(int k=0; k<N; k++)
    {
        int quotient = (N-k-1)/4;
        int remainder = (N-k-1)%4;
        float tmp1[4] = {Matrix[k][k], Matrix[k][k], Matrix[k][k], Matrix[k][k]};
        x = _mm_loadu_ps(tmp1);
        for(int j=k+1; j<N-remainder; j=j+4)
        {
            a = _mm_loadu_ps(Matrix[k]+j);
            a1 = _mm_div_ps(a,x);
            _mm_storeu_ps(Matrix1[k]+j,a1);
        }
        for(int j=k+1+4*quotient; j<N; j++)
        {
            Matrix1[k][j] = Matrix[k][j]/tmp1[0];
        }
        Matrix1[k][k] = 1;

        int thread;
        pthread_t* thread_handles;
        int thread_count = N-k-1;
        thread_handles = malloc(thread_count*sizeof(pthread_t));
        threadParm_t threadParm[thread_count];
        for(int i=0; i<thread_count; i++)
        {
            threadParm[i].k = k;
            threadParm[i].N = N;
            threadParm[i].quotient = quotient;
            threadParm[i].remainder = remainder;
            threadParm[i].Matrix = Matrix;
            threadParm[i].Matrix1 = Matrix1;
        }
        for (thread = 0; thread < thread_count; thread++)
        {
            threadParm[thread].thread = thread;
            pthread_create(&thread_handles[thread], NULL, calculate, (void *)&threadParm[thread]);
        }
        for (thread = 0; thread < thread_count; thread++)
        {
            pthread_join(thread_handles[thread], NULL);
        }
        free(thread_handles);
    }
    return Matrix1;
}


//循环划分的线程方法
void *calculate2(void *parm)
{
    threadParm_t2 *p = (threadParm_t2 *)parm;
    int k = p->k;
    int N = p->N;
    int remainder = p->remainder;
    int quotient = p->quotient;
    int thread = p->thread;
    int thread_count = p->thread_count;
    float **Matrix = p->Matrix;
    float **Matrix1 = p->Matrix1;

    int seg = (N-k-1)/thread_count+1;

    __m128 a,a1,a2;
    __m128 x;

    for(int i=k+1; i<N; i++)
    {
        if((i-k-1)%seg == thread)
        {
            float tmp2[4] = {Matrix[i][k], Matrix[i][k], Matrix[i][k], Matrix[i][k]};
            x = _mm_loadu_ps(tmp2);
            for(int j=k+1; j<N-remainder; j=j+4)
            {
                a = _mm_loadu_ps(Matrix[i]+j);
                a1 = _mm_loadu_ps(Matrix[k]+j);
                a2 = _mm_sub_ps(a, _mm_mul_ps(x, a1));
                _mm_storeu_ps(Matrix1[i]+j, a2);
            }
            for(int j=k+1+4*quotient; j<N; j++)
            {
                Matrix1[i][j] = Matrix[i][j] - tmp2[0]*Matrix[k][j];
            }
            Matrix1[i][k] = 0;
        }
    }
}


//循环划分Pthread的LU算法
float ** LUAlgorithmSSEandPthread2(float **Matrix, int N, int thread_count)
{
    float **Matrix1;
    Matrix1=(float**)malloc(N*sizeof(float*));
    for(int i=0; i<N; i++)
    {
        Matrix1[i] = (float*)malloc(N*sizeof(float));
    }
    //use SSE
    //LU
    __m128 a,a1,a2;
    __m128 x;

    //创建固定数目的线程
    int thread;
    pthread_t* thread_handles;
    pthread_barrier_t	barrier;//可以去掉
    thread_handles = malloc(thread_count*sizeof(pthread_t));

    for(int k=0; k<N; k++)
    {
        int quotient = (N-k-1)/4;
        int remainder = (N-k-1)%4;
        float tmp1[4] = {Matrix[k][k], Matrix[k][k], Matrix[k][k], Matrix[k][k]};
        x = _mm_loadu_ps(tmp1);
        for(int j=k+1; j<N-remainder; j=j+4)
        {
            a = _mm_loadu_ps(Matrix[k]+j);
            a1 = _mm_div_ps(a,x);
            _mm_storeu_ps(Matrix1[k]+j,a1);
        }
        for(int j=k+1+4*quotient; j<N; j++)
        {
            Matrix1[k][j] = Matrix[k][j]/tmp1[0];
        }
        Matrix1[k][k] = 1;

        threadParm_t2 threadParm[thread_count];
        pthread_barrier_init(&barrier, NULL, thread_count);//可以去掉
        for(int i=0; i<thread_count; i++)
        {
            threadParm[i].k = k;
            threadParm[i].N = N;
            threadParm[i].quotient = quotient;
            threadParm[i].remainder = remainder;
            threadParm[i].Matrix = Matrix;
            threadParm[i].Matrix1 = Matrix1;
            threadParm[i].thread_count = thread_count;
        }
        for (thread = 0; thread < thread_count; thread++)
        {
            threadParm[thread].thread = thread;
            pthread_create(&thread_handles[thread], NULL, calculate2, (void *)&threadParm[thread]);
        }
        for (thread = 0; thread < thread_count; thread++)
        {
            pthread_join(thread_handles[thread], NULL);
        }
        pthread_barrier_destroy(&barrier);//可以去掉
    }
    free(thread_handles);
    return Matrix1;
}
