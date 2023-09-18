#include "stdio.h"
#include "string.h"

int casenum,cases,n,i,value[50],sumvalue,solvenum,pre;
char sequence[50][2],w[50],lastanswer[41],tempanswer[41];

void test(int sumvalue,int first)
{
    int i;
    if (sumvalue==0)
    if (strcmp(lastanswer,tempanswer)!=0)
    {
        solvenum++;
        strcpy(lastanswer,tempanswer);
        printf("%s\n",tempanswer);
        return;
    }
    for(i=first+1;i<=n;i++)
        if(value[i]!=pre)
        if(sumvalue-value[i]>=0)
        {
            strcat(tempanswer,sequence[i]);
            test(sumvalue-value[i],i);
            tempanswer[strlen(tempanswer)-1]=\'\0\';
        }
        else return;
    if(first!=0)
        pre=value[first];
}

int main()
{
    scanf("%d",&casenum);
    for(cases=1;cases<=casenum;cases++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",&sequence[i]);
            value[i]=sequence[i][0]-65+1;
        }
        scanf("%s",&w);
        sumvalue=0;
        for(i=0;i<strlen(w);i++)
            sumvalue=sumvalue+w[i]-65+1;
        solvenum=0;
        strcpy(tempanswer,"\0");
        strcpy(lastanswer,"\0");
        printf("Case %d\n",cases);
        pre=0;
        test(sumvalue,0);
        if (solvenum==0) printf("NONE\n");
    }
return 0;
}