#include<cstdio>

struct{bool ishave;short x,y;}cubes[1000001];
int k;
int main()
{
    for(int i=-577;i<=578;i++)
        for(int j=i;j<=578;j++)
        {
            k=i*i*i+j*j*j;
            if(k>0&&k<=1000000)
                if((cubes[k].ishave&&cubes[k].x>i)||!cubes[k].ishave)
                    {cubes[k].ishave=1;cubes[k].x=i;cubes[k].y=j;}
        }
    while(scanf("%ld",&k))
    {
        if(!k)return 0;
        if(cubes[k].ishave)
            printf("%ld %ld\n",cubes[k].x,cubes[k].y);
        else
            printf("impossible\n");
    }
}