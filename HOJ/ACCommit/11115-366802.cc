#include <cstdio>
long long result[10000]={1,2};
void SetResult()
{
    for(long long i=2,k=2;i<10000;i++,k+=2)
        result[i]=result[i-1]+k+k+1;
}
int main()
{
    int ncase,num;scanf("%ld",&ncase);
    SetResult();
    for(int text=0;text<ncase;text++)
    {scanf("%ld",&num);printf("%I64d\n",result[num]);}
    return 0;
}