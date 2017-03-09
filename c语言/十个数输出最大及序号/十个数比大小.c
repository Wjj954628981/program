#include<stdio.h>
int main(){
	int a[10],max,n,i,j,x; 
	printf("请输入十个数字:");
	for(x=0;x<10;x++){
		scanf("%d",&a[x]);
	} 
	max=a[0];
	for(i=1;i<10;i++){
		j=i+1;
		if(max<=a[i]){
			max=a[i];
			n=j;
		}
	}
	printf("max=%d,n=%d",max,n);
	return 0;
}
