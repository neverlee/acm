#include <cstdio>
#include <cstring>

char sta[100],stb[100];
int len;

void GetSmallest()
{
    int i,k;bool isLong;
    for(i=len-1;i>=0;i--)
    {
        if(sta[len-1]==stb[i])
        {
            isLong=1;
            for(k=1;i-k>=0;k++)
                if(sta[len-1-k]!=stb[i-k])
                {isLong=0;break;}
            if(isLong)
            {
                sta[len-k]=0;
                if(len-k)printf("%s",sta);
                puts(stb);
                return;
            }
        }
    }
}

int main()
{
    while(scanf("%s",sta)!=EOF)
    {
        len=strlen(sta);
        for(int i=0;i<len;i++)
            stb[i]=sta[len-i-1];
        stb[len]=0;
        GetSmallest();
    }
    return 0;
}