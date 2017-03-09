#include <malloc.h>

#ifndef STACKOFINTEGER_H
#define STACKOFINTEGER_H

struct LinkList//使用链表可以动态的分配内存....即达到所谓的存任意个数的目的 
{
char data;
struct LinkList *next;
};


class StackOfIntegers{
	private:
	LinkList *L;
	
	public:
	StackOfIntegers();
 	const bool isEmpty();//判断是否为空 
 	const int Peek();
 	void push(int x);//入栈 
 	int pop();//出栈 
 	const int getSize();//求长度	
};

StackOfIntegers::StackOfIntegers()
{
			L=(LinkList *)malloc(sizeof(LinkList));
			L->next=NULL;
			L->data=0;
}

void StackOfIntegers::push(int x)//入栈 
{	
		
	LinkList *s;
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=x;
	s->next=L->next;
	L->next=s;	
}

int StackOfIntegers::pop()//出栈 
{
	
	int last;
	LinkList *p,*q;
	p=L->next;
	last=p->data;
	q=p;
	p=p->next;
	free(q);
	L->next=p;
	return last;
}

const bool StackOfIntegers::isEmpty()//判断是否为空 
{
	if(L->next==NULL)
	return true;
	else
	return false;
}

const int StackOfIntegers::getSize()//求元素个数 
{
	LinkList *p;
	int x=0;
	p=L;
	while(p->next!=NULL)
	{	
		x++;
		p=p->next;		
	}

return x;
}

const int StackOfIntegers::Peek()//求出这个栈的最大值 
{
	LinkList *p;
	p=L;
	int x=0;
	 
	while(p->next!=NULL)
	{	
		p=p->next;
		if(x<=p->data)
		{
		x=p->data;	
		}
	}
	
	return x;
} 


#endif