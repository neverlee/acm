// 10721-Combinations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int main()
{
	int c,k,tk;unsigned long long re;
	while(scanf("%ld%ld",&c,&k))
	{
		tk=k;
		k=k<c-k?k:c-k;
		if(c==0)return 0;
		if(k==0)
		{
			printf("%ld things taken %ld at a time is 1 exactly.\n",c,tk);
			continue;
		}
		re=(unsigned long long)c;
		for(unsigned long long i=1;i<k;i++)
			re=re*(c-i)/(i+1);
		printf("%ld things taken %ld at a time is %I64u exactly.\n",c,tk,re);
	}
}

