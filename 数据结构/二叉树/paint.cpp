#include <iostream>  
#include <stack>  
#include <string>  

using namespace std;  

class BinaryTreeNode{
    public:
    	char data;
    	BinaryTreeNode *LeftChild,*RightChild;
    	BinaryTreeNode(char e){
    		data=e;LeftChild=RightChild=0;
    	}
};

BinaryTreeNode *Create(string src){
	BinaryTreeNode *ptr;
	stack<BinaryTreeNode *>st;
	char c;
	int i=0;
	c=src[i++];
	while(c!='\0'){
		if(c!='+' && c!='-' && c!='*' && c!='/'){
			ptr=new BinaryTreeNode(c);
			st.push(ptr);
			c=src[i++];
		}
		else{
			ptr=new BinaryTreeNode(c);
			if(!st.empty()){
				ptr->RightChild=st.top();
				st.pop();
			}
			if(!st.empty()){
				ptr->LeftChild=st.top();
				st.pop();
			}
			st.push(ptr);
			c=src[i++];
		}
	}
	return ptr;
}

void Print(BinaryTreeNode *t,int n){
	if(t){
		Print(t->RightChild,n+1);
		for(int i=0;i<n;i++){
			cout<<"  ";
		}
        cout<<t->data<<endl;
        Print(t->LeftChild,n+1); 
	}	 	
}

int prior(char op){
	if(op=='+'||op=='-')  
       return 1;  
    if(op=='*'||op=='/')  
       return 2;  
    return 0; 
}//返回优先级 

string Middletolast(string middle){
	stack<char> op; 
	string ans;
	for(int i=0;i<middle.size();i++){
		char c=middle[i];
	    if(c>='a'&&c<='z'){
	    	ans.append(1,c);
		}
		else{
			if(c=='(')
			    op.push('(');
			else{
				if(c==')'){
					 while(op.top()!='('){
					 	ans.append(1,op.top());  
                        op.pop();
					 } 
					 op.pop(); 
				} 
				else{
					if(op.empty()){
						op.push(c);
					}
					else{
						if(prior(c)>prior(op.top())){
							op.push(c);
						}
						else{
							while(!op.empty()&&prior(c)<=prior(op.top())){
								ans.append(1,op.top());
								op.pop();
							}
							op.push(c);
						}
					}
				} 
			} 
		} 
	} 
	while(!op.empty()){
		ans.append(1,op.top());
		op.pop();
	}
	return ans;
}    

int main(){
	string m;
	cout<<"输入中序表达式:";
	cin>>m;
	string n=Middletolast(m);
	cout<<"后序表达式为:"<<n<<endl;
	BinaryTreeNode *r;
	r=Create(n);
    Print(r,1);
    return 0; 
} 
