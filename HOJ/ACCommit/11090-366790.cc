#include <cstdio>

const char MOD = 61;
const short SIZE=10010;
char str[SIZE];
int len,total;

void Init()
{
    total=0;
    for(len=0;str[len];len++)
    {
        if(str[len]<=\'9\')
            str[len]-=\'0\';
        else if(str[len]<=\'Z\')
            str[len]-=(\'A\'-10);
        else str[len]-=(\'a\'-36);
        total+=str[len];
    }
}

int main()
{
    while(gets(str))
    {
        if(str[0]==\'e\'&&str[1]==\'n\'&&str[2]==\'d\')return 0;
        Init();
        if(total%MOD)printf("no\n");
        else printf("yes\n");
    }
}