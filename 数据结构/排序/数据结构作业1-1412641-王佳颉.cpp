#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Sort{
	public:
		void BubbleSort(int a[],int n);
		void SelecitionSort(int a[],int n);
		void InsertionSort(int a[],int n);
		void Quicksort(int a[],int l,int );
};
void Output(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}//数组输出 
void Random(int a[],int n){
	srand(time(NULL));
	for (int i=0;i<n;i++){
		a[i]=rand()%1000;
	}
} //生成随机数 
void Sort::BubbleSort(int a[],int n){
	for(int i=0;i<n-1;i++){
	    for(int j=0;j<n-1;j++){
	    	if(a[j]>a[j+1])
	    	swap(a[j],a[j+1]);
	    }
	}
}//冒泡排序 
void Sort::SelecitionSort(int a[],int n){
	bool sorted=false;
	for (int size=n;!sorted&&(size>1);size--){
	    int indexofmax= 0;
	    sorted =true;
	    for (int i=1;i<size;i++){
	    	if(a[indexofmax]<=a[i])
	        indexofmax=i;
	        else sorted=false;
            swap (a[indexofmax],a[size-1]);
	    }  
	}
}//选择排序 
void Sort::InsertionSort(int a[],int n){
	for (int i=1;i<n;i++){
		int j,temp;
		temp=a[i];
		for (j=i-1;j>=0&&temp<a[j];j--){
		    a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}//插入排序 
void Sort::Quicksort(int a[],int l,int r){
   if(l>=r){
	 return;
	 }
	 int left=l,right=r;
	 while(left<right){
         while(left<right&&a[left]<=a[right]){
         	right--;
         }
	     if(left<right){
	     	int temp=a[left];
	 	    a[left]=a[right];
	 	    a[right]=temp;
	     }
	     while(left<right&&a[left]<=a[right]){
	     	left++;
	     }
	     if(left<right){
	     	int temp=a[left];
	 	    a[left]=a[right];
	 	    a[right]=temp;
	     }
}
	 Quicksort(a,l,left-1);
	 Quicksort(a,left+1,r);
}//快速排序 
int main(){
	clock_t start, end;
    double dif;
    Sort create;
    int n,k;
    cout<<"请输入随机数组大小:"<<endl;
    cin>>n;
    int *a=new int[n];
    Random(a,n);
    cout<<"随机数组为："; 
    Output(a,n);
    cout<<"请选择接下来进行的操作:"<<"\n"
	<<"1.对随机数数组进行冒泡排序" <<"\n"
	<<"2.对随机数数组进行选择排序" <<"\n"
	<<"3.对随机数数组进行插入排序" <<"\n"
	<<"4.对随机数数组进行快速排序" <<"\n"
	<<"5.对给定数数组进行排序" <<"\n";
	cin>>k; 
	if(k==1){
		start = clock();
		create.BubbleSort(a,n);
		cout<<"冒泡排序:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==2){
		start = clock();
		create.SelecitionSort(a,n);
		cout<<"选择排序:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==3){
		start = clock();
		create.InsertionSort(a,n);
		cout<<"插入排序:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==4){
		start = clock();
		create.Quicksort(a,0,n-1);
		cout<<"快速排序:"; 
		for (int i=0;i<n;i++)
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	} 
	if(k==5){
		int b[12]={15,11,20,5,3,3,2,9,9,8,16,13};
		int c[12]={11,15,16,17,24,25,29,36,37,43,46,48};
		int d[12]={46,40,34,32,30,29,27,24,22,16,9,2};
		cout<<"对数组A进行排序,数组A为:";
		Output(b,12);
		cout<<endl;
		int x;
		cout<<"选择排序方式："<<"\n"
		<< "1.冒泡排序"<<"\n"
		<<"2.选择排序"<<"\n"
		<<"3.插入排序"<<"\n";
		cin>>x;
		start = clock();
		switch(x){
			case 1:{
				cout<<"冒泡排序："; 
				create.BubbleSort(b,12);
				Output(b,12);
				break;
			}	
			case 2:{
				cout<<"选择排序：";
				create.SelecitionSort(b,12);
				Output(b,12);
				break;
			}
			case 3:{
				cout<<"插入排序：";
				create.InsertionSort(b,12);
				Output(b,12);
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //数组A排序 
		cout<<"对数组B进行排序,数组C为:";
		Output(c,12);
		cout<<endl;
		int y;
		cout<<"选择排序方式："<<"\n"
		<< "1.冒泡排序"<<"\n"
		<<"2.选择排序"<<"\n"
		<<"3.插入排序"<<"\n";
		cin>>y;
		start = clock();
		switch(y){
			case 1:{
				cout<<"冒泡排序："; 
				create.BubbleSort(c,12);
				Output(c,12);
				break;
			}	
			case 2:{
				cout<<"选择排序：";
				create.SelecitionSort(c,12);
				Output(c,12);
				break;
			}
			case 3:{
				cout<<"插入排序：";
				create.InsertionSort(c,12);
				Output(c,12); 
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //数组B排序 
        cout<<"对数组C进行排序,数组C为:";
		Output(d,12);
		cout<<endl;
		int z;
		cout<<"选择排序方式："<<"\n"
		<< "1.冒泡排序"<<"\n"
		<<"2.选择排序"<<"\n"
		<<"3.插入排序"<<"\n";
		cin>>z;
		start = clock();
		switch(z){
			case 1:{
				cout<<"冒泡排序："; 
				create.BubbleSort(d,12);
				Output(c,12);
				break;
			}	
			case 2:{
				cout<<"选择排序：";
				create.SelecitionSort(d,12);
				Output(c,12);
				break;
			}
			case 3:{
				cout<<"插入排序：";
				create.InsertionSort(d,12);
				Output(c,12);
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //数组C排序 
	}
    return 0;
} 
