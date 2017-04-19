#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

float **MakeMatrix(int N);//创建随机矩阵
float **LUAlgorithm(float **Matrix, int N);//串行算法
float ** LUAlgorithmSSE(float **Matrix, int N);//SSE并行算法
void *calculate(void *parm);//数据划分的线程方法
float ** LUAlgorithmSSEandPthread(float **Matrix, int N);//数据划分Pthread的LU算法
void *calculate2(void *parm);//循环划分的线程方法
float ** LUAlgorithmSSEandPthread2(float **Matrix, int N, int thread_count);//循环划分Pthread的LU算法

#endif // FUNCTION_H_INCLUDED
