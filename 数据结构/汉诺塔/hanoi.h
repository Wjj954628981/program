#ifndef HANOI_H 
#define HANOI_H 

using namespace std;

template<class T> class linkedStack;

template<class T>
class chainNode{
	friend linkedStack<T>;
	private:
		T element;
	    chainNode<T> *next;
};

template<class T>
class linkedStack{
	public:
		linkedStack(int initialCapacity=10){
			stackTop=NULL;
			stackSize=0;
		}
		~linkedStack();
		bool empty() const{return stackSize==0;}
		int size() const{return stackSize;}
		T& top(){
			if(stackSize==0)
			    throw empty();
			return stackTop->element;
		}
		void pop(T& theElement);
		void push(const T& theElement);
	private:
		chainNode<T>* stackTop;
		int stackSize;
};

template<class T>
linkedStack<T>::~linkedStack(){
	while(stackTop!=NULL){
		chainNode<T>* nextNode=stackTop->next;
		delete stackTop;
		stackTop=nextNode;
	}
}

template<class T>
void linkedStack<T>::pop(T& theElement){
	if(stackSize==0)
	    throw empty();
	theElement=stackTop->element;
	chainNode<T>* nextNode=stackTop->next;
	delete stackTop;
	stackTop=nextNode;
	stackSize--;
}

template<class T>
void linkedStack<T>::push(const T& theElement){
	chainNode<T>* p=new chainNode<T>;
	p->element=theElement;
	p->next=stackTop;
	stackTop=p;
	stackSize++;
}

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
