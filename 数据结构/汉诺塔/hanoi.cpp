#include<iostream>
#include"hanoi.h"

using namespace std;

int sum=1; 

class hanoi{
	friend void towersOfhanoi(int n);
	public:
		void moveAndshow(int n,int x,int y,int z);
	private:
		linkedStack<int>* tower[4];
};

void hanoi::moveAndshow(int n,int x,int y,int z){
	int d; 
	if(n>0){
		moveAndshow(n-1,x,z,y);
		tower[x]->pop(d);
		tower[y]->push(d);
        cout<<sum++<<":"<<x<<"->"<<y<<endl;
		moveAndshow(n-1,z,y,x);
	}
}

void towersOfhanoi(int n){
	hanoi X;
	X.tower[1]=new 	linkedStack<int>;
    X.tower[2]=new 	linkedStack<int>;
    X.tower[3]=new 	linkedStack<int>;
    for(int d=n;d>0;d--){
    	X.tower[1]->push(d);
    }
    X.moveAndshow(n,1,2,3);
}

int main(){
	towersOfhanoi(8);
	return 0;
}
