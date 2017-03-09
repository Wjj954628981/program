#include <stdio.h>
#include <string.h>
#include <iostream> 

using namespace std;

int main()
{
        int SubStrPosition(char *str1, char *str2);
        char a[100],b[100];
        cin>>a;
        cin>>b;
        char *str1 =a;
        char *str2 =b;
        for(int i=0;i<SubStrPosition(str1,str2)-1;i++){
        	cout<<a[i];
        }
        return 0;
}

/* 查找str2在str1中的位置,不存在时返回-1 */
int SubStrPosition(char *str1,char *str2)
{
        int istr1Len = 0;
        int istr2Len = 0;
        
        int i = 0;
        int j = 0;
        int iPosition = -1;

        istr1Len = strlen(str1);
        istr2Len = strlen(str2);
        if (istr2Len > istr1Len)
        {
                cout<<"Str2 cann't be the substring of str1.\n";
        }

        /* 开始寻找str2在str1中的位置，不区分大小写 */
        for (i; i < istr1Len; i++)
        {
                for (j; j < istr2Len; j++)
                {
                        if (!((str1[i+j] == str2[j]) || (str1[i+j] == str2[j] + 32) 
                                || (str1[i+j] == str2[j] - 32)))
                                break;
                }

                if (j == istr2Len)
                {
                        iPosition = i+1;
                        break;
                }
        }	

        return iPosition;
}
