#include<cstdio>
#include<algorithm>
using namespace std;
short ele[100010];
int en,an;

int main()
{
    scanf("%ld",&en);
    for(int i=0;i<en;i++)scanf("%ld",&ele[i]);
    sort(ele,ele+en);
    getchar();
    scanf("###");
    scanf("%ld",&an);
    while(an--)
    {
        scanf("%ld",&en);
        printf("%d\n",ele[en-1]);
    }
    return 0;
}