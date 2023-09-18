#include <cstdio>
int size,size2,most;
short have[102][203];

void Init()
{
    size2=2*size;
    for(int i=0;i<=size;i++)
        for(int j=0;j<=size2;j++)
            have[i][j]=0;
    getchar();
    char trg[101][202];
    for(int i=0;i<size;i++)
        gets(trg[i]);
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size2-i;j++)
            if(trg[i][j]==\'O\')have[i][j+1]=have[i][j]+1;
    }
}

int GetBig(int x,int y,int dir)
{
    int ihave=0;
    for(int i=0;have[x+i*dir][y+i]>=1+2*i&&x+i*dir>=0&&x+i*dir<size;i++)
        ihave++;
    return ihave;
}

void Search()
{
    most=0;
    int k;
    //\xd5\xfd\xb7\xb4\xc1\xbd\xb8\xf6\xb7\xbd\xcf\xf2\xb8\xf7\xb2\xe9\xd2\xbb\xb4\xce
    for(int i=0;i<size-most+1;i++)
        for(int j=i+2;j<=size2-i-1;j+=2)
        {
            k=GetBig(i,j,1);
            if(k>most)most=k;
        }
    for(int i=size-1;i>=most-1;i--)
        for(int j=i+1;j<=size2-i-1;j+=2)
        {
            k=GetBig(i,j,-1);
            if(k>most)most=k;
        }
    printf("%ld\n",most*most);
}

int main()
{
    while(scanf("%ld",&size)!=EOF)
    {
        if(!size)return 0;
        Init();
        Search();
    }
}