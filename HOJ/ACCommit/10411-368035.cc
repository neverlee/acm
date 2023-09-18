#include<cstdio>

char s1[210],s2[210];
int dps[210][210],i,j;
int Min(int a,int b,int c)
{
    if(a>b)a=b;
    if(a>c)a=c;
    return a;
}
int main()
{
    gets(s1+1);
    gets(s2+1);
    for(i=0;s1[i];i++)dps[i][0]=i;
    for(j=0;s2[j];j++)dps[0][j]=j;
    for(i=1;s1[i];i++)
        for(j=1;s2[j];j++)
            if(s1[i]==s2[j])dps[i][j]=dps[i-1][j-1];
            else
                dps[i][j]=Min(dps[i][j-1],dps[i-1][j],dps[i-1][j-1])+1;
    printf("%ld",dps[i-1][j-1]);
}