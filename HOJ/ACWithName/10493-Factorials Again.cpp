// 10493-Factorials Again.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<cstdio>
const long long Mod=1000000000L;
long long red[10001]={1,1,2};long num,p;
int main()
{
	for(int i=3;i<10001;i++)
	{
		p=i;while(p%10==0)p/=10;
		red[i]=(red[i-1]%Mod)*p;
		while(red[i]%10==0)red[i]/=10;
	}
	while(scanf("%ld",&num))
	{
		if(!num)return 0;
		printf("%I64d\n",red[num]%10);
	}
}

