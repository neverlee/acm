#include<cstdio>
const long long Max=1LL<<32;
long long n3[30],na3[30],num;
char result[20];
void SetN3()
{
    n3[0]=na3[0]=1;
    for(int i=1;(n3[i]=3*n3[i-1])<=Max;i++)
        na3[i]=na3[i-1]+n3[i];
}

void GetResult()
{
    for(int i=20;i>=0;i--)
    {
        result[i]=\'0\';
        if(num>na3[i-1]&&num<=na3[i])
        {num-=n3[i];result[i]=\'1\';}
        if(num<-na3[i-1]&&num>=-na3[i])
        {num+=n3[i];result[i]=\'-\';}
    }
    if(num==1)result[0]=\'1\';
    if(num==-1)result[0]=\'-\';
}

int main()
{
    SetN3();
    while(scanf("%I64d",&num)!=EOF)
    {
        if(num==0){printf("0\n");continue;}
        GetResult();
        int k=20;
        while(result[k]==\'0\')k--;
        for(;k>=0;k--)putchar(result[k]);
        putchar(\'\n\');
    }
    return 0;
}