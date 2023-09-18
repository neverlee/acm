#include "stdio.h"

int i,n,destination,list[15],total_answer,answer[15];

void dep(int m)
{
    int i,j,list_1[15];

    if(m>=n)
    {
        if(list[1]==destination) 
        {
            total_answer++;
            if (total_answer==1) 
                for(j=1;j<=n-1;j++)
                    printf("%d\n",answer[j]);
        }
            return;
        }

    for(j=1;j<=n-m+1;j++) list_1[j]=list[j];

    for(i=1;i<=n-m+1-1;i++)
    {
        list[i]=list[i]-list[i+1];
        answer[m]=i;
        for(j=i+1;j<=n-m+1-1;j++)list[j]=list[j+1];

        dep(m+1);

        for(j=1;j<=n-m+1;j++) list[j]=list_1[j];
    }
}

int main()
{
    while(scanf("%d",&n)!=-1)
    {
        total_answer=0;
        scanf("%d",&destination);
        for(i=1;i<=n;i++)
        scanf("%d",&list[i]);
        dep(1);
        printf("%d\n",total_answer);
    }
}