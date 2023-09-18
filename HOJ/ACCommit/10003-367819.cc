#include<cstdio>
#include<cstring>
const int MAX = 10001;
int f[MAX];
__int64 down[MAX],up[MAX],min;
int main()
{
int t,m,a,b;
scanf("%ld",&t);
while(t--)
{
   memset(f,0,sizeof(f));
   memset(down,0,sizeof(down));
   memset(up,0,sizeof(up));
   scanf("%ld%ld%ld",&m,&a,&b);
   for(int i=1; i<=m; i++)
    scanf("%ld",&f[i]);
   __int64 p=f[1],q=f[m], sum = 0;
   int besti = -1;
   down[1] = 0;
   for(int i=2; i<=m; i++)
   {
    down[i] = down[i-1]+b*p+sum;
    sum += p;
    p += f[i];
   }
   sum=0;up[m]=0;
   for(int i=m-1; i>=1; i--)
   {
    up[i] = up[i+1]+a*q+sum;
    sum += q;
    q += f[i];
   }
   min=999999999999999LL;
   for(int i=1; i<=m; i++)
   {
    if(min>(down[i]+up[i]) )
    {
     min=down[i]+up[i];
     besti=i;
    }
   }
   printf("%ld\n",besti);
}
return 0;
}