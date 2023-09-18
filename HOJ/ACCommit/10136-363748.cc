#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[2000];
    int len;bool flag;
    while(cin.getline(str,1900))
    {
        len=strlen(str);flag=1;
        for(int i=0,j=len-1;i<=j;i++,j--)
            if(!(str[i]==str[j]||str[i]+32==str[j]||str[i]==str[j]+32))
            {flag=0;break;}
        if(flag)cout <<"yes" <<endl;
        else cout <<"no" <<endl;
    }
}