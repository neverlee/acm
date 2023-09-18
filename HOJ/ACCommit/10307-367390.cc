#include<cstdio>
#include<algorithm>
int num,ele[1010];
int main()
{
    int ncase;
    scanf("%ld",&ncase);
    for(int text=1;text<=ncase;text++)
    {
        scanf("%ld",&num);
        for(int i=0;i<num;i++)
            scanf("%ld",&ele[i]);
        for(int i=num-1;i>0;i--)
            ele[i]-=ele[i-1];
        std::sort(ele,ele+num);
        printf("Case %ld:\n",text);
        printf("%ld",ele[0]);
        for(int i=1;i<num;i++)
            printf(" %ld",ele[i]);
        printf("\n");
    }
    return 0;
}