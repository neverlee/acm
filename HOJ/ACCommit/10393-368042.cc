#include<cstdio>

char s1[210],s2[210];
int dps[210][210],i,j,mx;

int main()
{
    int ncase;scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%ld%ld",&i,&j);
        mx=0;getchar();gets(s1+1);gets(s2+1);
        for(i=0;s1[i];i++)dps[i][0]=0;
        for(j=0;s2[j];j++)dps[0][j]=0;
        for(i=1;s1[i];i++)
            for(j=1;s2[j];j++)
            if(s1[i]==s2[j])
                {dps[i][j]=dps[i-1][j-1]+1;if(dps[i][j]>mx)mx=dps[i][j];}
            else dps[i][j]=0;
        printf("%ld\n",mx);
    }
    return 0;
}