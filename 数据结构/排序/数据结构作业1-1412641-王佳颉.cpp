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
}//������� 
void Random(int a[],int n){
	srand(time(NULL));
	for (int i=0;i<n;i++){
		a[i]=rand()%1000;
	}
} //��������� 
void Sort::BubbleSort(int a[],int n){
	for(int i=0;i<n-1;i++){
	    for(int j=0;j<n-1;j++){
	    	if(a[j]>a[j+1])
	    	swap(a[j],a[j+1]);
	    }
	}
}//ð������ 
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
}//ѡ������ 
void Sort::InsertionSort(int a[],int n){
	for (int i=1;i<n;i++){
		int j,temp;
		temp=a[i];
		for (j=i-1;j>=0&&temp<a[j];j--){
		    a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}//�������� 
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
}//�������� 
int main(){
	clock_t start, end;
    double dif;
    Sort create;
    int n,k;
    cout<<"��������������С:"<<endl;
    cin>>n;
    int *a=new int[n];
    Random(a,n);
    cout<<"�������Ϊ��"; 
    Output(a,n);
    cout<<"��ѡ����������еĲ���:"<<"\n"
	<<"1.��������������ð������" <<"\n"
	<<"2.��������������ѡ������" <<"\n"
	<<"3.�������������в�������" <<"\n"
	<<"4.�������������п�������" <<"\n"
	<<"5.�Ը����������������" <<"\n";
	cin>>k; 
	if(k==1){
		start = clock();
		create.BubbleSort(a,n);
		cout<<"ð������:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==2){
		start = clock();
		create.SelecitionSort(a,n);
		cout<<"ѡ������:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==3){
		start = clock();
		create.InsertionSort(a,n);
		cout<<"��������:"; 
		Output(a,n);
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
	}
	if(k==4){
		start = clock();
		create.Quicksort(a,0,n-1);
		cout<<"��������:"; 
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
		cout<<"������A��������,����AΪ:";
		Output(b,12);
		cout<<endl;
		int x;
		cout<<"ѡ������ʽ��"<<"\n"
		<< "1.ð������"<<"\n"
		<<"2.ѡ������"<<"\n"
		<<"3.��������"<<"\n";
		cin>>x;
		start = clock();
		switch(x){
			case 1:{
				cout<<"ð������"; 
				create.BubbleSort(b,12);
				Output(b,12);
				break;
			}	
			case 2:{
				cout<<"ѡ������";
				create.SelecitionSort(b,12);
				Output(b,12);
				break;
			}
			case 3:{
				cout<<"��������";
				create.InsertionSort(b,12);
				Output(b,12);
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //����A���� 
		cout<<"������B��������,����CΪ:";
		Output(c,12);
		cout<<endl;
		int y;
		cout<<"ѡ������ʽ��"<<"\n"
		<< "1.ð������"<<"\n"
		<<"2.ѡ������"<<"\n"
		<<"3.��������"<<"\n";
		cin>>y;
		start = clock();
		switch(y){
			case 1:{
				cout<<"ð������"; 
				create.BubbleSort(c,12);
				Output(c,12);
				break;
			}	
			case 2:{
				cout<<"ѡ������";
				create.SelecitionSort(c,12);
				Output(c,12);
				break;
			}
			case 3:{
				cout<<"��������";
				create.InsertionSort(c,12);
				Output(c,12); 
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //����B���� 
        cout<<"������C��������,����CΪ:";
		Output(d,12);
		cout<<endl;
		int z;
		cout<<"ѡ������ʽ��"<<"\n"
		<< "1.ð������"<<"\n"
		<<"2.ѡ������"<<"\n"
		<<"3.��������"<<"\n";
		cin>>z;
		start = clock();
		switch(z){
			case 1:{
				cout<<"ð������"; 
				create.BubbleSort(d,12);
				Output(c,12);
				break;
			}	
			case 2:{
				cout<<"ѡ������";
				create.SelecitionSort(d,12);
				Output(c,12);
				break;
			}
			case 3:{
				cout<<"��������";
				create.InsertionSort(d,12);
				Output(c,12);
				break;
			}
		}
		end = clock();
        dif = end - start;
        cout << " time consumed "<< dif/CLOCKS_PER_SEC << " seconds. " << endl;
        //����C���� 
	}
    return 0;
} 
