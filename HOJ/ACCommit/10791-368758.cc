#include<cstdio>
long long num;
int temp,ele[2000001]={0,1,2,3,4,5,6,7,8,9,10,11};

long long GetMax(long long n)
{
    if(n<2000001LL)return ele[n];
    long long k=GetMax(n/2)+GetMax(n/3)+GetMax(n/4);
    return n>k?n:k;
}
int main()
{
    for(int i=12;i<2000001;i++)
    {
        temp=ele[i/2]+ele[i/3]+ele[i/4];
        ele[i]=i>temp?i:temp;
    }
    while(scanf("%I64d",&num)!=EOF)
        printf("%I64d\n",GetMax(num));
    return 0;
}