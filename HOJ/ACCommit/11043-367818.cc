#include<cstdio>
int num,big,ele[100001],len;

void Init()
{
    scanf("%ld%ld",&num,&big);
    ele[0]=0;
    for(int i=1;i<=num;i++)
    {
        scanf("%ld",&ele[i]);
        ele[i]+=ele[i-1];
    }
}

void GetResult()
{
    int e=1;len;
    while(ele[e]<big&&e<=num)++e;
    if(e>num){printf("0\n");return;}
    len=e;
    for(;e<=num;)
    {
        if(len==1){printf("1\n");return;}
        if(ele[e]-ele[e-len+1]>=big)
        {len--;continue;}
        e++;
    }
    printf("%ld\n",len);
}

int main()
{
    int ncase;
    scanf("%ld",&ncase);
    while(ncase--)
    {
        Init();
        GetResult();
    }
    return 0;
}