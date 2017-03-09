#include<stdio.h>
int main(){
	int a,i;
	char c[8]={"Umtorhs"};
	printf("%s\n",c);
	for(i=0;i<7;i++){
	    if((c[i]>='A')&&(c[i]<='Z')){
	    	a=c[i]-'A';
	    	c[i]='Z'-a;
	    }
	    if((c[i]>='a')&&(c[i]<='z')){
	    	a=c[i]-'a';
	    	c[i]='z'-a;
	    }
	    printf("%c",c[i]);
	}
	return 0;
} 
