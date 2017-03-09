#include <iostream>

using namespace std;

bool isOneManFree(int n,bool*P)//判断是否有男生自由 
{
    for(int i=0;i<n;i++)
    {
        if(*(P+i)==true)    return true;
    }
    return false;
}

int* Matching(int n,int**MP,int**WP)//进行匹配 
{
    bool isManFree[n],isWomanFree[n],isManProposed[n][n];//男女生的自由状态和男生是否向女生表白 
    int *match= new int[n];//男女生的搭配列表 
    for(int i=0;i<n;i++)//初始化男女生状态 
    {
        isManFree[i]=true;
        isWomanFree[i]=true;
        for(int j=0;j<n;j++){   isManProposed[i][j]=false;    }
        match[i]=-1;
    }
    while(isOneManFree(n,isManFree))//如果有男生自由 
    {
        int indexM;
        for(int i=0;i<n;i++)//找到按顺序第一个自由的男生对其进行配对 
        {
            if(isManFree[i]==true)
			{
			 	indexM=i;break; 
			}
        }
        int indexWo;
        for(int i=0;i<n;i++)//找到该男生按顺序第一个未表白的女生 
        {
            int w=MP[indexM][i];
            if(isManProposed[indexM][w]==false)
			{ 
				indexWo=w;break;
			}
        }
        isManProposed[indexM][indexWo]=true;//表白！ 
        if(isWomanFree[indexWo])//如果该女生自由，则匹配成功，在一起！ 
        {
            isManFree[indexM]=false;
            isWomanFree[indexWo]=false;
            match[indexM]=indexWo;
        }
        else//该女生已经有了匹配，进行判断 
        {
            int indexRival;//找到与该女生匹配的男生 
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
            if(pM<pRival)//如果该男生排名前于原来匹配男生，则重新匹配成功！否则不作改变 
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
    int n;//匹配组数 
    cin>>n;
    int**MP,**WP;
    MP=new int*[n];
    for(int i=0;i<n;i++)//男女生排序 
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
    for(int i=0;i<n;i++)//把排序换成数组序列，需要都减一 
    {
        for(int j=0;j<n;j++)
        {
            MP[i][j]--;
            WP[i][j]--;
        }
    }
    int*match=Matching(n,MP,WP);//调用匹配函数 
    for(int i=0;i<n;i++)//输出匹配顺序 
    {
        cout<<*(match+i)+1<<" ";
    }
    return 0;
}
