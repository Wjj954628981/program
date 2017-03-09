#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(void){ 
	vector<vector<int> > v;
	int Row,Col;
	cin>>Row>>Col;
    srand(time(0));          
	int i,j;
	v.resize(Row);
	for(i=0;i<Row;i++){
		v[i].resize(Col);
		for(j=0;j<Col;j++){ 
			v[i][j]=rand() % 100+ 1;
		}
	}
	cout<<"before sorting:"<<"\n";
	for(i=0;i<Row;i++){ 
		for(j=0;j<Col;j++){ 
			cout<<v[i][j]<<"\t";
		}
		cout<<endl; 
	}
	cout<<"after sorting:"<<"\n";
	for(i=0;i<Row;i++){ 
	    sort(v[i].begin(),v[i].begin()+Col);
	    for(j=0;j<Col;j++){ 
	        cout<<v[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
