#include <malloc.h>

#ifndef STACKOFINTEGER_H
#define STACKOFINTEGER_H

struct LinkList//ʹ��������Զ�̬�ķ����ڴ�....���ﵽ��ν�Ĵ����������Ŀ�� 
{
char data;
struct LinkList *next;
};


class StackOfIntegers{
	private:
	LinkList *L;
	
	public:
	StackOfIntegers();
 	const bool isEmpty();//�ж��Ƿ�Ϊ�� 
 	const int Peek();
 	void push(int x);//��ջ 
 	int pop();//��ջ 
 	const int getSize();//�󳤶�	
};

StackOfIntegers::StackOfIntegers()
{
			L=(LinkList *)malloc(sizeof(LinkList));
			L->next=NULL;
			L->data=0;
}

void StackOfIntegers::push(int x)//��ջ 
{	
		
	LinkList *s;
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=x;
	s->next=L->next;
	L->next=s;	
}

int StackOfIntegers::pop()//��ջ 
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

const bool StackOfIntegers::isEmpty()//�ж��Ƿ�Ϊ�� 
{
	if(L->next==NULL)
	return true;
	else
	return false;
}

const int StackOfIntegers::getSize()//��Ԫ�ظ��� 
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

const int StackOfIntegers::Peek()//������ջ�����ֵ 
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