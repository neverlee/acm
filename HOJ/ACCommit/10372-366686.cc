#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE=10001;
int num,frult[SIZE];

int main()
{
    int power,tn,k;
    while(scanf("%ld",&num)!=EOF)
    {
        power=0;
        for(int i=0;i<num;i++)
            scanf("%ld",&frult[i]);
        sort(frult,frult+num);
        if(num==1){printf("0\n");continue;}
        for(int i=0;i<num-1;i++)
        {
            tn=frult[i]+frult[i+1];
            power+=tn;
            for(k=i+2;tn>frult[k]&&k<num;)
            {frult[k-1]=frult[k];k++;}
            frult[k-1]=tn;
        }
        printf("%ld\n",power);
    }
    return 0;
}