#include <iostream>
#include <windows.h>
#include <intrin.h>
#include <ctime>
#include <cstdlib>

using namespace std;


float **MakeMatrix(int N){
    srand((unsigned int)time(0));
    float **Matrix;
    Matrix = new float *[N];
    for(int i=0;i<N;i++){
        Matrix[i] = new float[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Matrix[i][j] = (float)((rand()%(100)))+(float)(rand()%101)/101;
        }
    }
    return Matrix;
}

float **LUAlgorithm(float **Matrix, int N){
    float **Matrix1;
    Matrix1 = new float *[N];
    for(int i=0;i<N;i++){
        Matrix1[i] = new float[N];
    }
    //LU
    for(int k=0;k<N;k++){
        for(int j=k+1;j<N;j++){
            Matrix1[k][j] = Matrix[k][j]/Matrix[k][k];
        }
        Matrix1[k][k] = 1;
        for(int i=k+1;i<N;i++){
            for(int j=k+1;j<N;j++){
                Matrix1[i][j] = Matrix[i][j] - Matrix[i][k]*Matrix[k][j];
            }
            Matrix1[i][k] = 0;
        }
    }
    return Matrix1;
}

float ** LUAlgorithmSSE(float **Matrix, int N){
    float **Matrix1;
    Matrix1 = new float *[N];
    for(int i=0;i<N;i++){
        Matrix1[i] = new float[N];
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

int main(){
    int N;
    cin>>N;
    long long head, freq, tail;        //timers
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    if(N>100){
        float **Matrix = MakeMatrix(N);

        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix1 = LUAlgorithm(Matrix, N);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                cout<<Matrix1[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"PC not use SSE: "<<(tail-head)*1000.0/freq<<"ms"<<endl<<endl;


        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        float **Matrix2 = LUAlgorithmSSE(Matrix, N);
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        //print
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                cout<<Matrix2[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"PC not use SSE: "<<(tail-head)*1000.0/freq<<"ms"<<endl<<endl;
    }else{
        long long time1[500],time2[500];
        for(int i=0;i<500;i++){
            float **Matrix = MakeMatrix(N);

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithm(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time1[i] = tail-head;

            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            LUAlgorithmSSE(Matrix, N);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            time2[i] = tail-head;
        }
        long long sum1 = time1[0], sum2 = time2[0];
        for(int i=1;i<500;i++){
            sum1 += time1[i];
            sum2 += time2[i];
        }
        cout<<endl<<"PC not use SSE: "<<sum1*1000.0/freq/500<<"ms"<<endl<<endl;
        cout<<endl<<"PC use SSE: "<<sum2*1000.0/freq/500<<"ms"<<endl<<endl;
    }
}
