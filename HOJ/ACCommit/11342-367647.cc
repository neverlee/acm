#include<cstdio>
int prime[10]={2,3,5,7,11,13,17,19};
int have[10];
char str[30];

void SetHave(int k)
{
    int p,all;
    for(int i=0;str[i];i++)
    {
        if(str[i]==\'N\')continue;
        p=i+1;all=0;
        while(p%prime[k]==0)
        {++all;p/=prime[k];    }
        if(all>have[k])have[k]=all;
    }
}

int main()
{
    int big;
    while(gets(str))
    {
        if(str[0]==\'*\')return 0;
        for(int i=0;i<8;i++)
        {have[i]=0;SetHave(i);}
        big=1;
        for(int i=0;i<8;i++)
            for(int j=0;j<have[i];j++)big*=prime[i];
        bool isHave=1;
        for(int i=0;str[i];i++)
            if(str[i]==\'N\')
                if(big%(i+1)==0)
                {isHave=0;break;}
        if(isHave)printf("%ld\n",big);
        else printf("-1\n");
    }
}