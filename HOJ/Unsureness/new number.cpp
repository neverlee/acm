# include<iostream>
# include<cmath>
#define __int64_t __int64
using namespace std;
__int64_t P;
int len;
bool a[30000];
int p[10000];
void prime()
{
	int i,j,k;
	for(i=0;i<150;i++)
		for(k=2*i+3,j=k*i+k+i;j<30000;j+=k)
			a[j]=1;
	p[0]=2;len=1;
	for(i=0;i<30000;i++)
		if(!a[i])
			p[len++]=(i<<1)+3;
} 
__int64_t Pmod(__int64_t x,__int64_t n)
{
	__int64_t ans=1;
	bool f=0;
	while((!f)&&n)
	{
		if(n&1)ans*=x;
		if(ans>P)
		{
			ans%=P;
			f=1;break;
		}
		x*=x;
		n>>=1;
	}
	while(n)
	{
		if(n&1)ans=(ans*(x%P))%P;
		x=((x%P)*(x%P))%P;
		n>>=1;
	}
	if(f)ans+=P;
	return ans;
}
__int64_t phi(int n)
{
	__int64_t d,ans;
	int i;
	d=(__int64_t)sqrt(n);
	ans=n;
	for(i=0;i<len&&p[i]<=d;i++)
		if(n%p[i]==0)
		{
			ans=ans/p[i]*(p[i]-1);
			while(!(n%p[i]))
			{
				n/=p[i];
			}
		}
	if(n!=1)
		ans=ans/n*(n-1);
	return ans;
}
__int64_t mod(__int64_t x,__int64_t n,__int64_t p)
{
	__int64_t ans=1;
	while(n)
	{
		if(n&1)ans=(ans*(x%p))%p;
		x=((x%p)*(x%p))%p;
		n>>=1;
	}
	return ans;
} 
int main()
{
	prime();
	__int64_t cas,i;
	__int64_t n,b,m,a[120];
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%I64d%I64d%I64d",&b,&n,&m);
		cin >> b >> n >> m;
		for(i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		//cin >> a[i];
		__int64_t ans=a[n];
		P=phi(m);
		for(i=n-1;i>=1;i--)
		{
			ans=Pmod(a[i],ans);
		}
		ans=mod(b,ans,m);
		printf("%I64d\n",ans);
		//cout << ans << '\n';
	}
	//system("pause");
	return 0;
}
