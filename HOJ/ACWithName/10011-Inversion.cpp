// 10011-Inversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "stdio.h"
#define N 50005
int n,m,add,inv,extent,i,a[N],j,k,t;
int main()
{
    while(scanf("%d%d",&n,&m),(n!=-1&&m!=-1))
    {
		add=0;
		for(extent=1;extent<=n;extent++)
		{
			add=add+extent-1; 
			if (add>=m)break;
		}
		inv=add-(extent-1);
		m=m-inv;
		for(i=1;i<=n-extent+1;i++)
			a[i]=i;
		for(i=n-extent+2;i<=n;i++)
			if(i==n-extent+2)a[i]=n;else a[i]=a[i-1]-1;
		i=n-extent+1;
		j=n;
		while (m!=0)
		{
			t=a[i];a[i]=a[j];a[j]=t;m--;
			j--;if(j==i){j=n;i--;}
		}
		for(i=1;i<=n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
    }
	return 0;
}