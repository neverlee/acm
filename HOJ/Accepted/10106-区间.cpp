// 10106-区间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
int arrive[1000001];
int main()
{
	for(int i=0;i<=1000000;i++)
		arrive[i]=0;
	int numAera;
	scanf("%ld",&numAera);
	int a,b;
	for(int i=0;i<numAera;i++)
	{
		scanf("%ld%ld",&a,&b);
		arrive[a]=arrive[a]>b?arrive[a]:b;
	}
	int m,n;
	for(m=0;m<=1000000;m++)
	{
		if(arrive[m])
		{
			printf("%ld ",m);
			for(n=m;n<=arrive[m];n++)
			{
				if(arrive[n]>arrive[m])
					arrive[m]=arrive[n];
			}
			printf("%ld\n",n-1);
			m=n-1;
		}
	}
	return 0;
}