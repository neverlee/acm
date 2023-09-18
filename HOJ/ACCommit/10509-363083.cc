#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long binary[40]={0};
    long k=1,t,len;
    for(int i=0;i<40;i++)
        binary[i]=(k<<=1)-1;
    char str[100];
    while(cin >>str)
    {
        if(str[0]==\'0\')return 0;
        len=strlen(str);
        k=0;t=0;
        for(int i=len-1;i>=0;i--,t++)
            k+=(binary[t]*(str[i]-\'0\'));
        cout <<k <<endl;
    }
}