#include <cstdio>
#include <cstring>

int main()
{
    short len;
    char str[100]={0},temp[100];
    printf("Spinlock Results\n");
    while(gets(temp))
    {
        if(temp[0]==\'z\')return 0;
        if(temp[0]==\'x\')
        {
            for(int i=0;i<len;i++)
                printf("%d",str[i]);
            puts("");
            for(int i=0;i<100;i++)
                str[i]=0;
        }
        else
        {
            len=strlen(temp);
            for(int i=0;i<len;i++)
            {
                str[i]+=(temp[i]-\'0\');
                str[i]%=10;
            }
        }
    }
}