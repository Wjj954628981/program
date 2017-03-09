#include<stdio.h>
int main(){
	int b,a,ans,n;
	printf("请输入a与n的值：\n");
	scanf("%d%d",&a,&n);
	int i;ans=0;b=a;
	for(i=1;i<=n;i++){
		ans=ans+b;
		b=b*10+a;
	}
	printf("所求的值为：%d\n",ans);
	getchar();
	return 0;
}
