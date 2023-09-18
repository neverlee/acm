#include<cstdio>
#include<algorithm>
using namespace std;
int relate[501];
int main()
{
    int ncase,num,min,total;scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%ld",&num);
        for(int i=0;i<num;i++)scanf("%ld",&relate[i]);
        sort(relate,relate+num);
        total=0;
        for(int i=1;i<num;i++)total+=relate[i]-relate[0];
        min=total;
        for(int i=1;i<num;i++)
        {
            total+=(2*i-num)*(relate[i]-relate[i-1]);
            if(total<min)min=total;
        }
        printf("%ld\n",min);
    }
    return 0;
}