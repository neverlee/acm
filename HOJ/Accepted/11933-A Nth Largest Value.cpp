// 11933-A Nth Largest Value.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
int num[1001];
int main()
{
	int ncase,np,kn;
	scanf("%d",&ncase);
	for(int text=0;text<ncase;text++)
	{
		scanf("%d",&np);
		for(int i=0;i<=1000;i++)num[i]=0;
		for(int i=0;i<10;i++){scanf("%d",&kn);num[kn]++;}
		int m,n;
		for(m=1000,n=0;m>=0&&n<3;m--)
			n+=num[m];
		printf("%d %d\n",np,m+1);
	}
	return 0;
}