// 10275-Reduced ID Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
int ele[400],num;
bool isHave[100000];

bool IsCan(int limit)
{
	int k;
	for(int j=0;j<limit;j++)isHave[j]=0;
	for(int j=0;j<num;j++)
	{
		k=ele[j]%limit;
		if(isHave[k])return 0;
		else isHave[k]=1;
	}
	return 1;
}

int main()
{
	int ncase;
	scanf("%ld",&ncase);
	while(ncase--)
	{
		scanf("%ld",&num);
		for(int i=0;i<num;i++)
			scanf("%ld",&ele[i]);
		for(int i=num;;i++)
			if(IsCan(i))
			{printf("%ld",i);if(ncase)putchar('\n');break;}
	}
	return 0;
}