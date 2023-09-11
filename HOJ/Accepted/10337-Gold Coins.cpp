// 10337-Gold Coins.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cmath>
int main()
{
	long num,kn;long long result;
	while(scanf("%I64d",&num))
	{
		if(num==0)return 0;
		kn=(long)sqrt((double)(2*num));kn--;
		while(kn*(kn+1)<=2*num)kn++;
		result=kn*(kn+1)*(2*kn+1)/6-kn*(kn*(kn+1)/2-num);
		printf("%ld %I64d\n",num,result);
	}
}