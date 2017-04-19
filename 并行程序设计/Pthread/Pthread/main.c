#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "function.h"

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
        float **Matrix2 = LUAlgorithmSSE(Matrix, N);
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
        fprintf(stdout,"\nPC use SSE:%f ms\n\n",time);


        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix3 = LUAlgorithmSSEandPthread(Matrix, N);
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
        fprintf(stdout,"\nPC use SSE and pthread with Data partitioning:%f ms\n\n",time);

        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix4 = LUAlgorithmSSEandPthread2(Matrix, N, thread_count);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                fprintf(stdout, "%f ", Matrix4[i][j]);
            }
            fprintf(stdout,"\n");
        }
        time = (tail-head)*1000.0/freq;
        fprintf(stdout,"\nPC use SSE and pthread with Cycle partitioning:%f ms\n\n",time);
    }
    else
    {
        long long time1[500],time2[500],time3[500],time4[500];
        for(int i=0; i<500; i++)
        {
            float **Matrix = MakeMatrix(N);

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithm(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time1[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSE(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time2[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSEandPthread(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time3[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSEandPthread2(Matrix, N, thread_count);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time4[i] = tail-head;
        }
        long long sum1 = time1[0], sum2 = time2[0], sum3 = time3[0], sum4 = time4[0];
        for(int i=1; i<500; i++)
        {
            sum1 += time1[i];
            sum2 += time2[i];
            sum3 += time3[i];
            sum4 += time4[i];
        }
        time = sum1*1000.0/freq/500;
        fprintf(stdout,"\nPC not use SSE:%f ms\n\n",time);
        time = sum2*1000.0/freq/500;
        fprintf(stdout,"\nPC use SSE:%f ms\n\n",time);
        time = sum3*1000.0/freq/500;
        fprintf(stdout,"\nPC use SSE and pthread with Data partitioning:%f ms\n\n",time);
        time = sum4*1000.0/freq/500;
        fprintf(stdout,"\nPC use SSE and pthread with Cycle partitioning:%f ms\n\n",time);
    }
}
