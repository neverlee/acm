#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
const int MSize = 16100000;
const int Size = 4100;

int lineA[MSize],lineB[MSize],num,mnum;
int tnum[Size][4];
void InitLine()
{
    int i,j,m=0;
    scanf("%ld",&num);
    mnum=num*num;
    for(i=0;i<num;i++)
        for(j=0;j<4;j++)
            scanf("%ld",&tnum[i][j]);
    for(i=0;i<num;i++)
        for(j=0;j<num;j++)
        {
            lineA[m]=tnum[i][0]+tnum[j][1];
            lineB[m++]=tnum[i][2]+tnum[j][3];
        }
    sort(lineA,lineA+m);
    sort(lineB,lineB+m,greater<int>());
    lineA[m]=lineA[m-1]-1;
    lineB[m+1]=lineB[m]=lineB[m-1]+1;
}

void Check()
{
    int x,y,have=1;
    long long total=0;
    for(x=0,y=0;x<mnum&&y<mnum;x++)
    {
        while(lineA[x]+lineB[y]>0&&y<mnum){++y;have=1;}
        if(lineA[x]+lineB[y]==0)
        {
            while(lineA[x]+lineB[y+1]==0){++y;++have;}
            total+=have;
        }
        else
            have=1;
    }
    printf("%I64d",total);
}

int main()
{
    InitLine();
    Check();
    return 0;
}