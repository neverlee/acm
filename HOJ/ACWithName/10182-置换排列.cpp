// 10182-置换排列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
int num[101];

void Check()
{
	for(int i=1;i<=num[0];i++)
		if(num[num[i]]!=i)
		{printf("no\n");return;}
	printf("yes\n");
}
int main()
{
	int ncase;
	scanf("%ld",&ncase);
	while(ncase--)
	{
		scanf("%ld",&num[0]);
		for(int i=1;i<=num[0];i++)
			scanf("%ld",&num[i]);
		Check();
	}
	return 0;
}