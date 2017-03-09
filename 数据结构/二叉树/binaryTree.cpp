#include<iostream>
#include<queue>

using namespace std;

template<class T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode<T> *leftChild,*rightChild;
		BinaryTreeNode(const T &e,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r){
			data=e;leftChild=l;rightChild=r;
		}

};

template<class T>
class BinaryTree{
	public:
		BinaryTreeNode<T> *root;
		BinaryTree(){root=NULL;};
		~BinaryTree(){DestroyTree();};
		void Pre_Order();
        void In_Order();
        void Post_Order();
        void Level_Order(); 
        int TreeHeight()const;
        int TreeWidth();
        void DestroyTree();
/*        BinaryTreeNode<T> *ArrayTree(int a[],int start,int end){
        	if(start>end){
        		return NULL;
        	}
        	int m=start+(end-start)/2;
        	BinaryTreeNode<T> *r=new BinaryTreeNode<T>();
        	r->data=a[m];
        	r->leftChild=ArrayTree(a,start,m-1);
        	r->rightChild=ArrayTree(a,m+1,end);
        	return r;
        }*/
		BinaryTreeNode<T> *MakeTree(const T&element,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r){
			root=new BinaryTreeNode<T>(element,l,r);
			return root;
		}
	private:
		void Destroy(BinaryTreeNode<T> *&r);
		void PreOrder(BinaryTreeNode<T> *r);
		void InOrder(BinaryTreeNode<T> *r);
		void PostOrder(BinaryTreeNode<T> *r);
		void LevelOrder(BinaryTreeNode<T> *r);
		int Height(const BinaryTreeNode<T> *r)const;
		int Width(BinaryTreeNode<T> *r);
};

template<class T>
void BinaryTree<T>::Pre_Order(){
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::In_Order(){
	InOrder(root);
}

template<class T>
void BinaryTree<T>::Post_Order(){
	PostOrder(root);
}

template<class T>
void BinaryTree<T>::Level_Order(){
	LevelOrder(root);
}

template<class T>
int BinaryTree<T>::TreeHeight()const{
	return Height(root);
}

template<class T>
int BinaryTree<T>::TreeWidth(){
	return Width(root);
}

template<class T>
void BinaryTree<T>::DestroyTree(){
	Destroy(root);
}

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *r){
	if(r!=NULL){
		cout<<r->data<<" ";
		PreOrder(r->leftChild);
		PreOrder(r->rightChild);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *r){
	if(r!=NULL){
		PreOrder(r->leftChild);
		cout<<r->data<<" ";
		PreOrder(r->rightChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *r){
	if(r!=NULL){
		PreOrder(r->leftChild);
		PreOrder(r->rightChild);
		cout<<r->data<<" ";
	}
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T> *r){
	queue<BinaryTreeNode<T>*> q;
	while(r!=NULL){
		cout<<r->data<<" ";
		if(r->leftChild)
		    q.push(r->leftChild);
		if(r->rightChild)
		    q.push(r->rightChild);
		if(q.empty()){return;}
		r=q.front();
		q.pop();
	}
}

template<class T>
int BinaryTree<T>::Height(const BinaryTreeNode<T> *r)const{
	if(r==NULL)
	  return 0;
	else{
		int lh,rh;
		lh=Height(r->leftChild);
		rh=Height(r->rightChild);
		return 1+(lh>rh?lh:rh);
	}
}

template<class T>
int BinaryTree<T>::Width(BinaryTreeNode<T> *r){
	if(r==NULL){
		return 0;
	}  
    queue<BinaryTreeNode<T>*> MyQueue;
    MyQueue.push(r);
    int width=1;//宽度 
    int curwidth=1;//当前层宽度 
    int nextwidth=0;//下一层宽度 
    while(!MyQueue.empty())
    {  
        while(curwidth!=0){
        	BinaryTreeNode<T>* p=MyQueue.front();
        	MyQueue.pop();
        	curwidth--;
        	if(p->leftChild!=NULL){
        		MyQueue.push(p->leftChild);
        		nextwidth++; 
        	}
        	if (p->rightChild!=NULL){
        		MyQueue.push(p->rightChild);
        		nextwidth++;
        	}
        }
        if(nextwidth>width){
        	width=nextwidth;
		}
        curwidth=nextwidth;  
        nextwidth=0;  
    }  
    return width;
}



template<class T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *&r){
	if(r!=NULL){
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r=NULL;
	}
}

template<class T>
void SwapChild(BinaryTreeNode<T> *r){
	if(r!=NULL){
		BinaryTreeNode<T> *temp;
		if(r){
		    temp=r->leftChild;
		    r->leftChild=r->rightChild;
		    r->rightChild=temp;
		    SwapChild(r->leftChild); 
		    SwapChild(r->rightChild);
	    }
	}
}
int main(){
	BinaryTreeNode<int> *b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*l,*m,*n,*o,*p,*q,*r,*s,*t,*u,*v,*w;
    BinaryTree<int> a;
    b=a.MakeTree(9,NULL,NULL);
    c=a.MakeTree(14,NULL,NULL);
    d=a.MakeTree(6,NULL,NULL);
    e=a.MakeTree(28,NULL,NULL);
    f=a.MakeTree(3,NULL,NULL);
    g=a.MakeTree(18,NULL,NULL);
    h=a.MakeTree(14,NULL,NULL);
    i=a.MakeTree(27,NULL,NULL);
    j=a.MakeTree(10,b,c);
    k=a.MakeTree(26,d,NULL);
    l=a.MakeTree(2,NULL,e);
    m=a.MakeTree(19,f,NULL);
    n=a.MakeTree(8,g,NULL);
    o=a.MakeTree(6,h,i);
    p=a.MakeTree(5,j,k);
    q=a.MakeTree(8,l,m);
    r=a.MakeTree(26,NULL,n);
    s=a.MakeTree(1,NULL,o);
    t=a.MakeTree(7,p,q);
    u=a.MakeTree(18,r,s);
    v=a.MakeTree(15,t,u);
//    int inOrderarray[]={9,10,14,5,6,26,0,7,0,2,28,8,3,19,0,15,0,0,0,26,18,8,0,18,0,0,0,1,14,6,27}; //将树补成满二叉树
//	a.root=a.ArrayTree(inOrderarray,0,30);
    cout<<"二叉树层次遍历为："<<endl;
    a.Level_Order();
    cout<<endl;
    cout<<"二叉树的宽度为："<<a.TreeWidth()<<endl; 
    SwapChild(a.root);
    cout<<"交换左右孩子后二叉树层次遍历为："<<endl;
    a.Level_Order();
    cout<<endl;
    cout<<"交换左右孩子后二叉树的宽度为："<<a.TreeWidth()<<endl; 
}
