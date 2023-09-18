#include <iostream>
#include <cstring>
using namespace std;

char str[1020];int len,re;
int main()
{
    while(cin.getline(str,1010))
    {
        re=len=strlen(str);
        int i,j=0;
        for(i=0;i<len-1;i++)
        {
            if(str[i]==\'<\')
            {
                if(j<=i)j=i+1;
                while(str[j]!=\'>\'&&j<len)j++;
                if(j==len)break;
                str[i]=str[j]=0;re-=2;
            }
        }
        cout <<re <<endl;
    }
    return 0;
}