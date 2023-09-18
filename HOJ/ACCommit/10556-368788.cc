#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Prime
{
public:
    vector<int> Value;
    Prime(int max,int num);
    bool IsPrime(int num);
    int GetPrime(int n);
    void PrintAll();
};
bool Prime::IsPrime(int num)
{
    int limit=(int)sqrt((double)num);
    for(int i=1;Value[i]<=limit;i++)
        if(!(num%Value[i])){return 0;}
    return 1;
}

Prime::Prime(int max, int num)
{
    Value.reserve(num);
    Value.push_back(1);Value.push_back(2);Value.push_back(3);Value.push_back(5);
    for(int i=7;i<=max;i+=2)
        if(IsPrime(i))
            Value.push_back(i);
}
int Prime::GetPrime(int n)
{return Value[n];}

void Prime::PrintAll()
{
    printf("%ld\n",Value.size());
    for(int i=0;i<Value.size();i++)
        printf("%ld ",Value[i]);
}
int num,cut,start,tend,ipt;
vector<int>::iterator iter;
int main()
{
    Prime p(1010,180);
    while(scanf("%ld%ld",&num,&cut)!=EOF)
    {
        iter=upper_bound(p.Value.begin(),p.Value.end(),num);
        ipt=iter-p.Value.begin();
        if(ipt%2)
        {
            start=ipt/2-cut+1;
            if(start<0)start=0;
        }
        else
        {
            start=ipt/2-cut;
            if(start<0)start=0;
        }
        tend=ipt/2+cut-1;
        if(tend>=ipt)tend=ipt-1;
        printf("%ld %ld:",num,cut);
        for(;start<=tend;start++)
            printf(" %ld",p.GetPrime(start));
        printf("\n\n");
    }
    return 0;
}