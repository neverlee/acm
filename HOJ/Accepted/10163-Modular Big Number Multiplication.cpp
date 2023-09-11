// 10163-Modular Big Number Multiplication.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include<cstdio>
long long md,num,k,res;
int main()
{
	while(scanf("%I64d%I64d",&md,&num)!=EOF)
	{
		res=1LL;
		while(num--)
		{
			scanf("%I64d",&k);
			res=(res*k)%md;
		}
		printf("%I64d\n",res);
	}
	return 0;
}