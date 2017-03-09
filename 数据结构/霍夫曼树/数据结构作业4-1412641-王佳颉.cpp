#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm> 

using namespace std;

struct Node
{
	char content;
	int freq;
	string code;
	Node *left;
	Node *right;
	Node(){left=right=NULL;}; 
};

bool compare(Node* a,Node* b)
{
		return a->freq> b->freq;	//按照降序排列 
}

class HolfTree
{
		private:		
		Node *root;
		void OutPutToStream(Node* p);
		void OutToFileStream(Node * node,string &str,int depth);
		string  NumToStr(int num);
		public:
		HolfTree(){root=new Node();};
		void BulidTree(string filename);
		void OutPut();
		void OutToFile(string str3);
		void OutToString(string filename);
};

string  HolfTree::NumToStr(int num)
{
	string x;
	stringstream ss;
	ss<<num;
	ss>>x	;
	return x;
};

//构造霍夫曼树 
void HolfTree::BulidTree(string filename)
{
		//获取文件名，打开文件，建立输入流 
		ifstream in(filename);
		string str;//用于保存从文件下来的字符串 
		char p;
		while(in.read(&p,1))
		{
			str+=p;
		}
		//统计各个字母出现的频率 
		string mychar;
		vector<int> count;
		vector<string> allstring;
		for(int i=0;i<str.size();i++)
		{
			
			int pos=-1;
			for(int k=0;k<=mychar.size();k++)
			{	
				if(mychar[k]==str[i])
					{
					pos=k;
					break;
					}
			}			
			//这里不能用if(pos)，因为pos有可能是0 
			if(pos!=-1)
				{
					count[pos]++;
				}
			else
			{
				mychar+=str[i];
				count.push_back(1);					
			}
		}
		//将字母与count转换为结构体Node
		vector<Node *> nodestack;
		for(int i=0;i<mychar.size();i++)
		{
			Node *p=new Node();
			p->content=mychar[i];
			p->freq=count[i];
			nodestack.push_back(p);
		}
		//将所有的node都放入了nodestack里面了，利用它来生成树
		while(nodestack.size()!=1)
		{
				//暴力的冒泡排序 
		  	sort(nodestack.begin(),nodestack.end(),compare);
				//将最小的两位 
				Node *p=new Node();
				//左孩子的权重比右孩子的权重大
				 	
				p->right=nodestack.back();
				nodestack.pop_back();
				p->left=nodestack.back();
				nodestack.pop_back();
				p->content='0';
				p->freq=p->left->freq+p->right->freq; 
				nodestack.push_back(p);
		} 
		root=nodestack.back();
		nodestack.pop_back();
};

//输出到控制台 字符频率和编码 
void  HolfTree::OutPut()
{
	OutPutToStream(root);
};
void HolfTree::OutPutToStream(Node* p)
{
		if(p->content!='0')
		cout<<"char:"<<p->content<<"   frequnce:"<<p->freq<<"   code:"<<p->code<<endl;
		if(p->left==NULL&&p->right==NULL)
		return;
		p->left->code=p->code+'0';
		p->right->code=p->code+'1';
		OutPutToStream(p->left);
		OutPutToStream(p->right);
}
     
//输出霍夫曼树到文件 
void HolfTree::OutToFile(string str3)
{
		string x,y;
		int i=0;
		do
		{
		y.clear();
		OutToFileStream(root,y,i);
		x+=y;
		x+='\n';
		i++;
		}while(y.size()!=0);
		ofstream out(str3);
		out.write(x.c_str(),x.size());
		out.close();
};
vo id HolfTree::OutToFileStream(Node * node,string &str,int depth)
{
	if(node->code.size()==depth)
	{
	for(int i=0;i<20/(depth+1);i++)
	{
		str+=" ";
	} 	
	 if(node->content=='0')
				{				
				str+=NumToStr(node->freq);
				}
			else
				{		 
				str+=node->content;
				}
	} 
	if(node->left==NULL&&node->right==NULL)
	return;
	OutToFileStream(node->left,str,depth);
	OutToFileStream(node->right,str,depth);
};

//解码
void HolfTree::OutToString(string filename)
{
	
		ifstream in(filename);
		string str;//用于保存从文件下来的字符串 
		char p1;
		while(in.read(&p1,1))
		{
			str+=p1;
		}
		
		Node *p=root;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='0')
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
			if(p->content!='0')
			{
				cout<<p->content;
				p=root;
			}
		}
};

int main()
{
	string str1="inputfile1.txt";
	cout<<"霍夫曼编码编码："<<endl;
	HolfTree ht;
	ht.BulidTree(str1);
	ht.OutPut();
	string str3="outputfile1.txt";
	ht.OutToFile(str3);
	cout<<"霍夫曼编码解码："<<endl;
	string str2="inputfile2.txt";
	ht.OutToString(str2);
	cout<<endl;
	return 0; 
} 