#include <iostream>

using namespace std;

bool isOneManFree(int n,bool*P)//�ж��Ƿ����������� 
{
    for(int i=0;i<n;i++)
    {
        if(*(P+i)==true)    return true;
    }
    return false;
}

int* Matching(int n,int**MP,int**WP)//����ƥ�� 
{
    bool isManFree[n],isWomanFree[n],isManProposed[n][n];//��Ů��������״̬�������Ƿ���Ů����� 
    int *match= new int[n];//��Ů���Ĵ����б� 
    for(int i=0;i<n;i++)//��ʼ����Ů��״̬ 
    {
        isManFree[i]=true;
        isWomanFree[i]=true;
        for(int j=0;j<n;j++){   isManProposed[i][j]=false;    }
        match[i]=-1;
    }
    while(isOneManFree(n,isManFree))//������������� 
    {
        int indexM;
        for(int i=0;i<n;i++)//�ҵ���˳���һ�����ɵ��������������� 
        {
            if(isManFree[i]==true)
			{
			 	indexM=i;break; 
			}
        }
        int indexWo;
        for(int i=0;i<n;i++)//�ҵ���������˳���һ��δ��׵�Ů�� 
        {
            int w=MP[indexM][i];
            if(isManProposed[indexM][w]==false)
			{ 
				indexWo=w;break;
			}
        }
        isManProposed[indexM][indexWo]=true;//��ף� 
        if(isWomanFree[indexWo])//�����Ů�����ɣ���ƥ��ɹ�����һ�� 
        {
            isManFree[indexM]=false;
            isWomanFree[indexWo]=false;
            match[indexM]=indexWo;
        }
        else//��Ů���Ѿ�����ƥ�䣬�����ж� 
        {
            int indexRival;//�ҵ����Ů��ƥ������� 
            for(int i=0;i<n;i++)
            {
                if(match[i]==indexWo)
				{ 
					indexRival=i;break; 
				}
            }
            int pM,pRival;
            for(int i=0;i<n;i++)
            {
                if(WP[indexWo][i]==indexM)  pM=i;
                if(WP[indexWo][i]==indexRival)  pRival=i;
            }
            if(pM<pRival)//�������������ǰ��ԭ��ƥ��������������ƥ��ɹ����������ı� 
            {
                isManFree[indexM]=false;
                isManFree[indexRival]=true;
                isWomanFree[indexWo]=false;
                match[indexM]=indexWo;
            }
        }
    }
    return match;
}

int main()
{
    int n;//ƥ������ 
    cin>>n;
    int**MP,**WP;
    MP=new int*[n];
    for(int i=0;i<n;i++)//��Ů������ 
    {
        MP[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>MP[i][j];
        }
    }
    WP=new int*[n];
    for(int i=0;i<n;i++)
    {
        WP[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>WP[i][j];
        }
    }
    for(int i=0;i<n;i++)//�����򻻳��������У���Ҫ����һ 
    {
        for(int j=0;j<n;j++)
        {
            MP[i][j]--;
            WP[i][j]--;
        }
    }
    int*match=Matching(n,MP,WP);//����ƥ�亯�� 
    for(int i=0;i<n;i++)//���ƥ��˳�� 
    {
        cout<<*(match+i)+1<<" ";
    }
    return 0;
}
