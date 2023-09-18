#include "stdio.h"
int main()
{
    int i,j,ret;
    char ch[105];
    while(-1!=(ret=scanf("%[^\n]",ch)))
    {
        if(ret==0)
            ch[0]=0;
        getchar();
        for(i=0;ch[i] && ch[i+1] && ch[i+2];i++)
        {
            if(ch[i]==\'B\'&&ch[i+1]==\'U\' &&ch[i+2]==\'G\')
            {
                for(j=i;ch[j+3];j++)
                    ch[j]=ch[j+3];
                ch[j]=0;
                i-=3;
                if(i<-1)
                    i=-1;
            }
        }
        printf("%s\n",ch);
    }
    return 0;
}