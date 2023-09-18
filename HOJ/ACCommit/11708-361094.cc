#include <cstdio>
#include <cstring>
int main()
{
    char str[10000];short len;char re,k;
    while(gets(str))
    {
        len=strlen(str);
        if(str[len-1]!=9&&str[len-8]!=32)continue;
        re=0;k=1;
        for(int i=len-1;i>=len-8;i--)
        {
            if(str[i]==9)
                re|=k;
            k<<=1;
        }
        putchar(re);
    }
    putchar(\'\n\');
    return 0;
}