#include <cstdio>
#include <cstring>
int main()
{
    char str[100];int one,len;
    while(scanf("%s",str),1)
    {
        if(str[0]==\'#\')return 0;
        one=0;
        len=strlen(str);
        for(int i=0;i<len-1;i++)
            if(str[i]==\'1\')one++;
        if((str[len-1]==\'o\'&&one%2==0)||(str[len-1]==\'e\'&&one%2==1))
            str[len-1]=\'1\';
        else
            str[len-1]=\'0\';
        puts(str);
    }
}