// 10676-Triangular Sums.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
long long tp[301],result[301];

void SetResult()
{
	tp[1]=result[1]=3;
	for(long long i=2;i<=300;i++)
	{
		tp[i]=i*(i+1)*(i+2)/2;
		result[i]=tp[i]+result[i-1];
	}
}
int main()
{
	int ncase,num;
	scanf("%ld",&ncase);
	SetResult();
	for(int text=1;text<=ncase;text++)
	{
		scanf("%ld",&num);
		printf("%ld %ld %I64d\n",text,num,result[num]);
	}
	return 0;
}