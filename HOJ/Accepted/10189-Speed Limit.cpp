// 10189-Speed Limit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
int num,a,b,all,re;
int main()
{
	while(scanf("%ld",&num))
	{
		if(num==-1)return 0;
		re=all=0;
		while(num--)
		{
			scanf("%ld%ld",&a,&b);
			re+=(a*(b-all));
			all=b;
		}
		printf("%ld miles\n",re);
	}
}