#include <windows.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

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
    }
    free(thread_handles);
    return Matrix1;
}

int main()
{
    int N;
    scanf("%d",&N);
    int thread_count;
    fprintf(stdout, "输入创建线程的数目:");
    scanf("%d",&thread_count);
    long long head, freq, tail;        //timers
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    float time;

    if(N>100)
    {
        float **Matrix = MakeMatrix(N);

        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix1 = LUAlgorithm(Matrix, N);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                fprintf(stdout, "%f ", Matrix1[i][j]);
            }
            fprintf(stdout,"\n");
        }
        time = (tail-head)*1000.0/freq;
        fprintf(stdout,"\nPC not use SSE:%f ms\n\n",time);


        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix2 = LUAlgorithmSSEandPthread(Matrix, N);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                fprintf(stdout, "%f ", Matrix2[i][j]);
            }
            fprintf(stdout,"\n");
        }
        time = (tail-head)*1000.0/freq;
        fprintf(stdout,"\nPC use SSE and pthread with Data partitioning:%f ms\n\n",time);

        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix3 = LUAlgorithmSSEandPthread2(Matrix, N, thread_count);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                fprintf(stdout, "%f ", Matrix3[i][j]);
            }
            fprintf(stdout,"\n");
        }
        time = (tail-head)*1000.0/freq;
        fprintf(stdout,"\nPC use SSE and pthread with Cycle partitioning:%f ms\n\n",time);
    }
    else
    {
        long long time1[500],time2[500],time3[500];
        for(int i=0; i<500; i++)
        {
            float **Matrix = MakeMatrix(N);

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithm(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time1[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSEandPthread(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time2[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSEandPthread2(Matrix, N, thread_count);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time3[i] = tail-head;
        }
        long long sum1 = time1[0], sum2 = time2[0], sum3 = time3[0];
        for(int i=1; i<500; i++)
        {
            sum1 += time1[i];
            sum2 += time2[i];
            sum3 += time3[i];
        }
        time = sum1*1000.0/freq/500;
        fprintf(stdout,"\nPC not use SSE:%f ms\n\n",time);
        time = sum2*1000.0/freq/500;
        fprintf(stdout,"\nPC use SSE and pthread with Data partitioning:%f ms\n\n",time);
        time = sum3*1000.0/freq/500;
        fprintf(stdout,"\nPC use SSE and pthread with Cycle partitioning:%f ms\n\n",time);
    }
}
