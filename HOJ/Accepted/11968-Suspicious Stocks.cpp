// 11968-Suspicious Stocks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
long day,money,price[70000],min[70000],max[70000],m,big;

void GetResult()
{
	m=80000;
	int i;
	for(i=0;i<day;i++)
	{
		if(price[i]<m)m=price[i];
		min[i]=m;
	}
	m=0;
	for(i=day-1;i>=0;i--)
	{
		if(price[i]>m)m=price[i];
		max[i]=m;
	}
	big=0;
	for(i=0;i<day-1;i++)
		if(min[i]<max[i+1]&&(money/min[i]*max[i+1]+money%min[i])>big)
			big=money/min[i]*max[i+1]+money%min[i];
	if((big-=money)<0)big=0;
	printf("%ld\n",big);
}
int main()
{
	while(scanf("%ld",&day))
	{
		if(!day)return 0;
		scanf("%ld",&money);
		for(int i=0;i<day;i++)
			scanf("%ld",&price[i]);
		GetResult();
	}
}