// 10052-Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<cstdio>
#include<cmath>
int main()
{
	int a,k;
	while(scanf("%ld",&a)!=EOF)
	{
	k=(int)sqrt(2.0*a);
	k-=1;if(k<0)k=0;
	for(int i=k;;i++)
	{
		k=i*(i+1)/2;
		if(k>a&&(k-a)%2==0)
		{printf("%ld\n",i);break;}
	}}
	return 0;
}

