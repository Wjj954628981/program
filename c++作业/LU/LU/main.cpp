#include <iostream>
#include <windows.h>
#include <intrin.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 12;

int main()
{
    float Matrix[N][N];
    long long head, freq, tail;        //timers

    srand((unsigned int)time(0));

    //initialize,random number between 0 and 100
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Matrix[i][j] = (float)((rand()%(100)))+(float)(rand()%101)/101;
        }
    }

    //print
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;


    //not use SSE
    //copy the Matrix
    float Matrix1[N][N];
    memcpy(&Matrix1[0][0],&Matrix[0][0],4*N*N);

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);
    //LU
    for(int k=0;k<N;k++){
        for(int j=k+1;j<N;j++){
            Matrix1[k][j] = Matrix1[k][j]/Matrix1[k][k];
        }
        Matrix1[k][k] = 1;
        for(int i=k+1;i<N;i++){
            for(int j=k+1;j<N;j++){
                Matrix1[i][j] = Matrix1[i][j] - Matrix1[i][k]*Matrix1[k][j];
            }
            Matrix1[i][k] = 0;
        }
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);

    //print
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            cout<<Matrix1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"PC not use SSE: "<<(tail-head)*1000.0/freq<<"ms"<<endl<<endl;


    //use SSE
    //copy the Matrix
    float Matrix2[N][N];
    memcpy(&Matrix2[0][0],&Matrix[0][0],4*N*N);

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);
    //LU
    __m128 a,a1,a2;
    __m128 x;

    for(int k=0;k<N;k++){
        int quotient = (N-k-1)/4;
        int remainder = (N-k-1)%4;
        float tmp1[4] = {Matrix2[k][k], Matrix2[k][k], Matrix2[k][k], Matrix2[k][k]};
        x = _mm_loadu_ps(tmp1);
        for(int j=k+1;j<N-remainder;j=j+4){
            a = _mm_loadu_ps(Matrix2[k]+j);
            a1 = _mm_div_ps(a,x);
            _mm_storeu_ps(Matrix2[k]+j,a1);
        }
        for(int j=k+1+4*quotient;j<N;j++){
            Matrix2[k][j] = Matrix2[k][j]/tmp1[0];
        }
        Matrix2[k][k] = 1;

        for(int i=k+1;i<N;i++){
            float tmp2[4] = {Matrix2[i][k], Matrix2[i][k], Matrix2[i][k], Matrix2[i][k]};
            x = _mm_loadu_ps(tmp2);
            for(int j=k+1;j<N-remainder;j=j+4){
                a = _mm_loadu_ps(Matrix2[i]+j);
                a1 = _mm_loadu_ps(Matrix2[k]+j);
                a2 = _mm_sub_ps(a, _mm_mul_ps(x, a1));
                _mm_storeu_ps(Matrix2[i]+j, a2);
            }
            for(int j=k+1+4*quotient;j<N;j++){
                Matrix2[i][j] = Matrix2[i][j] - tmp2[0]*Matrix2[k][j];
            }
            Matrix2[i][k] = 0;
        }
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);

    //print
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            cout<<Matrix2[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"PC use SSE: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
}
