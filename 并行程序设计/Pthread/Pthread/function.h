#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

float **MakeMatrix(int N);//�����������
float **LUAlgorithm(float **Matrix, int N);//�����㷨
float ** LUAlgorithmSSE(float **Matrix, int N);//SSE�����㷨
void *calculate(void *parm);//���ݻ��ֵ��̷߳���
float ** LUAlgorithmSSEandPthread(float **Matrix, int N);//���ݻ���Pthread��LU�㷨
void *calculate2(void *parm);//ѭ�����ֵ��̷߳���
float ** LUAlgorithmSSEandPthread2(float **Matrix, int N, int thread_count);//ѭ������Pthread��LU�㷨

#endif // FUNCTION_H_INCLUDED
