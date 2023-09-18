// 10450-Hamming Distance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
unsigned long long a,b,k;

int main()
{
	int total;
	while(scanf("%I64u%I64u",&a,&b))
	{
		if(a==0&&b==0)return 0;
		total=0;
		k=1;
		for(int i=0;i<63;i++)
		{
			if((a&k)!=(b&k))total++;
			k*=2;
		}
		if((a&k)!=(b&k))total++;
		printf("%ld\n",total);
	}
}