// 10406-密码破译.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
int main()
{
	long n,total,num[5000];
	scanf("%ld%ld",&n,&total);
	for(int i=0;i<n;i++)scanf("%ld",&num[i]);
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(num[i]+num[j]==total)
			{
				printf("%ld\n%ld\n",i+1,j+1);
				return 0;
			}
	printf("0\n");return 0;
}