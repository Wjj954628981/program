#include<stdio.h>
int main(){
	int b,a,ans,n;
	printf("������a��n��ֵ��\n");
	scanf("%d%d",&a,&n);
	int i;ans=0;b=a;
	for(i=1;i<=n;i++){
		ans=ans+b;
		b=b*10+a;
	}
	printf("�����ֵΪ��%d\n",ans);
	getchar();
	return 0;
}
