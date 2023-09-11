// 10477-Factorial.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>

int main()
{
	int ncase,num,have;
	scanf("%ld",&ncase);
	while(ncase--)
	{
		scanf("%ld",&num);
		have=0;
		for(int k=5;k<=num;k*=5)
			have+=(num/k);
		printf("%ld\n",have);
	}
	return 0;
}